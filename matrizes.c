
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

// MULTIPLICACAO DE MATRIZES
int multiplicarMatrizes(Matriz a, Matriz b, Matriz *resultado) {

    if (a.colunas != b.linhas) {

        printf("\nErro: nao e possivel multiplicar essas matrizes!\n");
        printf("Colunas da primeira devem ser iguais as linhas da segunda.\n");

        return 0;
    }

    resultado->linhas = a.linhas;
    resultado->colunas = b.colunas;

    for (int i = 0; i < resultado->linhas; i++) {

        for (int j = 0; j < resultado->colunas; j++) {

            resultado->dados[i][j] = 0;

            for (int k = 0; k < a.colunas; k++) {

                resultado->dados[i][j] +=
                    a.dados[i][k] * b.dados[k][j];

            }
        }
    }

    return 1;
}

#include <math.h>

// CALCULO DA MATRIZ INVERSA
int inverterMatriz(Matriz original, Matriz *inversa) {

    if (original.linhas != original.colunas) {
        printf("\nErro: a matriz precisa ser quadrada!\n");
        return 0;
    }

    int n = original.linhas;
    double auxiliar[50][100];

    // Monta a matriz aumentada [A | I]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auxiliar[i][j] = original.dados[i][j];
            auxiliar[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Metodo de Gauss-Jordan com pivoteamento
    for (int i = 0; i < n; i++) {

        int pivo = i;

        for (int k = i + 1; k < n; k++) {
            if (fabs(auxiliar[k][i]) >
                fabs(auxiliar[pivo][i])) {
                pivo = k;
            }
        }

        if (fabs(auxiliar[pivo][i]) < 1e-10) {
            printf("\nErro: matriz sem inversa!\n");
            return 0;
        }

        // Troca as linhas
        if (pivo != i) {
            for (int j = 0; j < 2 * n; j++) {
                double temp = auxiliar[i][j];
                auxiliar[i][j] = auxiliar[pivo][j];
                auxiliar[pivo][j] = temp;
            }
        }

        // Transforma o pivo em 1
        double divisor = auxiliar[i][i];

        for (int j = 0; j < 2 * n; j++) {
            auxiliar[i][j] /= divisor;
        }

        // Zera os outros elementos da coluna
        for (int k = 0; k < n; k++) {

            if (k != i) {

                double fator = auxiliar[k][i];

                for (int j = 0; j < 2 * n; j++) {
                    auxiliar[k][j] -=
                        fator * auxiliar[i][j];
                }
            }
        }
    }

    inversa->linhas = n;
    inversa->colunas = n;

    // Copia o resultado da inversa
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inversa->dados[i][j] = auxiliar[i][j + n];
        }
    }

    return 1;
}

// DIVISAO DE MATRIZES
int dividirMatrizes(Matriz a, Matriz b, Matriz *resultado) {

    Matriz inversa;

    if (b.linhas != b.colunas) {
        printf("\nErro: a matriz divisora precisa ser quadrada!\n");
        return 0;
    }

    if (a.colunas != b.linhas) {
        printf("\nErro: dimensoes incompatíveis para divisao!\n");
        return 0;
    }

    if (!inverterMatriz(b, &inversa)) {
        return 0;
    }

    return multiplicarMatrizes(a, inversa, resultado);
}

