import sqlite3

# Connect to the new database file
conn = sqlite3.connect('project.db')
c = conn.cursor()

# Create the 'users' table
c.execute('''
    CREATE TABLE users (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        username TEXT NOT NULL,
        hash TEXT NOT NULL,
        cash NUMERIC NOT NULL DEFAULT 10000.00
    );
''')

# Create a unique index on 'username' in the 'users' table
c.execute('''
    CREATE UNIQUE INDEX username ON users (username);
''')

# Create the 'user_cryptos' table
c.execute('''
    CREATE TABLE user_cryptos (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER NOT NULL,
        symbol TEXT NOT NULL,
        FOREIGN KEY (user_id) REFERENCES users(id)
);

# Commit the changes and close the connection
conn.commit()
conn.close()

print("Database 'project.db' created with the required schema.")
