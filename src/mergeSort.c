
#include <stdlib.h>
#include <stdio.h>
#include "mergeSort.h"

void mergeSortRecursivo(int vetor[], int inicio, int fim);
void merge(int vetor[], int inicio, int meio, int fim);

void mergeSort(int vetor[], int tamanho) {

    if (tamanho <= 1) {
        return;
    }

    mergeSortRecursivo(vetor, 0, tamanho - 1);
}

void mergeSortRecursivo(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSortRecursivo(vetor, inicio, meio);
        mergeSortRecursivo(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

void merge(int vetor[], int inicio, int meio, int fim) {
    int tamanhoAuxiliar = fim - inicio + 1;
    int *auxiliar = malloc(tamanhoAuxiliar * sizeof(int));

    if (auxiliar == NULL) {
        return;
    }
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {

        if (vetor[i] <= vetor[j]) {
            auxiliar[k] = vetor[i];
            i++;
        } else {
            auxiliar[k] = vetor[j];
            j++;
        }

        k++;
    }

    while (i <= meio) {
        auxiliar[k] = vetor[i];
        i++;
        k++;
    }

    while (j <= fim) {
        auxiliar[k] = vetor[j];
        j++;
        k++;
    }

    for (int i = 0; i < tamanhoAuxiliar; i++) {
        vetor[inicio + i] = auxiliar[i];
    }

    free(auxiliar);
}
