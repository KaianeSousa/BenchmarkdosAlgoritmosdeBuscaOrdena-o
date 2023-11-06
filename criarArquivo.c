#include <stdio.h>

int main(){
    
    int quantidade, numero;
    char nomeArquivo[] = "numeros.txt";
    FILE *arquivo = NULL; // Inicialize o ponteiro do arquivo como NULL

    printf("Quantos números inteiros você deseja adicionar ao arquivo? ");
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
                    printf("O número %d já existe. Digite outro número: ", numero);
                    i--; // Decrementa o contador para digitar um novo número
                    fclose(arquivo); // Fecha o arquivo apenas se ele foi aberto
                    arquivo = NULL; // Define o ponteiro do arquivo como NULL
                    break;
                }
            }
        }

        if(existe != numero){
            arquivo = fopen(nomeArquivo, "a");
            if(arquivo == NULL){
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }
                fprintf(arquivo, "%d\n", numero); // Escreve o número no arquivo
        }

        if(arquivo != NULL){
            fclose(arquivo); // Fecha o arquivo se ele estiver aberto
            arquivo = NULL; // Define o ponteiro do arquivo como NULL
        }
    }

    printf("Números foram adicionados ao arquivo 'numeros.txt'.\n");

    return 0;
}
