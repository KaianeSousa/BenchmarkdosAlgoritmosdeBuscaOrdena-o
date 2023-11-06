#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para carregar números do arquivo para um array
void carregarNumeros(const char *nomeArquivo, int *numeros, int *quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int num;
    *quantidade = 0;

    while (fscanf(arquivo, "%d", &num) != EOF) {
        numeros[*quantidade] = num;
        (*quantidade)++;
    }

    fclose(arquivo);
}

// Função para realizar a busca linear
int buscaLinear(int *numeros, int quantidade, int chave) {
    for (int i = 0; i < quantidade; i++) {
        if (numeros[i] == chave) {
            return i;
        }
    }
    return -1; // Retornar -1 se não encontrado
}

// Função para realizar a busca sentinela
int buscaSentinela(int *numeros, int quantidade, int chave) {
    int last = numeros[quantidade - 1];
    numeros[quantidade - 1] = chave; // Sentinela
    int i = 0;
    
    while (numeros[i] != chave) {
        i++;
    }

    numeros[quantidade - 1] = last; // Restaura o último elemento

    if (i < quantidade - 1 || numeros[quantidade - 1] == chave) {
        return i;
    } else {
        return -1; // Retornar -1 se não encontrado
    }
}

// Função para realizar a busca binária
int buscaBinaria(int *numeros, int quantidade, int chave) {
    int esq = 0;
    int dir = quantidade - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;

        if (numeros[meio] == chave) {
            return meio;
        }

        if (numeros[meio] < chave) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }

    return -1; // Retornar -1 se não encontrado
}

int main() {
    char nomeArquivo[] = "numeros.txt";
    int numeros[1000]; // Assumindo um máximo de 1000 números
    int quantidade;
    carregarNumeros(nomeArquivo, numeros, &quantidade);

    int opcao;
    do {
        printf("\nMenu de Operações:\n");
        printf("1. Busca Linear\n");
        printf("2. Busca Sentinela\n");
        printf("3. Busca Binária\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int chave, pos;
                printf("\nDigite o número a ser buscado: ");
                scanf("%d", &chave);

                clock_t inicio, fim;
                inicio = clock();
                pos = buscaLinear(numeros, quantidade, chave);
                fim = clock();

                if (pos != -1) {
                    printf("Número encontrado na posição %d. Tempo: %f segundos.\n", pos, (double)(fim - inicio) / CLOCKS_PER_SEC);
                } else {
                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 2: {
                int chave, pos;
                printf("\nDigite o número a ser buscado: ");
                scanf("%d", &chave);

                clock_t inicio, fim;
                inicio = clock();
                pos = buscaSentinela(numeros, quantidade, chave);
                fim = clock();

                if (pos != -1) {
                    printf("Número encontrado na posição %d. Tempo: %f segundos.\n", pos, (double)(fim - inicio) / CLOCKS_PER_SEC);
                } else {
                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 3: {
                int chave, pos;
                printf("\nDigite o número a ser buscado: ");
                scanf("%d", &chave);

                // Antes de usar a busca binária, é necessário ordenar o array
                // Para manter o exemplo simples, você pode usar um algoritmo de ordenação aqui
                // (como Bubble Sort) antes de realizar a busca binária.

                // Em vez disso, você pode criar uma função de ordenação e chamar aqui.

                // Ordenar o array
                // bubbleSort(numeros, quantidade);

                // Realizar a busca binária
                clock_t inicio, fim;
                inicio = clock();
                pos = buscaBinaria(numeros, quantidade, chave);
                fim = clock();

                if (pos != -1) {
                    printf("Número encontrado na posição %d. Tempo: %f segundos.\n", pos, (double)(fim - inicio) / CLOCKS_PER_SEC);
                } else {
                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
