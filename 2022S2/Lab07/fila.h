#define MAX_FILA_H 500 //Define a quantidade máxima de caracteres que cabem na fila.

typedef struct fila {
    char texto[MAX_FILA_H];
    int ini, fim, tamanho;
} fila;

void imprime_fila(fila f);

void cria_fila(fila *f);

void enfileira(fila *f, char frase[]);

void desenfileira(fila *f, int N);