#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/vetor.h"

// Exibe o cat�logo de algoritmos
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
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("\n========== BUBBLE SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Compara elementos adjacentes do vetor e realiza trocas\n");
                printf("quando encontra valores fora de ordem. A cada passagem,\n");
                printf("o maior elemento ainda nao ordenado chega ao final da\n");
                printf("regiao analisada. O processo se repete ate que o vetor\n");
                printf("esteja completamente ordenado.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(n) - com otimizacao\n");
                printf("Caso medio:        O(n^2)\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Espaco auxiliar:   O(1)\n");

                printf("\nESTABILIDADE: Estavel\n");
                break;

            case 2:
                printf("\n========== SELECTION SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Percorre a parte nao ordenada do vetor procurando o\n");
                printf("menor elemento. Quando o encontra, troca sua posicao\n");
                printf("com o primeiro elemento da regiao nao ordenada.\n");
                printf("A cada repeticao, a regiao ordenada aumenta ate que\n");
                printf("todos os elementos estejam em suas posicoes corretas.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(n^2)\n");
                printf("Caso medio:        O(n^2)\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Espaco auxiliar:   O(1)\n");

                printf("\nESTABILIDADE: Nao estavel (implementacao tradicional)\n");
                break;

            case 3:
                printf("\n========== INSERTION SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Constroi gradualmente uma parte ordenada do vetor.\n");
                printf("Seleciona um elemento por vez e o compara com os\n");
                printf("elementos anteriores, deslocando os maiores para\n");
                printf("a direita ate encontrar a posicao correta para\n");
                printf("inseri-lo. Funciona de maneira semelhante a\n");
                printf("organizacao de cartas em uma mao.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(n)\n");
                printf("Caso medio:        O(n^2)\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Espaco auxiliar:   O(1)\n");

                printf("\nESTABILIDADE: Estavel\n");
                break;

            case 4:
                printf("\n========== MERGE SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Utiliza a estrategia de divisao e conquista.\n");
                printf("Divide o vetor repetidamente em partes menores\n");
                printf("ate que cada parte tenha apenas um elemento.\n");
                printf("Em seguida, combina essas partes de forma ordenada,\n");
                printf("comparando seus elementos ate reconstruir o vetor\n");
                printf("completamente ordenado.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(n log n)\n");
                printf("Caso medio:        O(n log n)\n");
                printf("Pior caso:         O(n log n)\n");
                printf("Espaco auxiliar:   O(n)\n");

                printf("\nESTABILIDADE: Estavel (implementacao tradicional)\n");
                break;

            case 5:
                printf("\n========== QUICK SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Utiliza a estrategia de divisao e conquista.\n");
                printf("Escolhe um elemento chamado pivo e reorganiza o\n");
                printf("vetor de modo que os elementos menores fiquem de\n");
                printf("um lado e os maiores do outro. Depois, aplica o\n");
                printf("mesmo processo recursivamente nas duas partes,\n");
                printf("ate que todo o vetor esteja ordenado.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(n log n)\n");
                printf("Caso medio:        O(n log n)\n");
                printf("Pior caso:         O(n^2)\n");
                printf("Espaco auxiliar:   Depende da recursao\n");

                printf("\nESTABILIDADE: Nao estavel (implementacao tradicional)\n");
                break;

            case 6:
                printf("\n========== HEAP SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Transforma o vetor em uma estrutura chamada Heap,\n");
                printf("normalmente um Max-Heap, na qual o maior elemento\n");
                printf("fica na raiz. Em seguida, troca a raiz com o ultimo\n");
                printf("elemento da regiao nao ordenada, reduz o tamanho\n");
                printf("do Heap e reorganiza sua estrutura. O processo se\n");
                printf("repete ate ordenar todos os elementos.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(n log n)\n");
                printf("Caso medio:        O(n log n)\n");
                printf("Pior caso:         O(n log n)\n");
                printf("Espaco auxiliar:   O(1) - implementacao iterativa\n");

                printf("\nESTABILIDADE: Nao estavel\n");
                break;

            case 7:
                printf("\n========== COUNTING SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Ordena os elementos contando quantas vezes cada\n");
                printf("valor aparece no vetor. Utiliza um vetor auxiliar\n");
                printf("de contagem para registrar as frequencias e, a\n");
                printf("partir dessas informacoes, determina as posicoes\n");
                printf("corretas dos elementos no vetor ordenado.\n");
                printf("E especialmente eficiente quando os valores estao\n");
                printf("dentro de um intervalo inteiro relativamente pequeno.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(n + k)\n");
                printf("Caso medio:        O(n + k)\n");
                printf("Pior caso:         O(n + k)\n");
                printf("Espaco auxiliar:   O(n + k)\n");

                printf("\nESTABILIDADE: Estavel (implementacao tradicional com\n");
                printf("               contagem acumulada e saida auxiliar)\n");
                printf("\nOnde k representa o intervalo de valores.\n");
                break;

            case 8:
                printf("\n========== RADIX SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Ordena os numeros analisando seus digitos, em vez\n");
                printf("de comparar diretamente os valores completos.\n");
                printf("Na implementacao LSD, comeca pelo digito menos\n");
                printf("significativo e avanca para os mais significativos.\n");
                printf("Em cada etapa, utiliza uma ordenacao estavel para\n");
                printf("agrupar os elementos conforme o digito analisado.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(d * (n + b))\n");
                printf("Caso medio:        O(d * (n + b))\n");
                printf("Pior caso:         O(d * (n + b))\n");
                printf("Espaco auxiliar:   O(n + b)\n");

                printf("\nESTABILIDADE: Estavel (implementacao LSD tradicional)\n");
                printf("\nOnde d representa a quantidade de digitos e b a\n");
                printf("base numerica utilizada.\n");
                break;

            case 9:
                printf("\n========== BUCKET SORT ==========\n");
                printf("\nDESCRICAO:\n");
                printf("Distribui os elementos em diferentes grupos chamados\n");
                printf("baldes (buckets), de acordo com seus valores.\n");
                printf("Cada balde e ordenado individualmente e, depois,\n");
                printf("os elementos sao reunidos na ordem dos baldes,\n");
                printf("formando o vetor completamente ordenado.\n");
                printf("Seu desempenho depende da distribuicao dos dados.\n");

                printf("\nCOMPLEXIDADE:\n");
                printf("Melhor caso:       O(n + k)\n");
                printf("Caso medio:        O(n + k), sob distribuicao uniforme\n");
                printf("Pior caso:         O(n^2), dependendo da ordenacao\n");
                printf("Espaco auxiliar:   O(n + k)\n");

                printf("\nESTABILIDADE: Depende da implementacao dos baldes\n");
                printf("\nOnde k representa a quantidade de baldes.\n");
                break;

            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);
}

// Exibe o menu principal
void exibirMenu(void) {
    int opcao;

    do {
        printf("\n========================================\n");
        printf("       BENCHMARK DE ALGORITMOS\n");
        printf("========================================\n");

        printf("1 - Executar benchmark\n");
        printf("2 - Consultar resultados\n");
        printf("3 - Visualizar algoritmos\n");
        printf("4 - Configuracoes do experimento\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nFuncionalidade em desenvolvimento.\n");
                break;

            case 2:
                printf("\nFuncionalidade em desenvolvimento.\n");
                break;

            case 3:
                visualizarAlgoritmos();
                break;

            case 4:
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

