#define MAX 2129

typedef struct no *p_no;

struct no{
    char nome[31];
    char id[11];
    int tempo;
    p_no prox;
};

typedef struct hash *p_hash;

struct hash{
p_no vetor[MAX];
};

void Imprime(char *id);

p_no criar_no();

p_hash criar_hash();

int hash1(char *id);

int hash2(char *id);

void destruir_no(p_no lista);

void destruir_hash(p_no entradas, p_hash t, int aux);

p_no Att_entradas(p_no entradas, int tempo, char *nome, char *id);

p_no Rmv_entrada(p_no entradas, char *id);

void Consulta(p_hash t, char *id, int op);

p_no inserir_lista(p_no vetor, char *id, char *nome, int tempo);

p_hash inserir(p_hash t, char *id, char *nome, int tempo);

p_no remover_lista(p_no vetor);

void remover(p_no entradas, p_hash t, char *id);