typedef struct no *p_no;

struct no {
    int x, y;
    p_no prox;
    p_no ant;
} ;

void imprime(int **Matriz, int M, int N, int resultado);

p_no criar_lista ();

void destruir_lista(p_no lista);

p_no adicionar_elemento (p_no lista , int X, int Y);

int **cria_matriz(int M, int N);

void destruir_matriz(int **Matriz, int M);

void insere_fruta(int **Matriz, int X, int Y);

void insere_cobra(int **Matriz, int A, int B);

void calcula_movimento(int **Matriz, int M, int N, int *X, int *Y, char movimento);

int decide_acao(int **Matriz, int X, int Y);

void mover(int **Matriz, p_no cobra, int novo_x, int novo_y);

p_no aumenta_cobra(int **Matriz, p_no cobra, int x_ant, int y_ant);