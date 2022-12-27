#include <stdio.h>
#include <string.h>
#include "balloc.h"
#define MAX_ENTRADA 15
#define MAX_COMANDO 11
#define MENOR_NUMERO -100000
#define MAIOR_NUMERO 100000

typedef struct No
{
    int dado;
    struct No *esq, *dir;
} No;

typedef No *p_no;

p_no criar(p_no arvore){
    arvore = MALLOC(sizeof(No));
    arvore->dado = arvore->esq = arvore->dir = 0;
    return arvore;
}

p_no inserir(p_no arvore, int x){
    if(arvore->dado == NULL)
        arvore->dado = x;
    else{
        if(x < arvore->dado){
            arvore->esq = criar(arvore->esq);
            arvore = inserir(arvore->esq, x);
        } else {
            arvore->dir = criar(arvore->dir);
            arvore = inserir(arvore->dir, x);
        }
    }
    return arvore;
}

p_no remover(p_no arvore, int x){

}

int buscar(p_no arvore, int x){
    if(x == arvore->dado)
        return 1;
    else{
        if(x < arvore->dado)
            if(!buscar(arvore->esq, x))
                return 0;
        else
            if(!buscar(arvore->dir, x))
                return 0;
    }
}

void pre(p_no arvore){

}

void in(p_no arvore){

}

void pos(p_no arvore){

}

void min(p_no arvore, int menor, int i){
    i++;
    static int mnr = 0;
    if(menor > arvore->dado)
        mnr = arvore->dado;
    if(arvore->esq != NULL)
        min(arvore->esq, mnr, i);
    if(i == 0){
        if(mnr == 0)
            printf("arvore vazia");
        else
            printf("minimo: %d", mnr);
        }
}

void max(p_no arvore, int maior, int i){
    i++;
    static int mor = 0;
    if(maior > arvore->dado)
        mor = arvore->dado;
    if(arvore->dir != NULL)
        max(arvore->dir, mor, i);
    if(i == 0){
        if(mor == 0)
            printf("arvore vazia");
        else
            printf("maximo: %d", mor);
        }
}

void sucessor(p_no arvore, int x){

}

void predecessor(p_no arvore, int x){

}
 void info(p_no arvore){

}

int main(){
    p_no arvore = NULL;
    char entrada[MAX_ENTRADA], comando[MAX_COMANDO];
    int x;
    scanf("%s", entrada);
    while (strcmp(entrada, "terminar") != 0)
    {
        if (strstr(entrada, ' ') != NULL){
            strcpy(comando,strtok(entrada, ' '));
            x = strtok(entrada, NULL);
        }
        if (strcmp(entrada, "criar") == 0)
            arvore = criar(arvore);
        else if (strcmp(comando, "inserir") == 0)
            arvore = inserir(arvore, x);
        else if(strcmp(comando, "remover") == 0)
            arvore = remover(arvore, x);
        else if(strcmp(comando, "buscar") == 0){
            if(buscar(arvore, x))
                printf("%d esta na arvore\n", x);
            else
                printf("%d nao esta na arvore\n", x);
            }
        else if(strcmp(entrada, "pre-ordem") == 0)
            pre(arvore);
        else if(strcmp(entrada, "in-ordem") == 0)
            in(arvore);
        else if(strcmp(entrada, "pos-ordem") == 0)
            pos(arvore);
        else if(strcmp(entrada, "minimo") == 0)
            min(arvore, MAIOR_NUMERO, -1);
        else if(strcmp(entrada, "maximo") == 0)
            max(arvore, MENOR_NUMERO, -1);
        else if(strcmp(comando, "sucessor") == 0)
            sucessor(arvore, x);
        else if(strcmp(comando, "predecessor") == 0)
            predecessor(arvore, x);
        else if(strcmp(entrada, "info") == 0)
            info(arvore);
        scanf("%s", entrada);
    }
    return 0;
}