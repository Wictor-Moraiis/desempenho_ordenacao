
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/benchmark.h"
#include "../include/vetor.h"
#include "../include/bubbleSort.h"
#include "../include/selectionSort.h"
#include "../include/insertionSort.h"
#include "../include/countingSort.h"
#include "../include/mergeSort.h"
#include "../include/quickSort.h"
#include "../include/bucketSort.h"

#define QUANTIDADE_TESTES 6

int vetorOrdenado(int vetor[], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return 0;
        }
    }

    return 1;
}

void Benchmark(void) {

    char arquivos[QUANTIDADE_TESTES][20] = {
        "vetor_1.txt",
        "vetor_2.txt",
        "vetor_3.txt",
        "vetor_4.txt",
        "vetor_5.txt",
        "vetor_6.txt"
    };

    int tamanhos[QUANTIDADE_TESTES] = {
        100, 1000, 5000, 10000, 50000, 100000
    };

    printf("\n================================================================================================================\n");
    printf("                                      COMPARACAO DE ALGORITMOS\n");
    printf("================================================================================================================\n");

    printf("%-12s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
           "Elementos",
           "Bubble (ms)",
           "Selection (ms)",
           "Insertion (ms)",
           "Counting (ms)",
           "Merge (ms)",
           "Quick (ms)",
           "Bucket (ms)");

    for (int i = 0; i < QUANTIDADE_TESTES; i++) {

        int tamanho = tamanhos[i];

        int *original = carregarVetor(arquivos[i], tamanho);

        if (original == NULL) {
            printf("Erro ao carregar %s\n", arquivos[i]);
            continue;
        }

        int *vetorBubble = malloc(tamanho * sizeof(int));
        int *vetorSelection = malloc(tamanho * sizeof(int));
        int *vetorInsertion = malloc(tamanho * sizeof(int));
        int *vetorCounting = malloc(tamanho * sizeof(int));
        int *vetorMerge = malloc(tamanho * sizeof(int));
        int *vetorQuick = malloc(tamanho * sizeof(int));
        int *vetorBucket = malloc(tamanho * sizeof(int));

        if (vetorBubble == NULL ||
            vetorSelection == NULL ||
            vetorInsertion == NULL ||
            vetorCounting == NULL ||
            vetorMerge == NULL ||
            vetorQuick == NULL ||
            vetorBucket == NULL) {

            printf("Erro ao alocar memoria!\n");

            free(original);
            free(vetorBubble);
            free(vetorSelection);
            free(vetorInsertion);
            free(vetorCounting);
            free(vetorMerge);
            free(vetorQuick);
            free(vetorBucket);

            continue;
        }

        // Copia o mesmo vetor original para todos os algoritmos
        memcpy(vetorBubble, original, tamanho * sizeof(int));
        memcpy(vetorSelection, original, tamanho * sizeof(int));
        memcpy(vetorInsertion, original, tamanho * sizeof(int));
        memcpy(vetorCounting, original, tamanho * sizeof(int));
        memcpy(vetorMerge, original, tamanho * sizeof(int));
        memcpy(vetorQuick, original, tamanho * sizeof(int));
        memcpy(vetorBucket, original, tamanho * sizeof(int));

        clock_t inicio, fim;

        double tempoBubble, tempoSelection, tempoInsertion;
        double tempoCounting, tempoMerge, tempoQuick, tempoBucket;

        // Bubble Sort
        inicio = clock();

        bubbleSort(vetorBubble, tamanho);

        fim = clock();

        tempoBubble = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        // Selection Sort
        inicio = clock();

        selectionSort(vetorSelection, tamanho);

        fim = clock();

        tempoSelection = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        // Insertion Sort
        inicio = clock();

        insertionSort(vetorInsertion, tamanho);

        fim = clock();

        tempoInsertion = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        // Counting Sort
        inicio = clock();

        countingSort(vetorCounting, tamanho);

        fim = clock();

        tempoCounting = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        // Merge Sort
        inicio = clock();

        mergeSort(vetorMerge, tamanho);

        fim = clock();

        tempoMerge = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        // Quick Sort
        inicio = clock();

        quickSort(vetorQuick, tamanho);

        fim = clock();

        tempoQuick = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        // Bucket Sort
        inicio = clock();

        bucketSort(vetorBucket, tamanho);

        fim = clock();

        tempoBucket = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        // Verifica se os vetores foram ordenados corretamente
        int bubbleCorreto = vetorOrdenado(vetorBubble, tamanho);
        int selectionCorreto = vetorOrdenado(vetorSelection, tamanho);
        int insertionCorreto = vetorOrdenado(vetorInsertion, tamanho);
        int countingCorreto = vetorOrdenado(vetorCounting, tamanho);
        int mergeCorreto = vetorOrdenado(vetorMerge, tamanho);
        int quickCorreto = vetorOrdenado(vetorQuick, tamanho);
        int bucketCorreto = vetorOrdenado(vetorBucket, tamanho);

        printf("%-12d %-15.3f %-15.3f %-15.3f %-15.3f %-15.3f %-15.3f %-15.3f\n",
               tamanho,
               tempoBubble,
               tempoSelection,
               tempoInsertion,
               tempoCounting,
               tempoMerge,
               tempoQuick,
               tempoBucket);

        if (!bubbleCorreto || !selectionCorreto ||
            !insertionCorreto || !countingCorreto ||
            !mergeCorreto || !quickCorreto || !bucketCorreto) {

            printf("ERRO: Algoritmo apresentou resultado incorreto!\n");
        }

        free(original);
        free(vetorBubble);
        free(vetorSelection);
        free(vetorInsertion);
        free(vetorCounting);
        free(vetorMerge);
        free(vetorQuick);
        free(vetorBucket);
    }

    printf("================================================================================================================\n");
}
