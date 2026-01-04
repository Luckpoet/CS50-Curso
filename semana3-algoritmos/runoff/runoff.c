#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de eleitores e candidatos
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] é a j-ésima preferência do eleitor i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidatos têm nome, número de votos e status de eliminação
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Vetor de candidatos
candidate candidates[MAX_CANDIDATES];

// Número de eleitores e candidatos
int voter_count;
int candidate_count;

// Protótipos das funções
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Verifica uso inválido do programa
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Preenche o vetor de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("O número máximo de candidatos é %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Obtém o número de eleitores
    voter_count = get_int("Número de eleitores: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("O número máximo de eleitores é %i\n", MAX_VOTERS);
        return 3;
    }

    // Coleta os votos
    for (int i = 0; i < voter_count; i++)
    {
        // Para cada posição do ranking
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Preferência %i: ", j + 1);

            // Registra o voto, a menos que seja inválido
            if (!vote(i, j, name))
            {
                printf("Voto inválido.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Continua realizando rodadas até existir um vencedor
    while (true)
    {
        // Calcula os votos considerando apenas candidatos não eliminados
        tabulate();

        // Verifica se a eleição já tem um vencedor
        if (print_winner())
        {
            break;
        }

        // Encontra o menor número de votos
        int min = find_min();
        bool tie = is_tie(min);

        // Se houver empate, todos os candidatos restantes vencem
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Elimina os candidatos com o menor número de votos
        eliminate(min);

        // Zera a contagem de votos para a próxima rodada
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Registra a preferência se o voto for válido
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Conta os votos dos candidatos não eliminados
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
}

// Imprime o vencedor da eleição, se existir
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Retorna o menor número de votos entre os candidatos restantes
int find_min(void)
{
    int min = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Retorna true se a eleição estiver empatada entre todos os candidatos restantes
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Elimina o(s) candidato(s) que estão em último lugar
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
