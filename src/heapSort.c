#include <stdio.h>
#include <stddef.h>

void heapify(int vetor[], int tamanho, int raiz)
{
    int maior = raiz;
    int esquerda = 2 * raiz + 1;
    int direita = 2 * raiz + 2;
    int temp;

    if (esquerda < tamanho && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    if (direita < tamanho && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    if (maior != raiz) {

        temp = vetor[raiz];
        vetor[raiz] = vetor[maior];
        vetor[maior] = temp;

        heapify(vetor, tamanho, maior);
    }
}

void heapSort(int vetor[], int tamanho)
{
    int i, temp;

    if (vetor == NULL || tamanho <= 1) {
        return;
    }

    for (i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(vetor, tamanho, i);
    }

    for (i = tamanho - 1; i > 0; i--) {

        temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        heapify(vetor, i, 0);
    }
}