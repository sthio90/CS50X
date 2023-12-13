-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking up crime scene reports for the 28th of July 2021 at Humphrey Street
SELECT * FROM crime_scene_reports
    WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- | 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- | 297 | 2021 | 7     | 28  | Humphrey Street | Littering took place at 16:36. No known witnesses.

-- Find all activities at the bakery on July 28, 2021
SELECT * FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;

-- | 259 | 2021 | 7     | 28  | 10   | 14     | entrance | 13FNH73
-- | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95

