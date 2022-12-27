#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void Imprime(int Check, dados Entrada){
    if(Check){ //Imprime caso tenha inserido uma nova cidade.
        printf("ARVORE: MAPA\n");
        printf("CIDADE: %s\n", Entrada.Cidade);
        printf("INSERIDO COM SUCESSO!\n");
        printf("####\n");
    } //Imprime a nova data e cidade inserida.
    printf("ARVORE: VISITA\n");
    printf("DATA: %d\n", Entrada.Data_ini);
    printf("CIDADE: %s\n", Entrada.Cidade);
    printf("INSERIDO COM SUCESSO!\n");
    printf("####\n");
}

p_mapa_c Cria_mapa(){
    p_mapa_c Novo = malloc(sizeof(mapa_c));
    Novo->esq = NULL;
    Novo->dir = NULL;
    return Novo;
}

p_mapa_v Cria_visita(){
    p_mapa_v Novo = malloc(sizeof(mapa_v));
    Novo->esq = NULL;
    Novo->dir = NULL;
    return Novo;
}

void Destroi_mapa(p_mapa_c MAPA){
    if(MAPA != NULL){
        Destroi_mapa(MAPA->dir);
        Destroi_mapa(MAPA->esq);
        free(MAPA);
    }
}

void Destroi_visita(p_mapa_v VISITA){
    if(VISITA == NULL)
        return;
    Destroi_visita(VISITA->dir);
    Destroi_visita(VISITA->esq);
    free(VISITA);
}

p_mapa_c Aumenta_mapa(p_mapa_c MAPA, dados Entrada){
    p_mapa_c Novo = MAPA;
    if(Novo == NULL){ //Cria um novo nó caso o atual esteja vazio.
        Novo = Cria_mapa();
        strcpy(Novo->Cidade, Entrada.Cidade);
        Novo->Visitas = 1;
        Imprime(1, Entrada);
    } else if(strcmp(Entrada.Cidade, Novo->Cidade) < 0)
        Novo->esq = Aumenta_mapa(Novo->esq, Entrada);
    else if(strcmp(Entrada.Cidade, Novo->Cidade) > 0)
        Novo->dir = Aumenta_mapa(Novo->dir, Entrada);
    else{ //Caso a cidade já esteja no mapa, 1 visita será adicionada.
        Novo->Visitas++;
        Imprime(0, Entrada);
        }
    return Novo;
}

p_mapa_v Aumenta_visita(p_mapa_v VISITA, dados Entrada){
    p_mapa_v Novo = VISITA;
    if(Novo == NULL){ //Cria um novo nó caso o atual esteja vazio.
        Novo = Cria_visita();
        strcpy(Novo->Cidade, Entrada.Cidade);
        Novo->Data = Entrada.Data_ini;
        Novo->Pista = Entrada.Pista;
    } else if(Entrada.Data_ini < Novo->Data)
        Novo->esq = Aumenta_visita(Novo->esq, Entrada);
    else
        Novo->dir = Aumenta_visita(Novo->dir, Entrada);
    return Novo;
}

void Remover_mapa(p_mapa_c raiz){
    p_mapa_c min = raiz->dir;
    p_mapa_c pai = raiz;
    while (min->esq != NULL){ //Vai para o nó mais a esquerda da sub-árvore direita.
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;
    raiz->Visitas = min->Visitas; //Copia os dados do seu sucessor.
    strcpy(raiz->Cidade, min->Cidade);
}

p_mapa_c Encontra_mapa(p_mapa_c raiz, char *Nome){
    if (raiz == NULL)
        return NULL;
    if (strcmp(Nome, raiz->Cidade) < 0)
        raiz ->esq = Encontra_mapa(raiz->esq , Nome);
    else if (strcmp(Nome, raiz ->Cidade) > 0)
        raiz->dir = Encontra_mapa(raiz->dir , Nome);
    else{ //Atualiza o número de visitas.
        raiz->Visitas--;
        printf("QUANTIDADE DE VISITAS RESTANTES: %d\n", raiz->Visitas);
        if (raiz->esq == NULL){
            return raiz->dir;
        }else if (raiz->dir == NULL){
            return raiz->esq;
        }if(raiz->Visitas == 0)
            Remover_mapa(raiz); //Remove a raiz caso ela tenha 0 visitas;
    }
    return raiz;
}

void Remover_visita(p_mapa_v raiz){
    p_mapa_v min = raiz->dir;
    p_mapa_v pai = raiz;
    while (min->esq != NULL) { //Vai para o nó mais a esquerda da sub-árvore direita.
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;
    raiz->Data = min->Data; //Copia os dados do seu sucessor.
    raiz->Pista = min->Pista;
    strcpy(raiz->Cidade, min->Cidade);
}

p_mapa_v Exclui_visita(p_mapa_c MAPA, p_mapa_v VISITA, int Data){
    if (VISITA == NULL)
        return NULL;
    if (Data < VISITA->Data)
        VISITA ->esq = Exclui_visita(MAPA, VISITA->esq , Data);
    else if (Data > VISITA ->Data)
        VISITA->dir = Exclui_visita(MAPA, VISITA->dir , Data);
    else{ //Imprime os dados dessa visita.
        printf("CIDADE: %s\n", VISITA->Cidade);
        Encontra_mapa(MAPA, VISITA->Cidade);
        printf("####\n");
        if (VISITA->esq == NULL){
            return VISITA->dir;
        }else if (VISITA->dir == NULL){
           return VISITA->esq;
        }else
            Remover_visita(VISITA);
    }
    return VISITA;
}

void Relatorio_data(p_mapa_v VISITA, dados Entrada){ //Procura as visitas entre as datas desejadas.
    if(VISITA != NULL){
        Relatorio_data(VISITA->esq, Entrada);
        if((VISITA->Data >= Entrada.Data_ini) && (VISITA->Data <= Entrada.Data_fin)){
            printf("DATA: %d\n", VISITA->Data);
            printf("CIDADE: %s\n", VISITA->Cidade);
            printf("####\n");
        }
        Relatorio_data(VISITA->dir, Entrada);
    }
}

void Relatorio_pista(p_mapa_v VISITA, dados Entrada){ //Procura as cidades entre as datas desejadas.
    if(VISITA != NULL){
        Relatorio_pista(VISITA->dir, Entrada);
        if((VISITA->Data >= Entrada.Data_ini) && (VISITA->Data <= Entrada.Data_fin)){
            if(VISITA->Pista){
                printf("DATA: %d\n", VISITA->Data);
                printf("CIDADE: %s\n", VISITA->Cidade);
                printf("####\n");}
        }
        Relatorio_pista(VISITA->esq, Entrada);
    }
}