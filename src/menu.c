#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"
#include "../include/vetor.h"
#include "../include/benchmark.h"

void visualizarAlgoritmos(void) {
    int opcao;

    do {
        printf("\n========================================\n");
        printf("          ALGORITMOS DISPONIVEIS\n");
        printf("========================================\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Selection Sort\n");
        printf("3 - Insertion Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Quick Sort\n");
        printf("6 - Heap Sort\n");
        printf("7 - Counting Sort\n");
        printf("8 - Radix Sort\n");
        printf("9 - Bucket Sort\n");
        printf("0 - Voltar\n");
        printf("\nEscolha um algoritmo: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            return;
        }

        switch (opcao) {
            case 1:
                printf("\n========== BUBBLE SORT ==========\n");
                printf("Compara elementos adjacentes e troca os que estao fora de ordem.\n");
                printf("A cada passagem, o maior elemento restante vai para o final.\n");
                printf("Melhor caso:       O(n^2) nesta implementacao\n");
                printf("Caso medio:        O(n^2)\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Espaco auxiliar:   O(1)\n");
                printf("Estabilidade:      Estavel\n");
                break;

            case 2:
                printf("\n========== SELECTION SORT ==========\n");
                printf("Procura o menor elemento da parte nao ordenada e o coloca na proxima posicao.\n");
                printf("Melhor caso:       O(n^2)\n");
                printf("Caso medio:        O(n^2)\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Espaco auxiliar:   O(1)\n");
                printf("Estabilidade:      Nao estavel\n");
                break;

            case 3:
                printf("\n========== INSERTION SORT ==========\n");
                printf("Insere cada elemento na posicao correta dentro da parte ja ordenada.\n");
                printf("Melhor caso:       O(n)\n");
                printf("Caso medio:        O(n^2)\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Espaco auxiliar:   O(1)\n");
                printf("Estabilidade:      Estavel\n");
                break;

            case 4:
                printf("\n========== MERGE SORT ==========\n");
                printf("Divide o vetor em partes menores e depois intercala as partes ordenadas.\n");
                printf("Melhor caso:       O(n log n)\n");
                printf("Caso medio:        O(n log n)\n");
                printf("Pior caso:         O(n log n)\n");
                printf("Espaco auxiliar:   O(n)\n");
                printf("Estabilidade:      Estavel\n");
                break;

            case 5:
                printf("\n========== QUICK SORT ==========\n");
                printf("Escolhe um pivo, separa os menores e maiores e ordena as partes recursivamente.\n");
                printf("Nesta implementacao, o pivo e sempre o ultimo elemento.\n");
                printf("Melhor caso:       O(n log n)\n");
                printf("Caso medio:        O(n log n)\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Pilha recursiva:   O(log n) medio; O(n) pior\n");
                printf("Estabilidade:      Nao estavel\n");
                break;

            case 6:
                printf("\n========== HEAP SORT ==========\n");
                printf("Organiza os dados em um Max-Heap e coloca repetidamente o maior elemento no final.\n");
                printf("Melhor caso:       O(n log n)\n");
                printf("Caso medio:        O(n log n)\n");
                printf("Pior caso:         O(n log n)\n");
                printf("Pilha auxiliar:    O(log n), pois heapify e recursiva\n");
                printf("Estabilidade:      Nao estavel\n");
                break;

            case 7:
                printf("\n========== COUNTING SORT ==========\n");
                printf("Conta quantas vezes cada valor aparece e reconstrui o vetor em ordem.\n");
                printf("Esta implementacao tambem aceita valores negativos.\n");
                printf("Melhor caso:       O(n + k)\n");
                printf("Caso medio:        O(n + k)\n");
                printf("Pior caso:         O(n + k)\n");
                printf("Espaco auxiliar:   O(k)\n");
                printf("Estabilidade:      Nao estavel nesta implementacao\n");
                printf("Onde k e a quantidade de valores possiveis entre o minimo e o maximo.\n");
                break;

            case 8:
                printf("\n========== RADIX SORT ==========\n");
                printf("Ordena os numeros por digitos, comecando pelo menos significativo.\n");
                printf("Esta implementacao trabalha com inteiros nao negativos e base 10.\n");
                printf("Melhor caso:       O(d * (n + b))\n");
                printf("Caso medio:        O(d * (n + b))\n");
                printf("Pior caso:         O(d * (n + b))\n");
                printf("Espaco auxiliar:   O(n + b)\n");
                printf("Estabilidade:      Estavel\n");
                printf("Onde d e a quantidade de digitos e b e a base numerica.\n");
                break;

            case 9:
                printf("\n========== BUCKET SORT ==========\n");
                printf("Distribui os valores em baldes, ordena cada balde e depois os combina.\n");
                printf("Nesta implementacao, a quantidade de baldes e igual a n.\n");
                printf("Caso esperado:     O(n + B), sob distribuicao adequada\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Espaco auxiliar:   O(n + B)\n");
                printf("Estabilidade:      Estavel nesta implementacao\n");
                printf("Onde B e a quantidade de baldes.\n");
                break;

            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);
}

void exibirMenu(void) {
    int opcao;

    do {
        printf("\n========================================\n");
        printf("       BENCHMARK DE ALGORITMOS\n");
        printf("========================================\n");
        printf("1 - Executar benchmark\n");
        printf("2 - Visualizar algoritmos\n");
        printf("3 - Gerar novos vetores\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            return;
        }

        switch (opcao) {
            case 1:
                Benchmark();
                break;
            case 2:
                visualizarAlgoritmos();
                break;
            case 3:
                gerarVetores();
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);
}
