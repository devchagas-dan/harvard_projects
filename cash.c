#include <cs50.h>
#include <stdio.h>


int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);


    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);


    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);


    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}
int get_cents(void)
{
    // CRIAR UMA FUNÇÃO QUE RECEBA UM INTEGER DO USUÁRIO E RETORNE UM VALOR
    int n;
    do
    {
     n = get_int("Change owed: ");
    }
    while (n < 1);
    return n;
}


int calculate_quarters(int cents)
{
    cents = cents / 25;
    return cents;
}

int calculate_dimes(int cents)
{
    cents = cents % 25 / 10;
    return cents;
}

int calculate_nickels(int cents)
{
    cents = cents % 25 % 10 / 5;
    return cents;
}

int calculate_pennies(int cents)
{
    cents = cents % 25 % 10 % 5 / 1;
    return cents;
}
