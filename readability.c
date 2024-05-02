#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
int grade(int letters, int sentences, int words);
void print(int level);

int main(void)
{
    string text = get_string("Type your text: ");

    int letters = count_letters(text);
    int sentences = count_sentences(text);
    int words = count_words(text);
    int level = grade(letters, sentences, words);

    print(level);
}

int count_letters(string text)
{
    // preciso de uma função que vá calcular o número de letras do texto
    int letters = 0;
    // loop para passar por todas as linhas e verificar o tamanho delas e se é letra ou número
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }
    return sentences;
}
int count_words(string text)
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words += 1;
        }
    }
    return words + 1;
}

int grade(int letters, int sentences, int words)
{
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}

void print(int level)
{
    if (level <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", level);
    }
}
