#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//0.0588 * L - 0.296 * S - 15.8
//resultado disso arredondado

//letras maiusculas ou minusculas
//qq sequencia de caracteres terminada em espaço é uma palavra
//qq sequencia terminada em ponto, exclamacao ou interrogacao é uma frase

int main()
{
    //input do user
    string texto = get_string("Text: ");

    //variaveis de contagem de letra, palavra, frase e calculo da formula
    float letras=0, palavras=0, frases=0;
    int nivelArredondado;
    double nivelPreciso, L, S;

    int tamanho_texto = strlen(texto);


    //contagem geral
    for (int caracter = 0; caracter < tamanho_texto; caracter++)
    {
        // contagem letras
        if (isalpha(texto[caracter]))
        {
            letras++;
        }

        // contagem palavras
        if (isspace(texto[caracter]))
        {
            palavras++;
        }

        // contagem frases
        if (texto[caracter] == '!' || texto[caracter] == '.' || texto[caracter] == '?')
        {
            frases++;
        }

    }
    palavras++;

    L = (100 * letras / palavras);
    S = (100 * frases / palavras);
    //printf("%f\n%f\n", L, S);

    nivelPreciso = 0.0588 * L - 0.296 * S - 15.8;

    //printf("%i letras\n%i palavras\n%i frases\n", letras, palavras, frases);
    //printf("%c\n", texto[tamanho_texto]);

    //se for maior ou igual a 16, imprimir 16+
    if (nivelPreciso >= 16)
    {
        printf("Grade 16+");
    }
    //se for menor que 1, imprimir "Before Grade 1"
    else if (nivelPreciso < 1)
    {
        printf("Before Grade 1");
    }
    //de resto imprime o numero arredondado
    else
    {
        printf("Grade %i", nivelArredondado = round(nivelPreciso));
    }

    printf("\n");

}