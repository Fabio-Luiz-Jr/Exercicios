#include <stdio.h>
#include "represa.h"
#define MAX_NOME 101 //Tamanho máximo do nome da represa.
#define MAX_MEDIDAS 1000 //Tamanho máximo de medidas.

int main() {
    float M, mda;
    char nome_represa[MAX_NOME];
    int T, N, medidas[MAX_MEDIDAS], t_nome, capacidade;
    scanf("%d", &T); //Lê quantas represas serão checadas.
    for(int i = 0; i < T; i++) { //Cria um loop para ler todas as represas e seus respectivos dados.
        scanf("%s", nome_represa); //Salva o nome da represa.
        scanf("%f %d", &M, &N); //Salva a a capacidade máxima em M e a quantidade de valores medidos em N.
        for(int j = 0; j < N; j++) //Cria um loop para ler as N medidas.
            scanf("%d", &medidas[j]); //Salva as medidas.
        t_nome = t_nome_represa(nome_represa); //Retorna o tamanho da string "nome_represa".
        t_nome = tira_prefixo(nome_represa, t_nome); //Se nescessário remove o prefixo da string e retorna 
                                                     //o tamanho da string.
        lowercase(nome_represa, t_nome); //Deixa todos os caracteres minúsculos.
        underline(nome_represa, t_nome); //Substitui todos os "_" da string por " ".
        t_nome = tira_numero(nome_represa, t_nome); //Remove todos os números da string e retorna seu tamanho.
        mda = media(medidas, N); //Retorna a média das medidas.
        capacidade = testa_capacidade(M, N, medidas); //Verifica se alguma medida excede a capacidade da represa.
        imprime(nome_represa, N, mda, capacidade); //Imprime os resultados.
    }
    return 0;
}