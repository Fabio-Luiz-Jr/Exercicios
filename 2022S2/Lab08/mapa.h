#define MAX_OP 16
#define MAX_CIDADE 30

typedef struct mapa_c * p_mapa_c;

typedef struct mapa_c{
    char Cidade[MAX_CIDADE];
    int Visitas;
    p_mapa_c esq, dir;
}mapa_c;

typedef struct mapa_v * p_mapa_v;

typedef struct mapa_v{
    char Cidade[MAX_CIDADE];
    int Data, Pista;
    p_mapa_v esq, dir;
}mapa_v;

typedef struct dados{
    int Data_ini, Data_fin, Pista;
    char Operacao[MAX_OP], Cidade[MAX_CIDADE];
}dados;

void Imprime(int Check, dados Entrada);

p_mapa_c Cria_mapa();

p_mapa_v Cria_visita();

void Destroi_mapa(p_mapa_c MAPA);

void Destroi_visita(p_mapa_v VISITA);

p_mapa_c Aumenta_mapa(p_mapa_c MAPA, dados Entrada);

p_mapa_v Aumenta_visita(p_mapa_v VISITA, dados Entrada);

void Remover_mapa(p_mapa_c raiz);

p_mapa_c Encontra_mapa(p_mapa_c raiz, char *Nome);

void Remover_visita(p_mapa_v raiz);

p_mapa_v Exclui_visita(p_mapa_c MAPA, p_mapa_v VISITA, int Data);

void Relatorio_data(p_mapa_v VISITA, dados Entrada);

void Relatorio_pista(p_mapa_v VISITA, dados Entrada);