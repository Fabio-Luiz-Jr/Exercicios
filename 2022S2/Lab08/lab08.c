//O código funciona no meu computador e em um compilador online, mas por algum motivo ele não imprime no codePost.

#include <stdio.h>
#include <string.h>
#include "mapa.h"

int main(){
    int N;
    dados Entrada;
    p_mapa_c MAPA;
    p_mapa_v VISITA;

    scanf("%d", &N);
    while(N > 0){
        scanf("%s", Entrada.Operacao);
        if(strcmp(Entrada.Operacao, "insere_visita") == 0){
            scanf(" %s %d %d", Entrada.Cidade, &Entrada.Data_ini, &Entrada.Pista);
            MAPA = Aumenta_mapa(MAPA, Entrada);
            VISITA = Aumenta_visita(VISITA, Entrada);
        } else if(strcmp(Entrada.Operacao, "exclui_visita") == 0){
            scanf(" %d", &Entrada.Data_ini);
            VISITA = Exclui_visita(MAPA, VISITA, Entrada.Data_ini);
        } else if(strcmp(Entrada.Operacao, "relatorio_data") == 0){
            printf("--VISITAS--\n");
            scanf(" %d %d", &Entrada.Data_ini, &Entrada.Data_fin);
            Relatorio_data(VISITA, Entrada);
        } else{
            printf("--PISTAS--\n");
            scanf(" %d %d", &Entrada.Data_ini, &Entrada.Data_fin);
            Relatorio_pista(VISITA, Entrada);
        }
        N--;
    }
    Destroi_mapa(MAPA);
    Destroi_visita(VISITA);
    return 0;
}