// FALTA VERIFICAR O BUG DO INDEX QUE NÃO ESTÁ ACEITANDO PLAINTEX

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_char (string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Usage: ./substitution key\n");
        return 1;
    }
    if (!check_char (argv[1]))
    {
        printf ("Key must contain 26 unique characters.\n");
        return 1;
    }
    int length, index;
    string plaintext = get_string ("Plaintext:\n");
    string key = argv[1];
    length = strlen (plaintext);
    char cyphertext [length +1];
    for (int i = 0; i < length; i++)
    {
        if (islower(plaintext[i]))
        {
            index = plaintext - 97;
            cyphertext[i] = key [index];
            if (isupper (cyphertext[i]))
            {
                cypertext[i] += 32;
            }
        }
        else if (isupper(plaintext[i]))
        {
            index = plaintext - 65;
            cyphertext[i] = key [index];
            if (islower (cyphertext[i]))
            {
                cypertext[i] -= 32;
            }
        else
        {
            cyphertex[i] = plaintext [i];
        }

        }
    }
    cyphertext [length] = '\0'; // mostra o fim da string
    printf ("cyphertext: %s\n", cyphertext);

}
bool check_char (string key)
{
    int length;
    length = strlen (key);

    if (length != 26)
    {
        return false;
    }
    for (int i = 0; i < length; i++)
    {
        key[i] = toupper (key[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key [j])
            {
                return false;
            }

        }
    }
    return true;
}