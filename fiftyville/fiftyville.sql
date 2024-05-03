--Keep a log of any SQL queries you execute as you solve the mystery.
--Find crime scene description

SELECT "description"
FROM "crime_scene_reports"
WHERE "year" = 2021
AND "month" = 7 AND "day" = 28
AND "street" = 'Humphrey Street';

--Coletar informações do depoimento das tres testemunhas, no qual elas mencionam "bakery"
SELECT "name", "transcript"
FROM "interviews"
WHERE "year" = 2021 AND "month" = 7 AND "day" = 28 AND "transcript" LIKE "%bakery%";

-- Após ler as informações que a Ruth deu no depoimento, analisar o bakery_security_logs table para encontrar as informações sobre a license_plate
-- encontrar os supeitos pela license_plate
-- encontrar as placas dos suspeitos
SELECT "name"
FROM "people"
WHERE "license_plate" IN (
    SELECT "license_plate"
    FROM "bakery_security_logs"
    WHERE "year" = 2021 AND "month" = 7 AND "day" = 28 AND "hour" = 10 AND "minute" BETWEEN 15 AND 25 AND "activity" = 'exit'
    );

-- FIRST SUSPECTS: Vanessa / Barry / Iman / Sofia / Luca / Diana / Kelsey / Bruce

-- Eugene said that she was walking by the ATM on Leggett Street and she saw the thief there withdrawing some money
-- Na tabela ATM-transactions pretendo descobrir o account_number do suspeito
-- Join à tabela bank-accounts para descobrir o person_id e o telefone

SELECT "phone_number","name"
    FROM "people"
    WHERE "id" IN (
        SELECT "person_id"
        FROM "bank_accounts"
        WHERE "account_number" IN (
            SELECT "account_number"
            FROM "atm_transactions"
            WHERE "year" = 2021 AND "month" = 7 AND "day" = 28 AND "atm_location" = 'Leggett Street' AND "transaction_type" = 'withdraw'
        )
);

-- SUSPECTS: Iman / Luca / Diana / Bruce

-- preciso descobrir quem dos suspeitos acima ficou menos de 60 segundos com alguèm no telefone para
--isso terei que usar a mesma query para encontrar o numeros e linkar
-- à tabela caller de phone_calls

SELECT "name"
FROM "people"
JOIN "phone_calls"
ON "phone_calls"."caller" = "people"."phone_number"
WHERE "year" = 2021 AND "month" = 7 AND "day" = 28 AND "duration" < 60;

-- SUSPECTS: Bruce / Diana

-- Raymond said that he heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- FIND OUT THE EARLIEST FLIGHT OUT OF FIFTYVILLE TOMORROW
SELECT "name"
FROM "people"
JOIN "passengers"
ON "passengers"."passport_number" = "people"."passport_number"
WHERE "passengers"."flight_id" = (
   SELECT "id"
   FROM "flights"
   WHERE "year" = 2021 AND "month" = 7 AND "day" = 29 AND "origin_airport_id" = (
        SELECT "id"
        FROM "airports"
        WHERE "city" = 'Fiftyville')
    ORDER BY "hour","minute"
    LIMIT 1
    );

-- AFTER COMPRING NAMES AND PASSENGERS' NAMES ONLY BRUCE'S NAME WAS PRESENT

-- FIND OUT WHERE BRUCE RAN AWAY TO:
SELECT "city", "full_name"
FROM "airports"
WHERE "id" = (
    SELECT "destination_airport_id"
    FROM "flights"
    WHERE "year" = 2021 AND "month" = 7 AND "day" = 29 AND "origin_airport_id" = (
        SELECT "id"
        FROM "airports"
        WHERE "city" = 'Fiftyville')
    ORDER BY "hour","minute"
    LIMIT 1
    );

-- HIS ACCOMPLICE
-- Raymond said that the thief then asked the person on the other end
--of the phone to purchase the flight ticket and the thief called his/her accomplice for less than a minute
SELECT "name"
FROM "people"
WHERE "phone_number" = (
    SELECT "receiver"
    FROM "phone_calls"
    WHERE "year" = 2021 AND "month" = 7 AND "day" = 28 AND "duration" < 60 AND "caller" = (
        SELECT "phone_number"
        FROM "people"
        WHERE "name" = 'Bruce'
    )
);