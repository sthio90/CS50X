import csv
import datetime
from datetime import datetime
import pytz
import requests
import subprocess
import urllib
import uuid

from flask import redirect, render_template, session
from functools import wraps


def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/0.12/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


def lookup(symbol):
    """Look up quote for symbol."""

    # Prepare API request
    symbol = symbol.upper()
    end = datetime.datetime.now(pytz.timezone("US/Eastern"))
    start = end - datetime.timedelta(days=7)

    # Yahoo Finance API
    url = (
        f"https://query1.finance.yahoo.com/v7/finance/download/{urllib.parse.quote_plus(symbol)}"
        f"?period1={int(start.timestamp())}"
        f"&period2={int(end.timestamp())}"
        f"&interval=1d&events=history&includeAdjustedClose=true"
    )

    # Query API
    try:
        response = requests.get(url, cookies={"session": str(uuid.uuid4())}, headers={"User-Agent": "python-requests", "Accept": "*/*"})
        response.raise_for_status()

        # CSV header: Date,Open,High,Low,Close,Adj Close,Volume
        quotes = list(csv.DictReader(response.content.decode("utf-8").splitlines()))
        quotes.reverse()
        price = round(float(quotes[0]["Adj Close"]), 2)
        return {
            "name": symbol,
            "price": price,
            "symbol": symbol
        }
    except (requests.RequestException, ValueError, KeyError, IndexError):
        return None


def usd(value):
    """Format value as USD."""
    return f"${value:,.2f}"


def get_crypto_data(api_key, symbol):
    url = "https://pro-api.coinmarketcap.com/v1/cryptocurrency/quotes/latest"
    headers = {
        'X-CMC_PRO_API_KEY': api_key,
        'Accepts': 'application/json'
    }
    parameters = {
        'symbol': symbol,
        'convert': 'USD'
    }
    response = requests.get(url, headers=headers, params=parameters)
    data = response.json()
    return data


def get_historical_data(api_key, symbol, start, end):
    url = f"https://pro-api.coinmarketcap.com/v1/cryptocurrency/quotes/historical"
    headers = {
        'X-CMC_PRO_API_KEY': api_key,
        'Accepts': 'application/json'
    }
    parameters = {
        'symbol': symbol,
        'time_start': start,
        'time_end': end
    }
    response = requests.get(url, headers=headers, params=parameters)
    data = response.json()
    return data

def process_historical_data(historical_data):
    date_labels = []
    price_data = []

    # Loop through each entry in the 'quotes' list
    for entry in historical_data.get('data', {}).get('quotes', []):
        # Extract the timestamp and convert it to a more readable format
        timestamp = entry.get('timestamp')
        if timestamp:
            date = datetime.fromisoformat(timestamp).strftime('%Y-%m-%d %H:%M:%S')
            date_labels.append(date)

        # Extract the price
        price = entry.get('quote', {}).get('USD', {}).get('price')
        if price is not None:
            price_data.append(price)

    return date_labels, price_data
