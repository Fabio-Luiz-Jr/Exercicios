#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#define MAX_ENTRADA 500 //Define o tamanho máximo das entradas.

void imprime_tudo(fila f, p_pilha P) {
    imprime_fila(f);
    printf("PILHA ATUAL: ");
    imprime_pilha(P);
    printf("\n");
    printf("####\n");
}

int main() {
    char entrada[MAX_ENTRADA], aux[MAX_ENTRADA], *comando;
    p_pilha P;
    int N;
    fila F;
    P = cria_pilha();
    cria_fila(&F);
    do {
        fgets(entrada, MAX_ENTRADA, stdin);
        entrada[strcspn(entrada, "\n")] = 0;
        strcpy(aux, entrada);
        comando = strtok(aux, " "); //Separa a primeira palavra no ponteiro "comando".
        if(strcmp(comando, "EXEC") == 0) { //Quando verdadeiro, os primeiros N caracteres da fila serão empilhados.
            N = atoi(strtok(NULL, " "));
            P = empilhar(P, F.texto, F.ini, F.fim, N);
            desenfileira(&F, N);
        } else if(strcmp(comando, "DEL") == 0) { //Quando verdadeiro, os últimos N caracteres da pilha serão desempilhados.
            N = atoi(strtok(NULL, " "));
            P = desempilhar(P, N);
        } else if(strcmp(comando, "EXIT") != 0) //Condição é verdadeira quando o usuário digita uma frase.
            enfileira(&F, entrada);
        if(strcmp(entrada, "EXIT") != 0) //Para não imprimir a mais, ele não imprime quando o código terminar.
            imprime_tudo(F, P);
    } while(strcmp(entrada, "EXIT") != 0); //Repete o "do" enquanto o usuário não entrar com "EXIT".
    libera_pilha(P);
    return 0;
}