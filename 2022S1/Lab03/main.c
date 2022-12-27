#include <stdio.h>
#include <ctype.h>
#include <string.h>

int conta_palavras(int K, char p_chaves[K][15], char palavras[15]){
	int i, igual = 0;
	char lowercase[15];
	for(i = 0; i < strlen(palavras); i++)
		lowercase[i] = tolower(palavras[i]);
	lowercase[strlen(palavras)] = '\0';
	for(i = 0; i < K; i++) {
		printf("Entrada: |%s| - |%s|\n", p_chaves[i], lowercase);
		if(strcmp(p_chaves[i], lowercase) == 0)
			igual++;
	}
	return igual;
}

void imprime(int j, char desculpas[100]){
	printf("Conjunto de desculpas #%d\n", j);
	printf("%s\n", desculpas);
	printf("\n");
}

int main() {
	int K, E, i, j = 1, ttl_desculpas, maior_dsclp;
	char K_E[3];
	while(!feof(stdin)) {
	    fgets(K_E, 4, stdin);
		K = K_E[0] - '0';
	    E = K_E[2] - '0';
		char p_chaves[K][15], desculpas[E][100], desculpas_2[100], *palavras;
		int ttl_desc_frase[E];
		ttl_desculpas = 0;
		maior_dsclp = 0;
		for(i = 0; i < K; i++) {
			fgets(p_chaves[i], 16, stdin);
			p_chaves[i][strcspn(p_chaves[i], "\n")] = 0;
		}
		for(i = 0; i < E; i++)
			fgets(desculpas[i], 101, stdin);
		for(i = 0; i < E; i++){
			strcpy(desculpas_2, desculpas[i]);
			if(desculpas_2[strlen(desculpas_2)] == '.')
				desculpas_2[strlen(desculpas_2)] = '\0';
			palavras = strtok(desculpas_2, " " ".");
			while(palavras != NULL) {
				ttl_desculpas += conta_palavras(K, p_chaves, palavras);
				palavras = strtok(NULL, " " ".");
			}
			ttl_desc_frase[i] = ttl_desculpas;
		}
		for(i = 0; i < E; i++)
			if(ttl_desc_frase[i] > maior_dsclp)
				maior_dsclp = ttl_desc_frase[i];
		for(i = 0; i < E; i++)
			if(maior_dsclp == ttl_desc_frase[i])
				imprime(j, desculpas[i]);
		j++;
	}
	return 0;
}
