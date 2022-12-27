#include <stdio.h>
#include <string.h>
#define MAX_MTZ 99
#define MAX_CMD 17
#define MAX_OP 11

void cria_a_b(int A[][MAX_MTZ], int B[][MAX_MTZ], int N) {
    int i, j;
    for(j = 0; j < N; j++)
        for(i = 0; i < N; i++)
            /*Cria colunas intercaladas com 1 e 0 respectivamente nas matrizes A e B*/
            if((j / 3) % 2 != 0)
                A[i][j] = B[i][j] = 0;
            else
                A[i][j] = B[i][j] = 1;
}

void imprime(int matriz[][MAX_MTZ], int N) {
    printf("\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

void transposta(int x[][MAX_MTZ], int y[][MAX_MTZ], int N) {
    int aux[MAX_MTZ][MAX_MTZ], i, j;
    for(i = 0; i < N; i++)
        /*Copia a matriz x na matriz aux com as coordenadas invertidas*/
        for(j = 0; j < N; j++)
            aux[j][i] = x[i][j];
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            y[i][j] = aux[i][j];
    imprime(y, N);
}

void soma(int x[][MAX_MTZ], int y[][MAX_MTZ], int z[][MAX_MTZ], int N) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            /*Para evitar fazer contas de adição e subtração ele define em z[i][j] o valor 1 se
            x[i][j] ou y[i][j] forem 1*/
            if(x[i][j] == 1 || y[i][j] == 1)
                z[i][j] = 1;
            else
                z[i][j] = 0;
    imprime(z, N);
}

void multi_elem(int x[][MAX_MTZ], int y[][MAX_MTZ], int z[][MAX_MTZ], int N) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            z[i][j] = x[i][j] * y[i][j];
    imprime(z, N);
}

void multi_mat(int x[][MAX_MTZ], int y[][MAX_MTZ], int z[][MAX_MTZ], int N) {
    int aux[MAX_MTZ][MAX_MTZ], i, j, k, mult;
    /*Caso o 1º for() não existisse o cálculo seria feito apenas na primeira fileira da matriz aux*/
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++) {
            mult = 0;
            for(k = 0; k < N; k++) {
                mult += x[j][k] * y[k][j];
                if(mult == 1)
                    break;
            }
            aux[i][j] = mult;
        }
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            z[i][j] = aux[i][j];
    imprime(z, N);
}

void bordas(int x[][MAX_MTZ], int y[][MAX_MTZ], int N) {
    int aux[MAX_MTZ][MAX_MTZ], i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            /*Ele procura em um quadrado 3x3 se suas quatro bordas equivalem a 1, se for ele define
            o ponto do meio como 0, caso contrário, 1*/
            if((i == 0) || (i == N - 1) || (j == 0) || (j == N - 1))
                aux[i][j] = x[i][j];
            else if((x[i - 1][j - 1] == 1) && (x[i - 1][j + 1] == 1) && (x[i + 1][j - 1] == 1) && (x[i + 1][j + 1] == 1))
                aux[i][j] = 0;
            else
                aux[i][j] = x[i][j];
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            y[i][j] = aux[i][j];
    imprime(y, N);
}

int main() {
    int N, O, A[MAX_MTZ][MAX_MTZ], B[MAX_MTZ][MAX_MTZ];
    char  operacao[MAX_OP], X, Y, Z = 0;
    scanf("%d %d", &N, &O);
    cria_a_b(A, B, N);
    for(int i = 0; i < O; i++) {
        scanf(" %s %c %c", operacao, &X, &Y);
        if(strcmp(operacao, "SOMA") == 0 || strcmp(operacao, "MULTI_ELEM") == 0 
        || strcmp(operacao, "MULTI_MAT") == 0)
            /*Lê a variavel Z se vier ao acaso*/
            scanf(" %c", &Z);
        /*Escolhe qual operação fazer e em seguida, quais matrizes devem entrar nas funções
        a partir das variáveis X, Y e Z*/
        if(strcmp(operacao, "TRANSPOSTA") == 0) {
            if(X == 'A')
                if(Y == 'A')
                    transposta(A, A, N);
                else
                    transposta(A, B, N);
            else
                if(Y == 'A')
                    transposta(B, A, N);
                else
                    transposta(B, B, N);
        } else if(strcmp(operacao, "SOMA") == 0) {
            if(X == 'A')
                if(Y == 'A')
                    if(Z == 'A')
                        soma(A, A, A, N);
                    else
                        soma(A, A, B, N);
                else
                    if(Z == 'A')
                        soma(A, B, A, N);
                    else
                        soma(A, B, B, N);
            else
                if(Y == 'A')
                    if(Z == 'A')
                        soma(B, A, A, N);
                    else
                        soma(B, A, B, N);
                else
                    if(Z == 'A')
                        soma(B, B, A, N);
                    else
                        soma(B, B, B, N);
        } else if(strcmp(operacao, "MULTI_ELEM") == 0) {
            if(X == 'A')
                if(Y == 'A')
                    if(Z == 'A')
                        multi_elem(A, A, A, N);
                    else
                        multi_elem(A, A, B, N);
                else
                    if(Z == 'A')
                        multi_elem(A, B, A, N);
                    else
                        multi_elem(A, B, B, N);
            else
                if(Y == 'A')
                    if(Z == 'A')
                        multi_elem(B, A, A, N);
                    else
                        multi_elem(B, A, B, N);
                else
                    if(Z == 'A')
                        multi_elem(B, B, A, N);
                    else
                        multi_elem(B, B, B, N);
        } else if(strcmp(operacao, "MULTI_MAT") == 0) {
            if(X == 'A')
                if(Y == 'A')
                    if(Z == 'A')
                        multi_mat(A, A, A, N);
                    else
                        multi_mat(A, A, B, N);
                else
                    if(Z == 'A')
                        multi_mat(A, B, A, N);
                    else
                        multi_mat(A, B, B, N);
            else
                if(Y == 'A')
                    if(Z == 'A')
                        multi_mat(B, A, A, N);
                    else
                        multi_mat(B, A, B, N);
                else
                    if(Z == 'A')
                        multi_mat(B, B, A, N);
                    else
                        multi_mat(B, B, B, N);
        } else {
            if(X == 'A')
                if(Y == 'A')
                    bordas(A, A, N);
                else
                    bordas(A, B, N);
            else
                if(Y == 'A')
                    bordas(B, A, N);
                else
                    bordas(B, B, N);
        }
    }
    return 0;
}