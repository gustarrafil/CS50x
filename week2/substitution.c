#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



//receber argumento de execucao
int receber(int numeroArg, string chave);


int main(int argc, string argv[])
{
    //recebendo chave em argumento da main
    int numeroArg = argc;
    string chave = argv[1];

    //validando a chave e pegando P
    if (receber(numeroArg, chave) == 0) {
        string P = get_string("plaintext: ");
        string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string mP = P;
        string mchave = chave;
        int posicaoAlpha[strlen(P)];
        string C = P;

        //resto de todo codigo aqui dentro

        //pra cada carac, determinar posicao na string alfabeto
        for (int lP = 0; lP < strlen(P); lP++) {
            for (int lAlpha = 0; lAlpha < strlen(alpha); lAlpha++) {
                if (P[lP] == alpha[lAlpha] || P[lP] - 32 == alpha[lAlpha] || P[lP] == alpha[lAlpha] - 32) {

                    posicaoAlpha[lP] = lAlpha;
                }
            }
        }
        //aqui tenho uma lista com todos os valores das posicoes de cada letra de P na string alfabeto

        // for (int i =0; i< strlen(P);i++) {
        //     printf("%d, ", posicaoAlpha[i]);
        // }

        //em cada letra da conversao, busca a posicao da original na string da chave e forma a string cifrada
        //preservar maiusculas e minusculas
        for (int p = 0; p < strlen(C); p++) {
            if (isalpha(P[p])) {
                for (int lc = 0; lc < strlen(chave); lc++) {
                    if (islower(P[p])) {
                        C[p] = tolower(chave[posicaoAlpha[p]]);
                    } else {
                        C[p] = toupper(chave[posicaoAlpha[p]]);
                    }
                }
            }
        }


        //printf("%s\n", mchave);




        printf("ciphertext: %s\n", C);




    } else {
        return 1;
    }


    return 0;
}

int receber(int numeroArg, string chave) {
    if (numeroArg == 1) {
        printf("Usage: ./substituion KEY\n");
        return 1;
    } else if (numeroArg > 2) {
        printf("tem coisa a mais ai\n");
        return 1;
    } else if (strlen(chave) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (strlen(chave) == 26) {
        for (int l = 0; l < strlen(chave); l++) {
            if (isdigit(chave[l])) {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }
        for (int l = 0; l < strlen(chave); l++) {
            for (int lr = l + 1; lr < strlen(chave); lr++) {
                if (chave[l] == chave[lr]) {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
        // receber(argv[1]);
    }
    //printf("%s\n", chave);
    return 0;
}