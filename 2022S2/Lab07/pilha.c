#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

p_pilha cria_pilha() {
    p_pilha P;
    P = malloc(sizeof(pilha)); //Aloca memória com o tamanho de "pilha".
    P->topo = 0; //Define o valor inicial do "topo" como "0".
    P->prox = NULL; //Define o valor inicial de "prox" como "NULL".
    return P; //Retorna "P".
}

void imprime_pilha(p_pilha P) { //Imprime a pilha começando pelo seu último nó.
    if(P->prox != NULL)
        imprime_pilha(P->prox);
    printf("%s", P->texto);
}

p_pilha aumenta_pilha(p_pilha p) { //Adiciona um novo nó no começo da lista ligada "p".
    p_pilha novo = cria_pilha();
    novo->prox = p;
    return novo;
}

p_pilha empilhar(p_pilha p, char frase[], int i, int fim, int N) {
    p_pilha novo = p;
    for(int j = 0; j < N; i++, j++) {
        if(i > 499) //Continua a contagem na posição 0 da lista circular.
            i = 0;
        if(novo->topo == 50) //Caso a pilha alcance o limite, é criado outro nó.
            novo = aumenta_pilha(novo);
        novo->texto[novo->topo] = frase[i]; //Copia a parte desejada da lista para a pilha.
        novo->topo++; //Aumenta o "topo" da pilha.
    }
    return novo;
}

p_pilha libera_primeiro_no(p_pilha no) { //Libera o primeiro nó da pilha.
    p_pilha novo = no->prox;
    free(no);
    return novo;
}

p_pilha desempilhar(p_pilha p, int N) {
    p_pilha novo = p;
    for(int i = 0; i < N; i++) {
        if(novo->topo == 0) //Caso esteja vazio, libera o primeiro nó da pilha.
            novo = libera_primeiro_no(novo);
        novo->topo--; //Diminui o "topo" da pilha.
        novo->texto[novo->topo] = '\0'; //Marca diretamente no "texto" o seu fim, para mais fácil impressão.
    }
    return novo; //Retorna a pilha "novo".
}

void libera_pilha(p_pilha P) { //Libera a pilha do último nó até o primeiro.
    if(P->prox != NULL)
        libera_pilha(P->prox);
    P = libera_primeiro_no(P);
}