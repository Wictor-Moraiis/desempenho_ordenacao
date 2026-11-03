
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/benchmark.h"
#include "../include/vetor.h"
#include "../include/bubbleSort.h"
#include "../include/selectionSort.h"

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

    printf("\n===============================================\n");
    printf("          COMPARACAO DE ALGORITMOS\n");
    printf("===============================================\n");

    printf("%-12s %-18s %-18s\n",
           "Elementos", "Bubble Sort (ms)", "Selection Sort (ms)");

    for (int i = 0; i < QUANTIDADE_TESTES; i++) {

        int tamanho = tamanhos[i];

        int *original = carregarVetor(arquivos[i], tamanho);

        if (original == NULL) {
            printf("Erro ao carregar %s\n", arquivos[i]);
            continue;
        }

        int *vetorBubble = malloc(tamanho * sizeof(int));
        int *vetorSelection = malloc(tamanho * sizeof(int));

        if (vetorBubble == NULL || vetorSelection == NULL) {

            printf("Erro ao alocar memoria!\n");

            free(original);
            free(vetorBubble);
            free(vetorSelection);

            continue;
        }

        // Copia o mesmo vetor para os dois algoritmos
        memcpy(vetorBubble, original, tamanho * sizeof(int));
        memcpy(vetorSelection, original, tamanho * sizeof(int));

        clock_t inicio, fim;
        double tempoBubble, tempoSelection;

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

        // Verifica se os vetores foram ordenados corretamente
        int bubbleCorreto = vetorOrdenado(vetorBubble, tamanho);
        int selectionCorreto = vetorOrdenado(vetorSelection, tamanho);

        printf("%-12d %-18.3f %-18.3f\n",
               tamanho, tempoBubble, tempoSelection);

        if (!bubbleCorreto || !selectionCorreto) {
            printf("ERRO: Algoritmo apresentou resultado incorreto!\n");
        }

        free(original);
        free(vetorBubble);
        free(vetorSelection);
    }

    printf("===============================================\n");
}
