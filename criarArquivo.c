#include <stdio.h>

//Com Main
int main(){
    
    int quantidade, numero;
    char nomeArquivo[] = "numeros.txt";
    FILE *arquivo = NULL;
    printf("Informe a quantidade de números que deseja adicionar ao arquivo:\n ");
    scanf("%d", &quantidade);

    printf("Digite os números (um por linha):\n");

    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &numero);

        arquivo = fopen(nomeArquivo, "r");
        int existe = 0;
        int numLido;

        if(arquivo != NULL){
            while(fscanf(arquivo, "%d", &numLido) != EOF){
                if(numLido == numero){
                    printf("\nO número %d já existe. Digite outro: ", numero);
                    i--; 
                    fclose(arquivo); 
                    arquivo = NULL; 
                    break;
                }
            }
        }

        if(existe != numero){
            arquivo = fopen(nomeArquivo, "a");
            if(arquivo == NULL){
                printf("Erro! Não foi possível abrir o arquivo.\n");
                return 1;
            }
                fprintf(arquivo, "%d\n", numero); 
        }

        if(arquivo != NULL){
            fclose(arquivo); 
            arquivo = NULL; 
        }
    }

    printf("Números foram adicionados ao arquivo 'numeros.txt'.\n");

    return 0;
}

//Sem main

#include <stdio.h>

void adicionarNumerosArquivo(const char *nomeArquivo) {
    int quantidade, numero;
    FILE *arquivo = NULL;
  
    printf("Informe a quantidade de números que deseja adicionar ao arquivo:\n ");
    scanf("%d", &quantidade);

    printf("Digite os números (um por linha):\n");

    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &numero);

        arquivo = fopen(nomeArquivo, "r");
        int existe = 0;
        int numLido;

        if (arquivo != NULL) {
            while (fscanf(arquivo, "%d", &numLido) != EOF) {
                if (numLido == numero) {
                    printf("\nO número %d já existe. Digite outro: ", numero);
                    i--; 
                    fclose(arquivo);
                    arquivo = NULL; 
                    break;
                }
            }
        }

        if (existe != numero) {
            arquivo = fopen(nomeArquivo, "a");
            if (arquivo == NULL) {
                printf("Erro! Não foi possível abrir o arquivo.\n");
                return;
            }
            fprintf(arquivo, "%d\n", numero); 
        }

        if (arquivo != NULL) {
            fclose(arquivo);
            arquivo = NULL;
        }
    }

    printf("Números foram adicionados ao arquivo '%s'.\n", nomeArquivo);
}
