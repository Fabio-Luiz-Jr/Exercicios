#include <stdio.h>
#include "represa.h"
#define MAX_NOME 101
#define TAMANHO_PREFIXO 11 //Define o tamanho do prefixo "represa_de_".

int t_nome_represa(char nome_represa[MAX_NOME]) {
    for(int i = 0; i < MAX_NOME; i++) //Procura pelo final da string.
        if(nome_represa[i] == '\0')
            return i + 1; //Retorna o tamanho da string.
    return 0;
}

int tira_prefixo(char nome_represa[MAX_NOME], int t_nome) {
    int i;
    if(t_nome > TAMANHO_PREFIXO && nome_represa[0] == 'r' && nome_represa[3] == 'r' 
    && nome_represa[10] == '_') { //Remove o prefixo se tiver espaço para ele existir e se alguns caracteres
                                  //aleatórios do prefixo existirem na mesma posição da string.
        for(i = 0; i < t_nome; i++)
            nome_represa[i] = nome_represa[i + TAMANHO_PREFIXO]; //Remove o prefixo.
        nome_represa[i + 1] = '\0'; //Define o novo final da string.
        return t_nome - TAMANHO_PREFIXO; //Retorna o nova tamanho da string.
    }
    return t_nome; //Retorna o tamanho atual da string caso o prefixo não exista.
}

void lowercase(char nome_represa[MAX_NOME], int t_nome) {
    for(int i = 0; i < t_nome; i++)
        if(nome_represa[i] >= 65 && nome_represa[i] <= 90) //Procura se o caracter está entre as letras 
                                                           //maiúsculas da tabela ASCII.
            nome_represa[i] += 32; //Soma 32 ao caracter, mudando-o para seu valor minúsculo.
}

void underline(char nome_represa[MAX_NOME], int t_nome) { //Substitui "_" por " ".
    for(int i = 0; i < t_nome; i++)
        if(nome_represa[i] == '_')
            nome_represa[i] = ' ';
}

int tira_numero(char nome_represa[MAX_NOME], int t_nome) {
    int i;
    for(i = 0; i < t_nome; i++)
        if(nome_represa[i] >= 48 && nome_represa[i] <= 57) { //Procura na tabela ASCII se o caracter é um número.
            nome_represa[i] = '\0'; //Caso encontre um número, define sua posição como final da string.
            return i + 1; //Retorna o novo tamanho da string.
        }
    return t_nome; //Retorna o valor atual da string caso não encontre números.
}

float media(int medidas[], int N) {
    float soma = 0;
    for(int i = 0; i < N; i++)
        soma += medidas[i]; //Soma as medidas.
    return soma / N; //Retorna a média da soma das medidas.
}

int testa_capacidade(float M, int N, int medidas[]) {
    for(int i = 0; i < N; i++)
        if( medidas[i] >= M * 90 / 100) //Verifica se a medida excede a capacidade máxima da represa.
            return 1; //Retorna verdadeiro se exceder.
    return 0; //Retorna falso se estiver dentro dos limites.
}

void imprime(char nome_represa[MAX_NOME], int N, float mda, int capacidade) {
    printf("NOME: %s\n", nome_represa);
    printf("QTD NIVEIS: %d\n", N);
    printf("MEDIA: %d\n", (int)mda); //Imprime o valor inteiro da média.
    if(capacidade) //Imprime a próxima linha caso alguma medida exceda a capacidade máxima da represa.
        printf("CAPACIDADE ACIMA DE 90%% DA MAXIMA!\n");
    printf("#####\n");
}