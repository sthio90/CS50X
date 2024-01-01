# Crypto Checker
#### Video Demo:  <https://www.youtube.com/watch?v=PwrMpj6NieE>
#### Description:
Crypto Checker is a web application designed to provide users with the ability to track cryptocurrency prices in real-time. It leverages the power of the CoinMarketCap API to fetch the latest data on various cryptocurrencies, allowing users to make informed decisions based on current market trends.

The application is built using Flask, a micro web framework written in Python. It integrates with a SQLite database to store user data and cryptocurrency preferences, ensuring a personalized experience for each user.

## Key Features:

Real-time Crypto Prices: Users can search for and view the current price of any cryptocurrency supported by the CoinMarketCap API.
User Accounts: The application supports user account creation, login, and logout functionalities. Each user's cryptocurrency preferences and settings are stored securely.
Custom Crypto List: Users can add cryptocurrencies to their watchlist, making it easier to monitor specific tokens of interest.

## Technical Overview:

The project consists of several key files and components:

app.py: This is the main file of the Flask application. It contains routes to handle requests for different pages of the application, including the homepage, login, registration, cryptocurrency search, and user-specific crypto lists.

helpers.py: This file includes helper functions used throughout the application. It contains functions for error handling, user session management, API data fetching, and data processing for historical cryptocurrency prices.

templates: This directory contains HTML files for each webpage, utilizing Jinja templating to dynamically generate content based on user data and API responses.

static: This directory includes CSS files and other static assets used to style the web pages.

project.db: SQLite database file storing user account information and user-specific crypto lists.

## Design Considerations:
* During the development of Crypto Checker, several key design decisions were made:

User Experience: Focus was placed on creating an intuitive and easy-to-navigate interface, allowing users to quickly find and track cryptocurrencies.
Security: User passwords are hashed for security, and user session management is handled carefully to prevent unauthorized access.
API Utilization: The application makes efficient use of the CoinMarketCap API, fetching data as needed while being mindful of rate limits and access restrictions.
Future Enhancements:
While Crypto Checker currently meets its core objectives, future enhancements are planned:

Extended Historical Data: Subject to API access, the application will offer more extensive historical data analysis and trend visualization.
Portfolio Management: A feature to allow users to track their cryptocurrency holdings and view portfolio performance over time.
Mobile Responsiveness: Improving the application's responsiveness and user experience on mobile devices.
Conclusion:
Crypto Checker represents a practical and educational foray into the world of web application development, API integration, and real-time data processing. It exemplifies the power of Python and Flask in creating functional web applications and provides a platform for continued learning and development in the field of cryptocurrency and web development.*
