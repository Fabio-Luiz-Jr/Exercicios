#include <stdio.h>
#include <string.h>
#include "cobra.h"

int main() {
    int **Matriz, Fim = 0, M, N, X, Y, A, B, C_brancas;
    char comando[5], movimento;
    p_no cobra;
    //Variáveis **Matriz, M, N, X, Y, A, B, movimento definidas no enunciado.
    //Fim representa o resultado do movimento da cobra.
    //C_brancas conta o número de casas brancas na matriz.
    //comando armazena a palavra "FRUTA" ou "COBRA".
    //cobra armazena as coordenadas de cada parte da cobra na Matriz.
    cobra = criar_lista();
    scanf("%d %d ", &M, &N); //Lê as dimensões da Matriz.
    C_brancas = M * N - 1; //Define o número inicial de casas brancas da Matriz.
    Matriz = cria_matriz(M, N); //Cria a Matriz.
    scanf("%s %d %d ", comando, &X, &Y); //Lê o comando a ser executado.
    insere_fruta(Matriz, X, Y); //Coloca uma fruta na Matriz.
    scanf("%s %d %d ", comando, &A, &B);
    insere_cobra(Matriz, A, B); //Coloca a cobra na Matriz.
    cobra = adicionar_elemento(cobra, A, B); //Cria a cabeça da cobra.
    imprime(Matriz, M, N, Fim);
    while(!Fim) { //Repete até a cobra bater ou ocupar todas as casas.
        A = cobra->x;
        B = cobra->y;
        //Separa as coordenadas da cabeça da cobra em duas variáveis.
        scanf("%c ", &movimento); //Lê qual movimento deve fazer.
        calcula_movimento(Matriz, M, N, &A, &B, movimento); //Define para qual coordenada a cabeça deve se mover.
        Fim = decide_acao(Matriz, A, B);
        if(Fim == 0)
            mover(Matriz, cobra, A, B); //Move a cobra.
        else if(Fim == -1) {
            Fim = 0;
            cobra = aumenta_cobra(Matriz, cobra, A, B); //move e aumenta a cobra.
            C_brancas--; //Atualiza o valor de casas brancas restantes.
            if(C_brancas != 0) { //Coloca uma fruta na Matriz, se tiver espaço.
                imprime(Matriz, M, N, Fim);
                scanf("%s %d %d ", comando, &X, &Y);
                insere_fruta(Matriz, X, Y);
            }
        }
        if(C_brancas == 0)
            Fim = 2; //O jogador ganhou.
        imprime(Matriz, M, N, Fim);
    }
    destruir_lista(cobra);
    destruir_matriz(Matriz, M);
    return 0;
}
