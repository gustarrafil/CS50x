#include <cs50.h>
#include <stdio.h>

//user decides how tall it is, entering something 1 <= 8
//gap equals to ##

int main(void)
{
    int linha, coluna, numero;

    do
    {
        numero = get_int("Height: ");
    }
    while (numero < 1 || numero > 8);

    for (linha = 1; linha <= numero; linha++)
    {
        for (coluna = 1; coluna <= numero-linha; coluna++)
        {
            printf(" ");
        }

        for (coluna = 1; coluna <= linha; coluna++)
        {
            printf("#");
        }

        printf("  ");

        for (coluna = 1; coluna <= linha; coluna++)
        {
            printf("#");
        }


        printf("\n");
    }

    return 0;
}