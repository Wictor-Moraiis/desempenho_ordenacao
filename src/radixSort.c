#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSortDigito(int vetor[], int tamanho, long long exp, int saida[])
{
    int contagem[10] = {0};
    int i, digito;

    for(i = 0; i < tamanho; i++){

        digito = (vetor[i] / exp) % 10;
        contagem[digito]++;
    }

    for(i = 1; i < 10; i++){
        contagem[i] += contagem[i - 1];
    }

    for(i = tamanho - 1; i >= 0; i--){

        digito = (vetor[i] / exp) % 10;

        saida[contagem[digito] - 1] = vetor[i];

        contagem[digito]--;
    }

    memcpy(vetor, saida, tamanho * sizeof(int));
}


void radixSort(int vetor[], int tamanho)
{
    int i;
    int maior;

    if(vetor == NULL || tamanho <= 1){
        return;
    }

    for(i = 0; i < tamanho; i++){

        if(vetor[i] < 0){
            printf("Radix Sort: numeros negativos nao sao suportados.\n");
            return;
        }
    }

    maior = vetor[0];

    for(i = 1; i < tamanho; i++){

        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }

    int *saida = malloc(tamanho * sizeof(int));

    if(saida == NULL){
        printf("Erro ao alocar memoria no Radix Sort!\n");
        return;
    }

    for(long long exp = 1; maior / exp > 0; exp *= 10){

        countingSortDigito(vetor, tamanho, exp, saida);
    }

    free(saida);
}