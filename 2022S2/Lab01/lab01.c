#include <stdio.h>
#define MAX 1000

//Imprime o vetor u.
void imprime(int u[], int T) {
    for (int i = 0; i < T; i++)
        printf("%d ", u[i]);
    printf("\n");
}

//Lê o vetor u.
void le_calculos_tony(int u[], int T) {
    for (int i = 0; i < T; i++)
        scanf("%d", &u[i]);
}

void conjunto_banner(int u[], int T) {
    int B, i, c_banner[MAX], j;
    scanf("%d", &B);
    //Lê o Conjunto de Banner.
    for (i = 0; i < B; i++)
        scanf("%d", &c_banner[i]);
    //Modifica para zero os valores de u que não pertencem ao Conjunto de Banner.
    for (i = 0; i < T; i++)
        for (j = 0; j < B; j++) {
            if (c_banner[j] == u[i])
                break;
            if (j == B - 1)
                u[i] = 0;
        }
}

void multiplicacao_mobius(int u[], int T) {
    int M;
    scanf("%d", &M);
    //Multiplica u[i] por M a cada duas posições a partir da primeira.
    for (int i = 1; i < T; i += 2)
        u[i] *= M;
}

void movimento_ciclico(int u[], int T) {
    int P, vetor_auxiliar[MAX], i;
    scanf("%d", &P);
    //Copia em vetor_auxiliar o vetor u.
    for (i = 0; i < T; i++)
        vetor_auxiliar[i] = u[i];
    //Copia P posições a frente em u o vetor vetor_auxiliar.
    for (i = 0; i < T; i++)
        u[(P + i) % T] = vetor_auxiliar[i];
}

void inversao_vetor(int u[], int T) {
    int vetor_auxiliar[MAX], i;
    //Copia em vetor_auxiliar o vetor u de trás pra frente.
    for (i = 0; i < T; i++)
        vetor_auxiliar[T - i - 1] = u[i];
    //Copia em u o vetor vetor_auxiliar.
    for (i = 0; i < T; i++)
        u[i] = vetor_auxiliar[i];
    
}

int main() {
    int T, u[MAX], num_op, op;
    scanf("%d", &T);
    le_calculos_tony(u, T);
    scanf("%d", &num_op);
    //Executa a operação que o usuário escolher.
    for (int i = 0; i < num_op; i++) {
        scanf("%d", &op);
        if (op == 1)
            conjunto_banner(u, T);
        else if (op == 2)
            multiplicacao_mobius(u, T);
        else if (op == 3)
            movimento_ciclico(u, T);
        else
            inversao_vetor(u, T);
        imprime(u, T);
    }
    return 0;
}
