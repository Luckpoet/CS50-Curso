#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare the variable that will store the pyramid height
    int altura;

    // Loop until the user enters a valid number
    do
    {
        altura = get_int("Height: ");
    }
    while (altura < 1 || altura > 8);

    // Loop that controls each row of the pyramid
    for (int linha = 0; linha < altura; linha++)
    {
        // Loop to print the left spaces, decreasing on each row
        for (int espacos = 0; espacos < altura - linha - 1; espacos++)
        {
            printf(" ");
        }

        // Loop to print the blocks (#), increasing on each row
        for (int coluna = 0; coluna <= linha; coluna++)
        {
            printf("#");
        }

        // Print a new line after finishing the current row
        printf("\n");
    }
}
