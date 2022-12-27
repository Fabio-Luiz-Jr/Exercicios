/*Nome: Fábio Luiz Ferreira da Silva Júnior
* RA: 247079
*Laboratório 7 - Matrioshkas Generalizadas */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *filho_1, *prox_irmao;
} No;

typedef No * p_no;

p_no inserir_dado(int x);

p_no inserir_irmao(p_no node, int n);

p_no inserir_filho(p_no node, int n);

p_no cria_arvore(p_no node, int *nos, int n, int *i);

int soma_irmao(p_no arvore);

int procura_filho(p_no arvore);

void resultado(p_no arvore);

void libera(p_no arvore);

int main(){
    p_no arvore = NULL;
    int i, n, *nos;
    scanf("%d", &n);
        while(n != 0){
            i = 1;
            nos = malloc(n * sizeof(int));
            for (int i = 0; i < n; i++)
                scanf("%d", &nos[i]);
            arvore = inserir_dado(-nos[0]);
            arvore = cria_arvore(arvore, nos, n, &i);
            resultado(arvore);
            free(nos);
            libera(arvore);
            scanf("%d", &n);
        }
    return 0;
}

p_no inserir_dado(int x){
    p_no node = malloc(sizeof(No));
    node->dado = x;
    node->filho_1 = node->prox_irmao = NULL;
    return node;
}

p_no inserir_irmao(p_no node, int n){
    if(node->prox_irmao == NULL)
        node->prox_irmao = inserir_dado(n);
    else
        node->prox_irmao = inserir_irmao(node->prox_irmao, n);
    return node;
}

p_no inserir_filho(p_no node, int n){
    if(node->filho_1 == NULL)
        node->filho_1 = inserir_dado(n);
    else
        node->filho_1 = inserir_filho(node->filho_1, n);
    return node;
}

p_no cria_arvore(p_no node, int *nos, int n, int *i){
    if(nos[*i] < 0){
        node = inserir_filho(node, -nos[*i]);
        *i += 1;
        node->filho_1 = cria_arvore(node->filho_1, nos, n, i);
        *i += 1;
        node = cria_arvore(node, nos, n, i);
    } else if(nos[*i + 1] < 0){
        *i += 1;
        node = inserir_irmao(node, -nos[*i]);
        *i += 1;
        node->prox_irmao = cria_arvore(node->prox_irmao, nos, n, i);
    }
    return node;
}

int soma_irmao(p_no arvore){
    if(arvore == NULL)
        return 0;
    if(arvore->prox_irmao != NULL)
        return soma_irmao(arvore->prox_irmao) + arvore->dado;
    else
        return arvore->dado;
}

int procura_filho(p_no arvore){
    if(arvore->prox_irmao != NULL)
        if(!procura_filho(arvore->prox_irmao))
            return 0;
    if(arvore->filho_1 != NULL)
        if(!procura_filho(arvore->filho_1))
            return 0;
    if(soma_irmao(arvore->filho_1) >= arvore->dado)
        return 0;
    else
        return 1;
}

void resultado(p_no arvore){
    if(procura_filho(arvore))
        printf("Eh Matrioshka.\n");
    else
        printf("Nao eh Matrioshka.\n");
}

void libera(p_no arvore){
    if(arvore->prox_irmao != NULL)
        libera(arvore->prox_irmao);
    if(arvore->filho_1 != NULL)
        libera(arvore->filho_1);
    free(arvore);
}
