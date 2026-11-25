
#include <stdio.h>
#include "matrizes.h"

void cadastrarMatriz(Matriz *matriz) {

    printf("\nDigite a quantidade de linhas (1 a 50): ");
    scanf("%d", &matriz->linhas);

    printf("Digite a quantidade de colunas (1 a 50): ");
    scanf("%d", &matriz->colunas);

    if (matriz->linhas < 1 || matriz->linhas > 50 ||
        matriz->colunas < 1 || matriz->colunas > 50) {

        printf("Dimensoes invalidas!\n");
        matriz->linhas = 0;
        matriz->colunas = 0;
        return;
    }

    printf("\nDigite os elementos da matriz:\n");

    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matriz->dados[i][j]);
        }
    }

    printf("\nMatriz cadastrada com sucesso!\n");
}

void exibirMatriz(Matriz matriz) {

    if (matriz.linhas == 0 || matriz.colunas == 0) {
        printf("Matriz nao cadastrada.\n");
        return;
    }

    printf("\nResultado da matriz:\n");

    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            printf("%8.2lf ", matriz.dados[i][j]);
        }
        printf("\n");
    }
}

// SOMA DE MATRIZES
int somarMatrizes(Matriz a, Matriz b, Matriz *resultado) {

    if (a.linhas != b.linhas ||
        a.colunas != b.colunas) {

        printf("\nErro: dimensoes diferentes!\n");
        return 0;
    }

    resultado->linhas = a.linhas;
    resultado->colunas = a.colunas;

    for (int i = 0; i < a.linhas; i++) {
        for (int j = 0; j < a.colunas; j++) {

            resultado->dados[i][j] =
                a.dados[i][j] + b.dados[i][j];

        }
    }

    return 1;
}

// SUBTRACAO DE MATRIZES
int subtrairMatrizes(Matriz a, Matriz b, Matriz *resultado) {

    if (a.linhas != b.linhas ||
        a.colunas != b.colunas) {

        printf("\nErro: dimensoes diferentes!\n");
        return 0;
    }

    resultado->linhas = a.linhas;
    resultado->colunas = a.colunas;

    for (int i = 0; i < a.linhas; i++) {
        for (int j = 0; j < a.colunas; j++) {

            resultado->dados[i][j] =
                a.dados[i][j] - b.dados[i][j];

        }
    }

    return 1;
}
