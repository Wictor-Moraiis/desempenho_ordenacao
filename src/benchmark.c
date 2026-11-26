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
#include "../include/heapSort.h"
#include "../include/mergeSort.h"
#include "../include/quickSort.h"
#include "../include/bucketSort.h"
#include "../include/radixSort.h"

#define QUANTIDADE_TESTES 6

int compararInteiros(const void *a, const void *b) {
    int valorA = *(const int *)a;
    int valorB = *(const int *)b;

    return (valorA > valorB) - (valorA < valorB);
}

int vetoresIguais(int vetorA[], int vetorB[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetorA[i] != vetorB[i]) {
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

    printf("%-12s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
           "Elementos",
           "Bubble (ms)",
           "Selection (ms)",
           "Insertion (ms)",
           "Counting (ms)",
           "Heap (ms)",
           "Merge (ms)",
           "Quick (ms)",
           "Bucket (ms)",
           "Radix (ms)");

    for (int i = 0; i < QUANTIDADE_TESTES; i++) {
        int tamanho = tamanhos[i];
        int *original = carregarVetor(arquivos[i], tamanho);

        if (original == NULL) {
            printf("Erro ao carregar %s\n", arquivos[i]);
            continue;
        }

        /* Cria uma referencia ordenada antes de iniciar as medicoes. */
        int *esperado = malloc(tamanho * sizeof(int));

        if (esperado == NULL) {
            printf("Erro ao alocar o vetor de referencia!\n");
            free(original);
            continue;
        }

        memcpy(esperado, original, tamanho * sizeof(int));
        qsort(esperado, tamanho, sizeof(int), compararInteiros);

        /* Alocacao dos vetores utilizados pelos algoritmos. */
        int *vetorBubble = malloc(tamanho * sizeof(int));
        int *vetorSelection = malloc(tamanho * sizeof(int));
        int *vetorInsertion = malloc(tamanho * sizeof(int));
        int *vetorCounting = malloc(tamanho * sizeof(int));
        int *vetorHeap = malloc(tamanho * sizeof(int));
        int *vetorMerge = malloc(tamanho * sizeof(int));
        int *vetorQuick = malloc(tamanho * sizeof(int));
        int *vetorBucket = malloc(tamanho * sizeof(int));
        int *vetorRadix = malloc(tamanho * sizeof(int));

        if (vetorBubble == NULL ||
            vetorSelection == NULL ||
            vetorInsertion == NULL ||
            vetorCounting == NULL ||
            vetorHeap == NULL ||
            vetorMerge == NULL ||
            vetorQuick == NULL ||
            vetorBucket == NULL ||
            vetorRadix == NULL) {

            printf("Erro ao alocar memoria para os vetores de teste!\n");

            free(original);
            free(esperado);
            free(vetorBubble);
            free(vetorSelection);
            free(vetorInsertion);
            free(vetorCounting);
            free(vetorHeap);
            free(vetorMerge);
            free(vetorQuick);
            free(vetorBucket);
            free(vetorRadix);
            continue;
        }

        /* Todos os algoritmos recebem exatamente a mesma entrada. */
        memcpy(vetorBubble, original, tamanho * sizeof(int));
        memcpy(vetorSelection, original, tamanho * sizeof(int));
        memcpy(vetorInsertion, original, tamanho * sizeof(int));
        memcpy(vetorCounting, original, tamanho * sizeof(int));
        memcpy(vetorHeap, original, tamanho * sizeof(int));
        memcpy(vetorMerge, original, tamanho * sizeof(int));
        memcpy(vetorQuick, original, tamanho * sizeof(int));
        memcpy(vetorBucket, original, tamanho * sizeof(int));
        memcpy(vetorRadix, original, tamanho * sizeof(int));

        clock_t inicio, fim;
        double tempoBubble, tempoSelection, tempoInsertion;
        double tempoCounting, tempoHeap, tempoMerge;
        double tempoQuick, tempoBucket, tempoRadix;

        inicio = clock();
        bubbleSort(vetorBubble, tamanho);
        fim = clock();
        tempoBubble = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        inicio = clock();
        selectionSort(vetorSelection, tamanho);
        fim = clock();
        tempoSelection = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        inicio = clock();
        insertionSort(vetorInsertion, tamanho);
        fim = clock();
        tempoInsertion = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        inicio = clock();
        countingSort(vetorCounting, tamanho);
        fim = clock();
        tempoCounting = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        inicio = clock();
        heapSort(vetorHeap, tamanho);
        fim = clock();
        tempoHeap = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        inicio = clock();
        mergeSort(vetorMerge, tamanho);
        fim = clock();
        tempoMerge = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        inicio = clock();
        quickSort(vetorQuick, tamanho);
        fim = clock();
        tempoQuick = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        inicio = clock();
        bucketSort(vetorBucket, tamanho);
        fim = clock();
        tempoBucket = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        inicio = clock();
        radixSort(vetorRadix, tamanho);
        fim = clock();
        tempoRadix = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

        /* A validacao acontece depois das medicoes, fora do cronometro. */
        int bubbleCorreto = vetoresIguais(vetorBubble, esperado, tamanho);
        int selectionCorreto = vetoresIguais(vetorSelection, esperado, tamanho);
        int insertionCorreto = vetoresIguais(vetorInsertion, esperado, tamanho);
        int countingCorreto = vetoresIguais(vetorCounting, esperado, tamanho);
        int heapCorreto = vetoresIguais(vetorHeap, esperado, tamanho);
        int mergeCorreto = vetoresIguais(vetorMerge, esperado, tamanho);
        int quickCorreto = vetoresIguais(vetorQuick, esperado, tamanho);
        int bucketCorreto = vetoresIguais(vetorBucket, esperado, tamanho);
        int radixCorreto = vetoresIguais(vetorRadix, esperado, tamanho);

        printf("%-12d %-15.3f %-15.3f %-15.3f %-15.3f %-15.3f %-15.3f %-15.3f %-15.3f %-15.3f\n",
               tamanho,
               tempoBubble,
               tempoSelection,
               tempoInsertion,
               tempoCounting,
               tempoHeap,
               tempoMerge,
               tempoQuick,
               tempoBucket,
               tempoRadix);

        printf("Validacao: Bubble %s | Selection %s | Insertion %s | Counting %s | Heap %s | Merge %s | Quick %s | Bucket %s | Radix %s\n",
               bubbleCorreto ? "OK" : "ERRO",
               selectionCorreto ? "OK" : "ERRO",
               insertionCorreto ? "OK" : "ERRO",
               countingCorreto ? "OK" : "ERRO",
               heapCorreto ? "OK" : "ERRO",
               mergeCorreto ? "OK" : "ERRO",
               quickCorreto ? "OK" : "ERRO",
               bucketCorreto ? "OK" : "ERRO",
               radixCorreto ? "OK" : "ERRO");

        free(original);
        free(esperado);
        free(vetorBubble);
        free(vetorSelection);
        free(vetorInsertion);
        free(vetorCounting);
        free(vetorHeap);
        free(vetorMerge);
        free(vetorQuick);
        free(vetorBucket);
        free(vetorRadix);
    }

    printf("================================================================================================================\n");
}
