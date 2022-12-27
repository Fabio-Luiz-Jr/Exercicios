#include <stdio.h>
#include <stdlib.h>
#include "cobra.h"

void imprime(int **Matriz, int M, int N, int resultado) {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(Matriz[i][j] == -1)
                printf("* "); //Imprime a fruta.
            else if(Matriz[i][j] == 0)
                printf("_ "); //Imprime uma casa branca.
            else
                printf("# "); //Imprime a cobra.
        }
        printf("\n");
    }
    printf("\n");
    if(resultado == 1) //O jogador perdeu.
        printf("GAME OVER\n");
    else if(resultado == 2) //O jogador ganhou.
        printf("YOU WIN\n");
}

p_no criar_lista () {
    return NULL;
}

void destruir_lista(p_no lista) {
    if(lista != NULL) {
        destruir_lista(lista ->ant);
    free(lista);
    }
}

p_no adicionar_elemento (p_no lista , int X, int Y) {
    p_no novo;
    novo = malloc(sizeof(struct no));
    novo->x = X;
    novo->y = Y;
    if(lista != NULL){
        lista->prox = novo;
        novo->ant = lista;
    }
    return novo;
}

int **cria_matriz(int M, int N) {
    int **Matriz;
    Matriz = malloc(M * sizeof(int *));
    for(int i = 0; i < M; i++) {
        Matriz[i] = malloc(N * sizeof(int));
        for(int j = 0; j < N; j++)
            Matriz[i][j] = 0;
        }
    return Matriz;
}

void destruir_matriz(int **Matriz, int M) {
    for(int i = 0; i < M; i++)
        free(Matriz[i]);
    free(Matriz);
}

void insere_fruta(int **Matriz, int X, int Y) {
    Matriz[X][Y] = -1;
}

void insere_cobra(int **Matriz, int A, int B) {
    Matriz[A][B] = 1;
}

void calcula_movimento(int **Matriz, int M, int N, int *X, int *Y, char movimento) {
    if(movimento == 'w') {
        (*X)--;
        if(*X < 0)
            *X = M - 1;
        } else if(movimento == 'a') {
        (*Y)--;
        if(*Y < 0)
            *Y = N - 1;
        } else if(movimento == 's') {
        (*X)++;
            if(*X == M)
                *X = 0;
        } else {
        (*Y)++;
        if(*Y == N)
            *Y = 0;
        }
} //Define para qual coordenada a cobra deve ir com base no movimento lido.

int decide_acao(int **Matriz, int X, int Y) {
    if(Matriz[X][Y] == -1)
        return -1; //Encontrou uma fruta.
    else if(Matriz[X][Y] == 0)
        return 0; //Encontrou uma casa branca.
    return 1; //A cobra bateu nela mesma.
}

void mover(int **Matriz, p_no cobra, int novo_x, int novo_y) {
    Matriz[cobra->x][cobra->y] = 0;
    if(cobra->ant != NULL)
        mover(Matriz, cobra->ant, -1, -1);
    if(novo_x == -1){
        cobra->x = cobra->prox->x;
        cobra->y = cobra->prox->y;
    } else {
        cobra->x = novo_x;
        cobra->y = novo_y;
    }
    Matriz[cobra->x][cobra->y] = 1;
} //Move a cabeça e o resto do corpo a segue.

p_no aumenta_cobra(int **Matriz, p_no cobra, int novo_x, int novo_y) {
    p_no novo;
    novo = adicionar_elemento(cobra, novo_x, novo_y); //Adiciona uma nova cauda no final da cauda antiga.
    Matriz[novo->x][novo->y] = 1;
    return novo;
}