#include <stdlib.h>
#include <stdio.h>

void insertionSort(int vetor[], int tamanho)
{
    int chave, i, j;

    for(i = 1; i < tamanho; i++){

        chave = vetor[i];
        j = i - 1;
        
        while(j >= 0 && vetor[j] > chave){

            vetor[j + 1] = vetor[j];
            j--;
        }    
        vetor[j + 1] = chave;
    }
}