#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define MAX 2129 //"MAX" é um número primo distante de 2 exponencial e maior que "N".
#define PRIMO 1151 //"PRIMO" é um número primo menor que "MAX".

void Imprime(char *id){
    printf("PROCESSO %s INSERIDO!\n", id);
}

p_no criar_no(){
    p_no novo;
    novo = malloc(sizeof(struct no));
    return novo;
}

p_hash criar_hash(){
    p_hash novo;
    novo = malloc(sizeof(struct hash));
    return novo;
}

int hash1(char *id){ //Função para o primeiro hash.
    int i, n = 0;
    for (i = 0; i < strlen(id); i++)
        n = (256 * n + id[i]) % MAX;
    return n;
}

int hash2(char *id){ //Função para o segundo hash.
    int i, n = 0;
    for (i = 0; i < strlen(id); i++)
        n = (256 * n + id[i]) % PRIMO;
    return PRIMO - n;
}

void destruir_no(p_no lista){
    if(lista->prox != NULL)
        destruir_no(lista->prox);
    free(lista);
}

void destruir_hash(p_no entradas, p_hash t, int aux){ //Destroi a lista do hash do último até o primeiro inserido.
    int n = hash1(entradas->id);
    if(entradas->prox != NULL)
        destruir_hash(entradas->prox, t, 0);
    while(strcmp(t->vetor[n]->id, entradas->id) != 0)
        n = (n + hash2(entradas->id) % MAX);
    destruir_no(t->vetor[n]);
    if(aux) //Por último destrói o próprio hash.
        free(t);
}

p_no Att_entradas(p_no entradas, int tempo, char *nome, char *id){ //Adciona a nova entrada na lista de entradas.
    p_no novo = entradas;
    if(novo == NULL){
        novo = criar_no();
        novo->tempo = tempo;
        strcpy(novo->id, id);
        strcpy(novo->nome, nome);
    } else
        novo->prox = Att_entradas(novo->prox, tempo, nome, id);
    return novo;
}

p_no Rmv_entrada(p_no entradas, char *id){ //Marca uma entrada como "REMOVIDO".
    p_no novo = entradas;
    if(strcmp(novo->id, id) != 0)
        novo->prox = Rmv_entrada(novo->prox, id);
    else
        strcpy(novo->nome, "REMOVIDO");
    return novo;
}

void Consulta(p_hash t, char *id, int op){ //Procura a entrada a partir de seu id.
    int n = hash1(id);
    while(t->vetor[n] != 0){
        if((strcmp(t->vetor[n]->id, id) == 0) && (strcmp(t->vetor[n]->nome, "REMOVIDO") != 0)){
            //Não deixa entrar no if caso a entrada tenha sido marcada como "REMOVIDO".
            if(op)
                printf("TEMPO DO PROCESSO %s: %d DIAS.\n", id, t->vetor[n]->tempo);
            else
                printf("PROCESSO %s: %s\n", t->vetor[n]->id, t->vetor[n]->nome);
            return;
        }
        n = (n + hash2(id)) % MAX;
    }
    printf("PROCESSO %s NAO ENCONTRADO!\n", id);
}

p_no inserir_lista(p_no vetor, char *id, char *nome, int tempo){
    p_no novo = malloc(sizeof(struct no));
    novo->tempo = tempo;
    strcpy(novo->id, id);
    strcpy(novo->nome, nome);
    return novo;
}

p_hash inserir(p_hash t, char *id, char *nome, int tempo){
    p_hash novo = t;
    int n = hash1(id);
    while(novo->vetor[n] != NULL)
        n = (n + hash2(id)) % MAX;
    novo->vetor[n] = inserir_lista(novo->vetor[n], id, nome, tempo);
    return novo;
}

p_no remover_lista(p_no vetor){ //Marca a entrada selecionada como "REMOVIDO".
    p_no novo = vetor;
    strcpy(novo->nome, "REMOVIDO");
    return novo;
}

void remover(p_no entradas, p_hash t, char *id){ //Remove a entrada com base em seu id.
    int n = hash1(id);
    while(strcmp(t->vetor[n]->id, id) != 0)
        n = (n + hash2(id)) % MAX;
    t->vetor[n] = remover_lista(t->vetor[n]);
    entradas = Rmv_entrada(entradas, id);
    printf("PROCESSO %s REMOVIDO!\n", id);
}