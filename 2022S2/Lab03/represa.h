int t_nome_represa(char nome_represa[101]); //Retorna o tamanho da string.

int tira_prefixo(char nome_represa[101], int t_nome); //Remove o prefixo e retorna o tamanho da string.

void lowercase(char nome_represa[101], int t_nome); //Deixa todos os caracteres minúsculos.

void underline(char nome_represa[101], int t_nome); //Substitui os "_" por " ".

int tira_numero(char nome_represa[101], int t_nome); //Remove os números e retorna o tamanho da string.

float media(int medidas[], int N); //Retorna a média das medidas.

int testa_capacidade(float M, int N, int medidas[]); //Retorna verdadeiro se alguma medida exceder a 
                                                     //capacidade máxima da represa, caso contrário, falso.

void imprime(char nome_represa[101], int N, float mda, int capacidade); //Imprime os resultados.