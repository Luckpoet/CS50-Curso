#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar para verificar se uma string contém apenas dígitos (0-9)
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Se o caractere atual não for um dígito
        if (!isdigit(s[i]))
        {
            return false; // A string é inválida
        }
    }
    return true; // A string é válida
}

// Função que rotaciona um caractere 'x' por 'y' posições
char rotate(char x, int y)
{
    // Verifica se é letra maiúscula
    if (isupper(x))
    {
        // Converte ASCII para índice 0-25
        return (x - 'A' + y) % 26 + 'A';
    }
    // Verifica se é letra minúscula
    else if (islower(x))
    {
        return (x - 'a' + y) % 26 + 'a';
    }
    // Se não for letra retorna sem alteração
    else
    {
        return x;
    }
}

int main(int argc, string argv[])
{
    // Verifica se o usuário forneceu o número correto de argumentos
    // Exemplo esperado: ./caesar 13 (argc deve ser 2)
    if (argc != 2)
    {
        printf("usage: ./caesar key\n");
        return 1; // Retorna 1 para indicar erro
    }

    // Verifica se o segundo argumento contém apenas números
    if (!only_digits(argv[1]))
    {
        printf("usage: ./caesar key\n");
        return 1;
    }

    // Converte a chave de String para Inteiro
    int key = atoi(argv[1]);

    // Solicita o texto original ao usuário
    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    // Loop que percorre cada caractere do texto de entrada
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Imprime o caractere rotacionado chamando a função rotate
        printf("%c", rotate(text[i], key));
    }

    // Pula uma linha ao final para o terminal ficar limpo
    printf("\n");

    return 0; // Sucesso =)
}
