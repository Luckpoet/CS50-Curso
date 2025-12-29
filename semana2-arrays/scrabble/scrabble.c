#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Array que armazena os pontos de cada letra do alfabeto de A a Z
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Função que calcula a pontuação total de uma palavra
int computer_score(string word)
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Se a letra for maiúscula
        if (isupper(word[i]))
        {
            // Subtrai 'A' para converter o valor ASCII em índice 0-25
            score += points[word[i] - 'A'];
        }
        // Se a letra for minúscula
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }

    return score;
}

int main(void)
{
    // Solicita a palavra de cada um dos dois jogadores
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");

    // Calcula a pontuação de ambos chamando a função computer_score
    int score1 = computer_score(word1);
    int score2 = computer_score(word2);

    // Compara os resultados e imprime o vencedor ou empate
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}