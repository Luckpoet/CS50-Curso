#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de candidatos
#define MAX 9

// Os candidatos possuem nome e número de votos
typedef struct
{
    string name;
    int votes;
} candidate;

// Vetor para armazenar os candidatos
candidate candidates[MAX];

// Número de candidatos
int candidate_count;

// Protótipos das funções
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifica o uso incorreto do programa
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Preenche o vetor de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("O número máximo de candidatos é %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Número de eleitores: ");

    // Percorre todos os eleitores
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Voto: ");

        // Verifica se o voto é inválido
        if (!vote(name))
        {
            printf("Voto inválido.\n");
        }
    }

    // Exibe o vencedor da eleição
    print_winner();
}

// Atualiza o total de votos a partir de um novo voto
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Imprime o vencedor (ou vencedores) da eleição
void print_winner(void)
{
    int max_votes = 0;

    // Encontra o maior número de votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Imprime todos os candidatos com o maior número de votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
