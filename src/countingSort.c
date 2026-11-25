#include <stdlib.h>
#include <stdio.h>

void countingSort(int vetor[], int tamanho)
{
    int menor, maior, i, intervalo;

    menor = vetor[0];
    maior = vetor[0];


    for(i = 1; i < tamanho; i++){

        if(vetor[i] < menor){
            menor = vetor[i];
        }

        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }

    intervalo = maior - menor + 1;

    int *contagem = calloc(intervalo, sizeof(int));
    
    if (contagem == NULL) {

        printf("Erro ao alocar memoria!\n");
         return;
    }

    for(i = 0; i < tamanho; i++){

        int indice = vetor[i] - menor;
        contagem[indice]++;
    }

   int pos = 0;

    for(i = 0; i < intervalo; i++){

        while(contagem[i] > 0){

            vetor[pos] = i + menor;
            pos++;
            contagem[i]--;
        }
    }

    free(contagem);
}