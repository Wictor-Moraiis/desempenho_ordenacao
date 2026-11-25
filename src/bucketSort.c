#include <stdlib.h>
#include "bucketSort.h"

void encontrarMinMax(int vetor[], int tamanho, int *minimo, int *maximo) {
    *minimo = vetor[0];
    *maximo = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < *minimo) {
            *minimo = vetor[i];
        }
        if (vetor[i] > *maximo) {
            *maximo = vetor[i];
        }
    }
}

int calcularIndiceBucket(int valor, int minimo, int maximo, int quantidadeBuckets) {
    long long intervalo = (long long)maximo - minimo + 1;

    return ((long long)valor - minimo) * quantidadeBuckets / intervalo;
}

void insertionSortBucket(int vetor[], int inicio, int fim) {
    for (int i = inicio + 1; i < fim; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= inicio && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

void bucketSort(int vetor[], int tamanho) {
    if (tamanho <= 1) {
        return;
    }
    int minimo, maximo;

    encontrarMinMax(vetor, tamanho, &minimo, &maximo);
    if (minimo == maximo) {
        return;
    }
    int quantidadeBuckets = tamanho;

    int *contagem = calloc(quantidadeBuckets, sizeof(int));
    int *inicio = malloc(quantidadeBuckets * sizeof(int));
    int *proximaPosicao = malloc(quantidadeBuckets * sizeof(int));
    int *auxiliar = malloc(tamanho * sizeof(int));

    if (contagem == NULL || inicio == NULL ||
        proximaPosicao == NULL || auxiliar == NULL) {
        free(contagem);
        free(inicio);
        free(proximaPosicao);
        free(auxiliar);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        int indice = calcularIndiceBucket(
            vetor[i], minimo, maximo, quantidadeBuckets);
        contagem[indice]++;
    }

    int total = 0;
    for (int i = 0; i < quantidadeBuckets; i++) {
        inicio[i] = total;
        proximaPosicao[i] = total;
        total += contagem[i];
    }

    for (int i = 0; i < tamanho; i++) {
        int indice = calcularIndiceBucket(
            vetor[i], minimo, maximo, quantidadeBuckets
        );
        auxiliar[proximaPosicao[indice]] = vetor[i];
        proximaPosicao[indice]++;
    }

    for (int i = 0; i < quantidadeBuckets; i++) {
        insertionSortBucket(
            auxiliar,
            inicio[i],
            inicio[i] + contagem[i]
        );
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = auxiliar[i];
    }

    free(contagem);
    free(inicio);
    free(proximaPosicao);
    free(auxiliar);
}