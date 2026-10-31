#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarVetor(int tamanho, int faixa, char nomeArquivo[30])
{
	int i;
	printf("Tamanho: %d | Faixa: %d\n", tamanho, faixa);

	if (tamanho <= 0 || faixa <= 0)
	{
		printf("Valores invalidos!\n");
		return 1;
	}

	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "w");

	if (arquivo == NULL)
	{
		printf("Erro ao criar o arquivo!\n");
		return 1;
	}

	int vetor[tamanho];

	for (i = 0; i < tamanho; i++)
	{
		vetor[i] = rand() % (faixa + 1);
		fprintf(arquivo, "%d\n", vetor[i]);
	}
	fclose(arquivo);

	return 0;
}

void gerarVetores()
{
	char nomeArquivo[30];
	int tamanhos[6] = {100, 1000, 5000, 10000, 50000, 100000};
	int faixas[6] = {100, 1000, 5000, 10000, 50000, 100000};
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		sprintf(nomeArquivo, "vetor_%i.txt", i + 1);
		gerarVetor(tamanhos[i], faixas[i], nomeArquivo);
	}
}

int *carregarVetor(char nomeArquivo[], int tamanho)
{

	FILE *arquivo;
	int *vetor;
	int i;

	vetor = malloc(tamanho * sizeof(int));

	if (vetor == NULL)
	{
		printf("Erro ao alocar memoria!\n");
		return NULL;
	}

	arquivo = fopen(nomeArquivo, "r");

	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");

		free(vetor);
		return NULL;
	}

	for (i = 0; i < tamanho; i++)
	{
		if (fscanf(arquivo, "%d", &vetor[i]) != 1)
		{
			printf("Erro ao ler os dados do arquivo!\n");

			free(vetor);
			fclose(arquivo);

			return NULL;
		}
	}

	fclose(arquivo);

	return vetor;
}