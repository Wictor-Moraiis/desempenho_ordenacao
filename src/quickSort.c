#include <stdlib.h>
#include <stdio.h>
#include "quickSort.h"

void trocar(int *a, int *b) {
    int temporario = *a;
    *a = *b;
    *b = temporario;
}

int partition(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);

    return i + 1;
}

void quickSortRecursivo(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = partition(vetor, inicio, fim);

        quickSortRecursivo(vetor, inicio, indicePivo - 1);
        quickSortRecursivo(vetor, indicePivo + 1, fim);
    }
}

void quickSort(int vetor[], int tamanho) {
    if (tamanho <= 1) {
        return;
    }

    quickSortRecursivo(vetor, 0, tamanho - 1);
}