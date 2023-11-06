#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função com as mains

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


int buscaLinear(int *numeros, int quantidade, int chave) {
    for (int i = 0; i < quantidade; i++) {
        if (numeros[i] == chave) {
            return i;
        }
    }
    return -1;
}

int buscaSentinela(int *numeros, int quantidade, int chave) {
    int last = numeros[quantidade - 1];
    numeros[quantidade - 1] = chave; 
    int i = 0;

    while (numeros[i] != chave) {
        i++;
    }

    numeros[quantidade - 1] = last;

    if (i < quantidade - 1 || numeros[quantidade - 1] == chave) {
        return i;
    } else {
        return -1; 
    }
}


int buscaBinaria(int *numeros, int quantidade, int chave) {
    int esquerda = 0;
    int direita = quantidade - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (numeros[meio] == chave) {
            return meio;
        }

        if (numeros[meio] < chave) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1;
}


void bubbleSort(int *numeros, int quantidade) {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {

                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

int particionar(int *numeros, int esquerda, int direita) {
    int pivo = numeros[direita];
    int i = esquerda - 1;

    for (int j = esquerda; j < direita; j++) {
        if (numeros[j] <= pivo) {
            i++;

            int temp = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = temp;
        }
    }

    int temp = numeros[i + 1];
    numeros[i + 1] = numeros[direita];
    numeros[direita] = temp;

    return i + 1;
}

void quickSort(int *numeros, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = particionar(numeros, esquerda, direita);
        quickSort(numeros, esquerda, pivo - 1);
        quickSort(numeros, pivo + 1, direita);
    }
}

void insertionSort(int *numeros, int quantidade) {
    for (int i = 1; i < quantidade; i++) {
        int chave = numeros[i];
        int j = i - 1;

        while (j >= 0 && numeros[j] > chave) {
            numeros[j + 1] = numeros[j];
            j--;
        }

        numeros[j + 1] = chave;
    }
}

int main() {
    char nomeArquivo[] = "numeros.txt";
    int numeros[1000]; 
    int quantidade;
    carregarNumeros(nomeArquivo, numeros, &quantidade);

    int opcao;
    do {
        printf("\nMenu de Operações:\n");
        printf("1. Busca Linear\n");
        printf("2. Busca Sentinela\n");
        printf("3. Busca Binária\n");
        printf("4. Ordenar com Bubble Sort\n");
        printf("5. Ordenar com Quick Sort\n");
        printf("6. Ordenar com Insertion Sort\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: { 
                int chave;
                printf("Digite o número que deseja buscar: ");
                scanf("%d", &chave);
                int posicao = buscaLinear(numeros, quantidade, chave);
                if (posicao != -1) {
                    printf("Número encontrado na posição %d.\n", posicao);
                } else {
                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 2: { 
                int chave;
                printf("Digite o número que deseja buscar: ");
                scanf("%d", &chave);
                int posicao = buscaSentinela(numeros, quantidade, chave);
                if (posicao != -1) {
                    printf("Número encontrado na posição %d.\n", posicao);
                } else {
                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 3: { 
                int chave;
                printf("Digite o número que deseja buscar: ");
                scanf("%d", &chave);
                int posicao = buscaBinaria(numeros, quantidade, chave);
                if (posicao != -1) {
                    printf("Número encontrado na posição %d.\n", posicao);
                } else {
                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 4: { /
                clock_t inicio, fim;
                inicio = clock();
                bubbleSort(numeros, quantidade);
                fim = clock();
                printf("Números ordenados com Bubble Sort. Tempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;

            case 5: { 
                clock_t inicio, fim;
                inicio = clock();
                quickSort(numeros, 0, quantidade - 1); 
                fim = clock();
                printf("Números ordenados com Quick Sort. Tempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;

            case 6: { 
                clock_t inicio, fim;
                inicio = clock();
                insertionSort(numeros, quantidade); 
                fim = clock();
                printf("Números ordenados com Insertion Sort. Tempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
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


//sem main


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int buscaLinear(int *numeros, int quantidade, int chave) {
    for (int i = 0; i < quantidade; i++) {
        if (numeros[i] == chave) {
            return i;
        }
    }
    return -1; 
}


int buscaSentinela(int *numeros, int quantidade, int chave) {
    int last = numeros[quantidade - 1];
    numeros[quantidade - 1] = chave;
    int i = 0;

    while (numeros[i] != chave) {
        i++;
    }

    numeros[quantidade - 1] = last;

    if (i < quantidade - 1 || numeros[quantidade - 1] == chave) {
        return i;
    } else {
        return -1; 
    }
}

int buscaBinaria(int *numeros, int quantidade, int chave) {
    int esquerda = 0;
    int direita = quantidade - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (numeros[meio] == chave) {
            return meio;
        }

        if (numeros[meio] < chave) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1; 
}

void bubbleSort(int *numeros, int quantidade) {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
             
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

int particionar(int *numeros, int esquerda, int direita) {
    int pivo = numeros[direita];
    int i = esquerda - 1;

    for (int j = esquerda; j < direita; j++) {
        if (numeros[j] <= pivo) {
            i++;
 
            int temp = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = temp;
        }
    }

    int temp = numeros[i + 1];
    numeros[i + 1] = numeros[direita];
    numeros[direita] = temp;

    return i + 1;
}


void quickSort(int *numeros, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = particionar(numeros, esquerda, direita);
        quickSort(numeros, esquerda, pivo - 1);
        quickSort(numeros, pivo + 1, direita);
    }
}

void insertionSort(int *numeros, int quantidade) {
    for (int i = 1; i < quantidade; i++) {
        int chave = numeros[i];
        int j = i - 1;

        while (j >= 0 && numeros[j] > chave) {
            numeros[j + 1] = numeros[j];
            j--;
        }

        numeros[j + 1] = chave;
    }
}
