#include <stdio.h>
#include <string.h>
#include "hash.h"

int main(){
    p_no entradas = NULL; //"entradas" registra a ordem em que os dados foram adicionados.
    p_hash processos = NULL;
    int N, tempo;
    char op, nome[31], id[11]; //"nome" e "id" possuem um tamanho maior ou igual as suas maiores entradas.

    processos = criar_hash();
    scanf("%d", &N);
    while(N > 0){
        scanf(" %c %s", &op, id);
        if(op == 'I'){ //Decide qual operação executar.
            scanf(" %s %d", nome, &tempo);
            entradas = Att_entradas(entradas, tempo, nome, id);
            processos = inserir(processos, id, nome, tempo);
            Imprime(id);
        } else if(op == 'C')
            Consulta(processos, id, 0);
        else if(op == 'T')
            Consulta(processos, id, 1);
        else
            remover(entradas, processos, id);
        N--;
    }
    destruir_hash(entradas, processos, 1);
    destruir_no(entradas);
    printf("FINALIZADO!");
    return 0;
}