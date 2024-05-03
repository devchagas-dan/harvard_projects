#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    unsigned int k = argc;
    if (k != 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string ("plaintext:  ");
    string ciphertext;
    printf("ciphertext: %s", ciphertext);

    printf ("\n");
    return 0;

}


