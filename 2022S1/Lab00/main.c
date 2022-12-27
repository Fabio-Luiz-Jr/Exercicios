#include <stdio.h>
#include <string.h>
#define MAX 100
/*Define o tamanho máximo das strings como 100*/

int main() {
	char Entrada[MAX], Saida[MAX];
	scanf("%s", Entrada);
	/*Le a entrada*/
	for(int i = 0; i < strlen(Entrada); i++)
		Saida[strlen(Entrada) - i - 1] = Entrada[i];
	/*Inverte a entrada e coloca o resultada na variavel Saida*/
	printf("%s", Saida);
	/*Imprime a Saida*/
	return 0;
}
