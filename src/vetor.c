#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "../include/vetor.h"

int gerarVetor(int tamanho, int faixa, char nomeArquivo[30]) {
    if (tamanho <= 0 || faixa < 0 || faixa == INT_MAX) {
        printf("Tamanho ou faixa invalida!\n");
        return 1;
    }

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s!\n", nomeArquivo);
        return 1;
    }

    int menor = faixa;
    int maior = 0;

    for (int i = 0; i < tamanho; i++) {
        int valor = rand() % (faixa + 1);

        if (valor < menor) {
            menor = valor;
        }
        if (valor > maior) {
            maior = valor;
        }

        fprintf(arquivo, "%d\n", valor);
    }

    fclose(arquivo);

    printf("Arquivo: %s | N: %d | faixa permitida: 0 a %d | minimo observado: %d | maximo observado: %d | K observado: %d\n",
           nomeArquivo, tamanho, faixa, menor, maior, maior - menor + 1);

    return 0;
}

void gerarVetores(void) {
    char nomeArquivo[30];
    int tamanhos[6] = {100, 1000, 5000, 10000, 50000, 100000};
    int faixas[6] = {100, 1000, 5000, 10000, 50000, 100000};

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 6; i++) {
        snprintf(nomeArquivo, sizeof(nomeArquivo), "vetor_%d.txt", i + 1);
        gerarVetor(tamanhos[i], faixas[i], nomeArquivo);
    }
}

int *carregarVetor(char nomeArquivo[], int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }

    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nomeArquivo);
        return NULL;
    }

    int *vetor = malloc((size_t)tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria para carregar o vetor!\n");
        fclose(arquivo);
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        if (fscanf(arquivo, "%d", &vetor[i]) != 1) {
            printf("Erro ao ler os dados do arquivo %s!\n", nomeArquivo);
            free(vetor);
            fclose(arquivo);
            return NULL;
        }
    }

    fclose(arquivo);
    return vetor;
}
