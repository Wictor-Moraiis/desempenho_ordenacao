
# Analise comparativa de algoritmos de ordenacao

Projeto em C que implementa e compara nove algoritmos de ordenacao: Bubble, Selection, Insertion, Merge, Quick, Heap, Counting, Radix e Bucket Sort.

## Compilacao no macOS

O projeto utiliza o Apple Clang e o GNU Make. Na pasta principal do repositorio, execute:

```bash
make clean
make
```

O comando gera o executavel `desempenho_ordenacao`.

Para iniciar o programa:

```bash
./desempenho_ordenacao
```

Para remover o executavel:

```bash
make clean
```

## Compilacao no Windows

No Windows, utilizando MinGW/GCC e GNU Make, execute:

```bash
make -f Makefile.win
```

O comando gera o executavel `desempenho_ordenacao.exe`.

## Validacao dos resultados

Antes das medicoes, o benchmark cria uma copia do vetor original e ordena essa copia com `qsort()`. Depois de medir cada algoritmo, compara o vetor produzido com a referencia. A criacao da referencia e a validacao ficam fora do intervalo medido.

## Vetores de entrada

Os arquivos `vetor_1.txt` ate `vetor_6.txt` ficam na pasta principal. A opcao 3 do menu gera novos arquivos. A geracao informa a faixa permitida, o minimo e o maximo observados e o valor de K observado em cada arquivo.

**Atencao:** gerar novos vetores altera as entradas do experimento. Se os vetores forem regenerados, todas as medicoes devem ser refeitas para que as tabelas e os graficos representem os novos dados.

## Ambiente e opcoes de compilacao

No macOS, o projeto utiliza Apple Clang com as opcoes `-std=c11 -Wall -Wextra -Iinclude`. O Makefile nao define um nivel explicito de otimizacao (`-O0`, `-O1`, `-O2` ou `-O3`), portanto, o compilador utiliza seu nivel padrao. Para reproduzir os tempos, registre a versao do compilador e mantenha as mesmas opcoes em todas as execucoes.
