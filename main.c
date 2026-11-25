
#include <stdio.h>
#include "matrizes.h"

int main() {

    Matriz A = {0};
    Matriz B = {0};
    Matriz resultado = {0};

    int opcao;
    int cadastradas = 0;

    do {

        printf("\n====================================\n");
        printf("       CALCULADORA DE MATRIZES\n");
        printf("====================================\n");

        printf("1 - Cadastrar matrizes\n");
        printf("2 - Somar matrizes\n");
        printf("3 - Subtrair matrizes\n");
        printf("4 - Multiplicar matrizes\n");
        printf("5 - Dividir matrizes\n");
        printf("6 - Exibir matrizes\n");
        printf("0 - Encerrar programa\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("\nCADASTRO DA MATRIZ A\n");
                cadastrarMatriz(&A);

                if (A.linhas == 0) {
                    cadastradas = 0;
                    break;
                }

                printf("\nCADASTRO DA MATRIZ B\n");
                cadastrarMatriz(&B);

                if (B.linhas == 0) {
                    cadastradas = 0;
                    break;
                }

                cadastradas = 1;

                printf("\nMatrizes cadastradas!\n");
                break;

            case 2:

                if (!cadastradas) {
                    printf("\nCadastre as matrizes primeiro!\n");
                    break;
                }

                if (somarMatrizes(A, B, &resultado)) {
                    printf("\nRESULTADO DA SOMA:\n");
                    exibirMatriz(resultado);
                }

                break;

            case 3:

                if (!cadastradas) {
                    printf("\nCadastre as matrizes primeiro!\n");
                    break;
                }

                if (subtrairMatrizes(A, B, &resultado)) {
                    printf("\nRESULTADO DA SUBTRACAO:\n");
                    exibirMatriz(resultado);
                }

                break;

            case 4:

                if (!cadastradas) {
                    printf("\nCadastre as matrizes primeiro!\n");
                    break;
                }

                if (multiplicarMatrizes(A, B, &resultado)) {
                    printf("\nRESULTADO DA MULTIPLICACAO:\n");
                    exibirMatriz(resultado);
                }

                break;

            case 5:

                if (!cadastradas) {
                    printf("\nCadastre as matrizes primeiro!\n");
                    break;
                }

                if (dividirMatrizes(A, B, &resultado)) {
                    printf("\nRESULTADO DA DIVISAO:\n");
                    exibirMatriz(resultado);
                }

                break;

            case 6:

                if (!cadastradas) {
                    printf("\nCadastre as matrizes primeiro!\n");
                    break;
                }

                printf("\nMATRIZ A:\n");
                exibirMatriz(A);

                printf("\nMATRIZ B:\n");
                exibirMatriz(B);

                break;

            case 0:

                printf("\nPrograma encerrado!\n");
                break;

            default:

                printf("\nOpcao invalida! Tente novamente.\n");

        }

    } while (opcao != 0);

    return 0;
}
