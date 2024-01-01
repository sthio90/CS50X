import os
from config import COINMARKETCAP_API_KEY
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, usd, get_crypto_data

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///project.db")


@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    return render_template("welcome.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        # Ensure username submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password submitted
        elif not password:
            return apology("must provide password", 400)

        # Ensure confirmation submitted and matches password
        elif not confirmation or password != confirmation:
            return apology("passwords do not match", 400)

        # Search database users and if username is already in database then return 'username already in use'
        user_check = db.execute("SELECT * FROM users WHERE username = ?;", username)
        if user_check:
            return apology("Username already in use", 400)

        # If above criterias not met then create new row in user table with new user information
        hash_password = generate_password_hash(password)
        db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?);", username, hash_password
        )

        flash(f"Successfully registered!", "success")
        return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/crypto", methods=["GET", "POST"])
@login_required
def crypto():
    api_key = COINMARKETCAP_API_KEY
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        # Ensure symbol submitted
        if not symbol:
            return apology("must provide symbol", 400)

        crypto_data = get_crypto_data(api_key, symbol)

        if crypto_data is None or 'data' not in crypto_data or symbol not in crypto_data['data']:
            return apology(f"Data for symbol {symbol} not found", 400)

        # Error handling and data extraction
        try:
            crypto_price = crypto_data['data'][symbol]['quote']['USD']['price']
            print(f"The current price of {symbol} is: ${crypto_price:.2f}")
        except (KeyError, TypeError):
            crypto_price = "Unavailable"
            print(f"Error: Unable to retrieve the price for {symbol}")

        return render_template("crypto.html", symbol=symbol, crypto_price=usd(crypto_price))

    # Handle GET request
    return render_template("crypto.html", symbol=None, crypto_price=None)


@app.route("/add_crypto", methods=["GET", "POST"])
@login_required
def add_crypto():
    api_key = COINMARKETCAP_API_KEY
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()

        if not symbol:
            return apology("You must provide a symbol", 400)

        # Verify if the symbol is valid by making an API call
        crypto_data = get_crypto_data(api_key, symbol)
        if not crypto_data or 'data' not in crypto_data or symbol not in crypto_data['data']:
            return apology(f"Symbol {symbol} is not a valid cryptocurrency", 400)

        # Add the symbol to the database
        db.execute("INSERT INTO user_cryptos (user_id, symbol) VALUES (?, ?)",
                   session["user_id"], symbol)

        return redirect("/crypto_list")
    else:
        return render_template("add_crypto.html")


@app.route("/crypto_list")
@login_required
def crypto_list():
    api_key = COINMARKETCAP_API_KEY
    # Query the database for the user's cryptocurrencies
    user_cryptos = db.execute("SELECT symbol FROM user_cryptos WHERE user_id = ?",
                              session["user_id"])

    # Fetch real-time data for each token
    crypto_data = []
    for crypto in user_cryptos:
        symbol = crypto['symbol']
        api_data = get_crypto_data(api_key, symbol)
        if api_data and 'data' in api_data and symbol in api_data['data']:
            price = api_data['data'][symbol]['quote']['USD']['price']
            crypto_data.append({
                'symbol': symbol,
                'price': usd(price)
            })

    return render_template("crypto_list.html", cryptos=crypto_data)


@app.route("/delete_crypto", methods=["POST"])
@login_required
def delete_crypto():
    symbol = request.form.get("symbol")

    if not symbol:
        return apology("Missing symbol", 400)

    # Delete the token from the database
    db.execute("DELETE FROM user_cryptos WHERE user_id = ? AND symbol = ?",
               session["user_id"], symbol)

    return redirect("/crypto_list")
