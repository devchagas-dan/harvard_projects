from cs50 import get_float


def main():
    cents = get_cents()

    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    pennies = calculate_pennies(cents)
    cents = cents - pennies

    coins = quarters + dimes + nickels + pennies

    print(coins)


def get_cents():
    while True:
        n = get_float("Change owed: ")
        if n >= 0:
            break
    cents = n * 100
    return cents


def calculate_quarters(cents):
    counter = 0
    while cents >= 25:
        cents = cents - 25
        counter += 1
    return counter


def calculate_dimes(cents):
    counter = 0
    while cents >= 10:
        cents = cents - 10
        counter += 1
    return counter


def calculate_nickels(cents):
    counter = 0
    while cents >= 5:
        cents = cents - 5
        counter += 1
    return counter


def calculate_pennies(cents):
    counter = 0
    while cents >= 1:
        cents = cents - 1
        counter += 1
    return counter


main()