typedef struct Size{
    int Ocupado_C;
    int Ocupado_L;
    int Total_C;
    int Total_L;
}Size;

void Imprime(int **Matriz, Size Tamanho);

int **Cria_matriz(Size Tamanho);

void Destroi_matriz(int L, int **Matriz);

void Le_matriz(int L, int C, int **Matriz);

int **Realoca(int **Matriz, Size *Tamanho);

int **Cria_linha(int **Matriz, int *Dados, Size *Tamanho);

int **Destroi_linha(int **Matriz, int L, Size *Tamanho);

int **Cria_coluna(int **Matriz, int *Dados, Size *Tamanho);

int **Destroi_coluna(int **Matriz, int C, Size *Tamanho);