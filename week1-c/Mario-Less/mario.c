#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Declara a váriavel que vai armazenar a altura da pirâmide
    int altura;

    //Loop até que o usuário digite um número válido (entre 1 à 8)
    do
    {
        altura = get_int("Height: ");
    }
    while (altura < 1 || altura > 8);

    //Loop para controlar as linhas da pirâmide
    for (int linha = 0; linha < altura; linha++)
    {
        //loop para imprimir os espaços à esquerda, diminui a cada linha
        for (int espacos = 0; espacos < altura - linha - 1; espacos++)
        {
            printf(" ");
        }

        //Loop para imprimir os blocos(#), aumenta a quantidade a cada linha
        for (int coluna = 0; coluna <= linha; coluna++)
        {
            printf("#");
        }

        // Quebra de linha após imprimir todos os espaços e blocos da linha atual
        printf("\n");
    }
}
