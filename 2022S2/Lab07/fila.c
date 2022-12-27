#include <stdio.h>
#include <string.h>
#include "fila.h"
#define MAX_FILA_C 500 //Define a quantidade máxima de caracteres que cabem na fila.

void imprime_fila(fila f) {
    printf("FILA ATUAL: ");
    for(int i = f.ini; i != f.fim; i++) { //Imprime a fila caracter por caracter.
        if(i > 499)
            i = 0;
        printf("%c", f.texto[i]);
    }
    printf("\n");
}

void cria_fila(fila *f) { //Define os valores iniciais da fila.
    f->ini = 0; //Define o inicio da fila.
    f->fim = 0; //Define o final da fila.
    f->tamanho = 0; //Define o tamanho da fila.
}

void enfileira(fila *f, char frase[]) { //Adiciona caracteres a fila e atualiza seu tamanho e final.
    for(int i = 0; i < strlen(frase); i++) {
        f->texto[f->fim] = frase[i]; //Copia caracter por caracter para a fila.
        f->fim = (f->fim + 1) % MAX_FILA_C; //Atualiza o final da fila.
        f->tamanho++; //Aumenta o tamanho da fila.
    }
}

void desenfileira(fila *f, int N) { //Atualiza o inicio da fila e seu tamanho.
    for(int i = 0; i < N; i++) {
        f->ini = (f->ini + 1) % MAX_FILA_C; //Atualiza o inicio da fila.
        f->tamanho--; //Diminui o tamanho da fila.
        }
}