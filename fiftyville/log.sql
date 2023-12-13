-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking up crime scene reports for the 28th of July 2021 at Humphrey Street
SELECT * FROM crime_scene_reports
    WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- | 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- | 297 | 2021 | 7     | 28  | Humphrey Street | Littering took place at 16:36. No known witnesses.

-- Identify people who were near Humphrey Street on July 28, 2021
SELECT * FROM bakery_security_logs WHERE date = '2021-07-28';
