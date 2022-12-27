#define MAX_PILHA 50 //Define a quantidade máxima de caracteres que um nó consegue armazenar.

typedef struct pilha *p_pilha;

typedef struct pilha {
    char texto[MAX_PILHA];
    int topo;
    p_pilha prox;
} pilha;

p_pilha cria_pilha();

void imprime_pilha(p_pilha P);

p_pilha aumenta_pilha(p_pilha p);

p_pilha empilhar(p_pilha p, char frase[], int i, int fim, int N);

p_pilha libera_primeiro_no(p_pilha no);

p_pilha desempilhar(p_pilha p, int N);

void libera_pilha(p_pilha P);