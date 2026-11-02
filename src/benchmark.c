#include <stdlib.h>
#include <stdio.h>
#include "../include/vetor.h"
#include "../include/bubbleSort.h"
#include <time.h>

clock_t inicio, fim;
double tempo;

void Benchmark()
{
    int *vetor;

    vetor = carregarVetor("vetor_3.txt", 5000);

    if (vetor == NULL)
        return;

    inicio = clock();

    bubbleSort(vetor, 5000);

    fim = clock();

    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

    printf("Tempo Bubble Sort: %.3f ms\n", tempo);

    free(vetor);
}