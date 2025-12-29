#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Função que aplica a fórmula de Coleman-Liau
int calcular_indice(int letras, int frases, int palavras)
{
    // L = média de letras por 100 palavras
    float l = ((float) letras / palavras) * 100;
    // S = média de frases por 100 palavras
    float s = ((float) frases / palavras) * 100;

    // A fórmula do índice
    float index = 0.0588 * l - 0.296 * s - 15.8;
    
    // Retorna o valor arredondado para o inteiro mais próximo
    return (int) round(index);
}

int main(void)
{
    // Solicita o texto ao usuário
    string text = get_string("Text: ");

    int letras = 0;
    int palavras = 1; // Começa em 1 pois a última palavra não tem espaço depois
    int frases = 0;
    int tamanhotext = strlen(text);

    // Percorre o texto caractere por caractere
    for (int i = 0; i < tamanhotext; i++)
    {
        // Se for uma letra (A-Z ou a-z), incrementa letras
        if (isalpha(text[i]))
        {
            letras++;
        }
        // Se for um espaço, é o fim de uma palavra
        else if (isspace(text[i]))
        {
            palavras++;
        }
        // Fim de uma frase
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            frases++;
        }
    }

    int grade = calcular_indice(letras, frases, palavras);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}