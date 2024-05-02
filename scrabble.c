#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
// criar um array para colocar todos os pontos que cada letra representa
int POINTS [] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
// declarando função compute que irá receber um argumento (string word)
int compute_scores(string word);

int main (void)
{
    // obter valor dos dois jogadores
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");

    //função para calcular a pontuação de ambos os jogadores
    int score1 = compute_scores(word1);
    int score2 = compute_scores(word2);

    if(score 1 > score 2)
    {
        printf ("Player 1 Wins!\n");
    }
    else if (score 1 < score 2)
    {
        printf ("Player 2 Wins!\n");
    }
    else
    {
        printf ("Tie!\n");
    }

int compute_scores(string word)
{
    //criar uma variável para poder iniciar a soma dos pontos
    int sum_points = 0;
    //criar um loop para iterar em todas as letras da string(word) que será passada como argumento
    for (int i = 0; i < strlen(word); i++) // função strlen nos dá o números de caracteres tanto no array e vai auxiliar o loop para iterar en cada um dos itens do string
    {
        if( isalpha(word[i])) // função que retorna true se o valor for alphanumérico(letras e números)
        {
            int letter_offset = toupper (word[i] - 'A');
            sum_points += POINTS[letter_offset];
        }
    }
    return sum_points;

}
