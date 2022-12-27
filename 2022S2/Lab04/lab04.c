#include <stdio.h>
#include <stdlib.h>
#define MENOR_INT_POSSIVEL -2147483647 //Define o menor valor possível em int.

void Libera_vetor(int *Vetor){
    free(Vetor);
}

void Libera_matriz(int N, int **Matriz){
    for(int i = 0; i < N; i++)
        Libera_vetor(Matriz[i]);
    free(Matriz);
}

int *Encontra_sub(int op, int N, int *Tropa, int *size){ //Retorna a sub-tropa e define seu tamanho.
    //op = 0: Encontra a sub tropa forte;
    //op = 1: Encontra a sub tropa de elite.
    int media = 0;
    int novo_inicio, inicio = 0, fim = 0;
    int maior_soma = MENOR_INT_POSSIVEL, soma_atual = 0;
    int *Tropa_padronizada = malloc(N * sizeof(int)), *Sub_tropa;

    if(op){ //Calcula a média (se nescessário).
        for(int i = 0; i < N; i++)
            media += Tropa[i];
        media /= N;
    }
    
    for(int i = 0, atualiza_inicio = 0; i < N; i++){
        if(op)
            Tropa_padronizada[i] = Tropa[i] - media;
        else
            Tropa_padronizada[i] = Tropa[i];
        //Subtrai a média para padronizar a tropa (se nescessário).
        
        soma_atual += Tropa_padronizada[i];
        if(soma_atual > maior_soma){
            maior_soma = soma_atual;
            fim = i;
            if(atualiza_inicio){ //Atualiza o ponto de início da sub-tropa.
                inicio = novo_inicio;
                atualiza_inicio = 0;
            }
        }

        if(soma_atual <= 0){
            atualiza_inicio = 1; //Sinaliza para atualizar o ponto de início da sub-tropa, se for possível.
            novo_inicio = i + 1; //Salva um possível novo ponto inicial da sub-tropa.
            soma_atual = 0; //Reseta o valor da soma atual.
        }
    }

    *size = fim - inicio + 1; //Calcula o tamanho da sub-tropa.
    Sub_tropa = malloc(*size * sizeof(int));

    for(int i = 0; i < *size; i++) //Copia a subarray desejada para a sub-tropa.
        Sub_tropa[i] = Tropa[i + inicio];
    
    Libera_vetor(Tropa_padronizada);

    return Sub_tropa;
}

void Encontra_elite(int Q, int *Elite, int *N_sub_forte, int **Sub_forte){ //Combina todas as sub-tropas fortes.
    for(int i = 0, k = 0; i < Q; i++)
        for(int j = 0; j < N_sub_forte[i]; j++){
            Elite[k] = Sub_forte[i][j];
            k++;
        }
}

void Imprime(int N, int *Vetor){
    for(int i = 0; i < N; i ++)
        printf("%d ", Vetor[i]);
}

void Imprime_forte(int i, int N, int *Vetor){
    printf("Sub-tropa Forte %d: ", i + 1);
    Imprime(N, Vetor);
    printf("\n");
}

void Imprime_elite(int N, int *Vetor){
    printf("Sub-tropa Elite: ");
    Imprime(N, Vetor);
}

int main(){
    int Q, *N_tropa, **N_exp_tropa;
    int *N_sub_forte = 0, **Sub_forte = NULL;
    int N_elite = 0, *Elite;
    int N_sub_elite = 0, *Sub_elite = NULL;

    scanf("%d", &Q);

    N_sub_forte = malloc(Q * sizeof(int));
    N_tropa = malloc(Q * sizeof(int));
    N_exp_tropa = malloc(Q * sizeof(int*));
    Sub_forte = malloc(Q * sizeof(int*));

    for(int i = 0; i < Q; i++){
        scanf("%d", &N_tropa[i]);
        N_exp_tropa[i] = malloc(N_tropa[i] * sizeof(int));
        for(int j = 0; j < N_tropa[i]; j++)
            scanf("%d", &N_exp_tropa[i][j]);
        }
    

    for(int i = 0; i < Q; i++){
        Sub_forte[i] = Encontra_sub(0, N_tropa[i], N_exp_tropa[i], &N_sub_forte[i]);
        N_elite += N_sub_forte[i]; //Calcula o tamanho da tropa elite.
        }
    Elite = malloc(N_elite * sizeof(int));
    Libera_matriz(Q, N_exp_tropa);
    Libera_vetor(N_tropa);

    Encontra_elite(Q, Elite, N_sub_forte, Sub_forte);

    Sub_elite = Encontra_sub(1, N_elite, Elite, &N_sub_elite);

    Libera_vetor(Elite);

    for(int i = 0; i < Q; i++)
        Imprime_forte(i, N_sub_forte[i], Sub_forte[i]);
    Imprime_elite(N_sub_elite, Sub_elite);
    
    Libera_matriz(Q, Sub_forte);
    Libera_vetor(N_sub_forte);
    Libera_vetor(Sub_elite);

    return 0;
}