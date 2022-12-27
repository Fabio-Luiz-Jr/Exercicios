#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultron.h"
#define MAX_OP 3 //Define o tamanho máximo de caracteres da operação

int main(){
    Size Ocupando;
    int Repetir = 0;
    int L = 0, C = 0;
    int **Matriz = NULL;
    int *Novos_dados;
    char Operacao[MAX_OP], L_ou_C;

    scanf("%d %d ", &L, &C);
    Ocupando.Total_L = 2 * L;
    Ocupando.Total_C = 2 * C;
    Ocupando.Ocupado_L = L;
    Ocupando.Ocupado_C = C;
    Matriz = Cria_matriz(Ocupando);
    Le_matriz(L, C, Matriz);
    scanf("%d ", &Repetir);

    while(Repetir > 0){
        scanf("%s %c ", Operacao, &L_ou_C);
        if(strcmp(Operacao, "IN") == 0){ //Decide qual operação executar, e em seguida, se vai aplicá-la em uma linha ou coluna.
            if(L_ou_C == 'L'){
                Novos_dados = malloc(Ocupando.Ocupado_C * sizeof(int));
                for(int i = 0; i < Ocupando.Ocupado_C; i++)
                    scanf("%d", &Novos_dados[i]);
                Matriz = Cria_linha(Matriz, Novos_dados, &Ocupando);
                free(Novos_dados);
            } else {
                Novos_dados = malloc(Ocupando.Ocupado_L * sizeof(int));
                for(int i = 0; i < Ocupando.Ocupado_L; i++)
                    scanf("%d", &Novos_dados[i]);
                Matriz = Cria_coluna(Matriz, Novos_dados, &Ocupando);
                free(Novos_dados);
            }
        } else {
            if(L_ou_C == 'L'){
                Novos_dados = malloc(sizeof(int));
                scanf("%d", &Novos_dados[0]);
                Matriz = Destroi_linha(Matriz, Novos_dados[0], &Ocupando);
                free(Novos_dados);
            } else {
                Novos_dados = malloc(sizeof(int));
                scanf("%d", &Novos_dados[0]);
                Matriz = Destroi_coluna(Matriz, Novos_dados[0], &Ocupando);
                free(Novos_dados);
            }
        }
        Imprime(Matriz, Ocupando);
        Realoca(Matriz, &Ocupando); //Realoca a matriz, se nescessário.
        Repetir--;
    }
    
    printf("COMBINACAO MATRICIAL FINALIZADA!\n");
    Destroi_matriz(Ocupando.Total_L, Matriz);

    return 0;
}