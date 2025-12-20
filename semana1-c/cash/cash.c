#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Variável que armazenará o valor do troco em centavos
    int centavos;

    // Solicita ao usuário um valor válido (não negativo)
    do
    {
        centavos = get_int("Troco devido (em centavos): ");
    }
    while (centavos < 0);

    // Contador que armazenará a quantidade total de moedas usadas
    int moedas = 0;

    // Enquanto for possível usar moedas de 25 centavos (quarter)
    while (centavos >= 25)
    {
        centavos -= 25; // Subtrai 25 centavos do valor restante
        moedas++;      // Incrementa o número de moedas utilizadas
    }

    while (centavos >= 10)
    {
        centavos -= 10; 
        moedas++;      
    }

    while (centavos >= 5)
    {
        centavos -= 5;
        moedas++;     
    }

    while (centavos >= 1)
    {
        centavos -= 1;
        moedas++;    
    }

    // Imprime o número mínimo de moedas necessárias para o troco
    printf("%i\n", moedas);
}