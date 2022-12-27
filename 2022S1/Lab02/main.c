#include <stdio.h>
#define MAX 1000

int procura(int s, int matriz[MAX][MAX], int linha, int coluna, int M){
    /*Procura a menor submatriz que satisfaz os requisitos*/
    int i, j, soma = 0;
    for(i = linha; i <= linha + M; i++)
        for(j = coluna; j <= coluna + M; j++)
            soma += matriz[i][j];
    /*Soma todos os elementos da submatriz*/
    if(soma == s)
        return 1;
    /*Retorna '1' caso a soma dos elementos da submatriz seja igual a variável s*/
    return 0;
}

int main() {
    int i, j, n, m, s, matriz[MAX][MAX], encontrou = 0, linha, coluna, M;
    scanf("%d %d %d", &n, &m, &s);
    /*Le n, m e s*/
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &matriz[i][j]);
    /*Le a matriz*/
    for(M = 0; M <= m && encontrou == 0; M++)
        for(linha = 0; linha < n && encontrou == 0; linha++)
            for(coluna = 0; coluna < m && encontrou == 0; coluna++)
                encontrou = procura(s, matriz, linha, coluna, M);
    /*Procura por toda submatriz possível*/
    if(encontrou == 1)
        printf("submatriz %d x %d em [%d,%d]\n", M, M, linha, coluna);
    /*Imprime esta mensagem caso encontrar uma submatriz que satisfaz os requisitos*/
    else
        printf("nao ha'\n");
    /*Imprime esta mensagem caso não encontre*/
    return 0;
}