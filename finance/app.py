import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Fetch users stock holdings
    holdings = db.execute("SELECT symbol, SUM(CASE WHEN type = 'buy' THEN shares ELSE -shares END) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0", session["user_id"])

    # Prepare list of held stock data
    stocks = []
    total_holdings_value = 0

    # Fetch current prices and calculate total value for each
    for holding in holdings:
        stock_data = lookup(holding["symbol"])
        if stock_data:
            holding_value = holding["total_shares"] * stock_data["price"]
            total_holdings_value += holding_value
            stocks.append({
                "symbol": holding["symbol"],
                "name": stock_data["name"],
                "shares": holding["total_shares"],
                "price": usd(stock_data["price"]),
                "total": usd(holding_value)
            })

    # Fetch users current cash balance
    user_balance = db.execute("SELECT cash FROM users WHERE id = ?;", session["user_id"])
    cash = user_balance[0]["cash"]
    grand_total = total_holdings_value + cash

    # Render index page with stock and cash data
    return render_template("index.html", stocks=stocks, cash=usd(cash), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = toupper(request.form.get("symbol"))
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("Invalid number of shares", 400)

        if shares < 1:
            return apology("Invalid number of shares", 400)

        stock = lookup(symbol)
        user = db.execute("SELECT cash FROM users WHERE id = ?;", session["user_id"])
        if not user:
            return apology("User not found", 400)

        cash = user[0]["cash"]
        total_cost = shares * stock["price"]

        # check input is blank or symbol does not exist
        if not symbol or stock is None:
            return apology("Invalid symbol", 400)


        # Update user's cash
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_cost, session["user_id"])

        # Record the purchase in transactions table
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, type) VALUES (?, ?, ?, ?, 'buy')",
                   session["user_id"], symbol, shares, stock["price"])

        return redirect ("/")

    return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

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
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
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
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        # Ensure symbol submitted
        if not symbol:
            return apology("must provide symbol", 400)

        stock = lookup(symbol)

        if stock is None:
            return apology("symbol not found", 400)

        return render_template("quoted.html", name=stock["name"], symbol=stock["symbol"], price=stock["price"])

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
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
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?);", username, hash_password)

        return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
