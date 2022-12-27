#include <stdio.h>
#include <stdlib.h>
#include "ultron.h"

void Imprime(int **Matriz, Size Tamanho){
    for(int i = 0; i < Tamanho.Ocupado_L; i++){
        for(int j = 0; j < Tamanho.Ocupado_C; j++)
            printf("%d ", Matriz[i][j]);
        printf("\n");
    }
    printf("###\n");
}

int **Cria_matriz(Size Tamanho){ //Cria uma matriz com 4 vezes o tamanho dos dados iniciais.
    int **Matriz;
    Matriz = malloc(Tamanho.Total_L * sizeof(int*));
    for(int i = 0; i < Tamanho.Total_L; i++)
        Matriz[i] = malloc(Tamanho.Total_C * sizeof(int));
    return Matriz;
}

void Destroi_matriz(int L, int **Matriz){
    for(int i = 0; i < L; i++)
        free(Matriz[i]);
    free(Matriz);
}

void Le_matriz(int L, int C, int **Matriz){ //Adciona os dados iniciais a matriz.
    for(int i = 0; i < L; i++)
        for(int j = 0; j < C; j++)
            scanf("%d", &Matriz[i][j]);
}

int **Realoca(int **Matriz, Size *Tamanho){
    if(Tamanho->Total_L / 4 >= Tamanho->Ocupado_L){ //Realoca as linhas caso estejam ocupando 1/4 da capacidade, ou menos.
        Matriz = realloc(Matriz, Tamanho->Total_L / 2 * sizeof(int*));
        Tamanho->Total_L /= 2;
    } else if (Tamanho->Total_L == Tamanho->Ocupado_L){ //Realoca as linhas caso estejam na capacidade máxima.
        Matriz = realloc(Matriz, Tamanho->Total_L * 2 * sizeof(int*));
        Tamanho->Total_L *= 2;
    }
    if(Tamanho->Total_C / 4 >= Tamanho->Ocupado_C){ //Realoca as colunas caso estejam ocupando 1/4 da capacidade, ou menos.
        for(int i = 0; i < Tamanho->Total_L; i++)
            Matriz[i] = realloc(Matriz[i], Tamanho->Total_C / 2);
        Tamanho->Total_C /= 2;
    } else if (Tamanho->Total_C == Tamanho->Ocupado_C){ //Realoca as colunas caso estejam na capacidade máxima.
        for(int i = 0; i < Tamanho->Total_L; i++)
            Matriz[i] = realloc(Matriz[i], Tamanho->Total_C / 2);
        Tamanho->Total_C *= 2;
    }
    return Matriz;
}

int **Cria_linha(int **Matriz, int *Dados, Size *Tamanho){ //Adiciona uma linha na última posição.
    for(int i = 0; i < Tamanho->Ocupado_C; i++)
        Matriz[Tamanho->Ocupado_L][i] = Dados[i];
    Tamanho->Ocupado_L++;
    return Matriz;
}

int **Destroi_linha(int **Matriz, int L, Size *Tamanho){
    for(int i = 0; i < Tamanho->Ocupado_C; i++)
        for(int j = L; j < Tamanho->Ocupado_L - 1; j++)
            Matriz[j][i] = Matriz[j + 1][i];
    Tamanho->Ocupado_L--;
    return Matriz;
}

int **Cria_coluna(int **Matriz, int *Dados, Size *Tamanho){ //Cria uma coluna na última posição, e então organiza as colunas.
    for(int i = 0; i < Tamanho->Ocupado_L; i++)
        Matriz[i][Tamanho->Ocupado_C] = Dados[i];
    Tamanho->Ocupado_C++;

    for(int i = 0; i < Tamanho->Ocupado_L; i++)
        for(int j = Tamanho->Ocupado_C - 1, aux; j > 0; j--)
            if(Matriz[i][j] < Matriz[i][j - 1]){
                aux = Matriz[i][j - 1];
                Matriz[i][j - 1] = Matriz[i][j];
                Matriz[i][j] = aux;
            } else
                break;
    return Matriz;
}

int **Destroi_coluna(int **Matriz, int C, Size *Tamanho){
    for(int i = 0; i < Tamanho->Ocupado_L; i++)
        for(int j = C; j < Tamanho->Ocupado_C - 1; j++)
            Matriz[i][j] = Matriz[i][j + 1];
    Tamanho->Ocupado_C--;
    return Matriz;
}