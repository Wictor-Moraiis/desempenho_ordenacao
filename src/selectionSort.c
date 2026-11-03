#include <stdlib.h>
#include <stdio.h>
#include "selectionSort.h"

void selectionSort(int vetor[], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[indiceMenor];
        vetor[indiceMenor] = temp;
    }
}
