-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking up crime scene reports for the 28th of July 2021 at Humphrey Street
SELECT * FROM crime_scene_reports
    WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
