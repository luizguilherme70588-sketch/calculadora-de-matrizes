
#include <stdio.h>

int main() {
    int opcao;

    printf("=================================\n");
    printf("    CALCULADORA DE MATRIZES\n");
    printf("=================================\n");

    do {
        printf("\n1 - Cadastrar matrizes\n");
        printf("2 - Somar matrizes\n");
        printf("3 - Subtrair matrizes\n");
        printf("4 - Multiplicar matrizes\n");
        printf("5 - Dividir matrizes\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Cadastro de matrizes.\n");
                break;
            case 2:
                printf("Opcao de soma selecionada.\n");
                break;
            case 3:
                printf("Opcao de subtracao selecionada.\n");
                break;
            case 4:
                printf("Opcao de multiplicacao selecionada.\n");
                break;
            case 5:
                printf("Opcao de divisao selecionada.\n");
                break;
            case 0:
                printf("Programa encerrado!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
