#include <stdio.h>

int batalha(int hp, int ataque) {
	hp -= ataque;
	/*Deduz do HP os pontos de ataque*/
	if(hp < 0)
		hp = 0;
	/*Caso o HP for menor que zero, ele é defenido como 0*/
	return hp;
}

int main() {
	int hp_ryu, hp_ken, ataque, golpes_ryu = 0, golpes_ken = 0;
	scanf("%d", &hp_ryu);
	/*Lê o HP do Ryu*/
	scanf("%d", &hp_ken);
	/*Lê o HP do Ken*/
	while(hp_ryu > 0 && hp_ken > 0) {
		scanf("%d", &ataque);
		/*Lê os pontos de ataque*/
		if(ataque < 0) {
			golpes_ken++;
			/*Conta os golpes de Ken*/
			ataque = ataque * (-1);
			/*Converte os pontos de ataque para um valor positivo*/
			hp_ryu = batalha(hp_ryu, ataque);
			printf("KEN APLICOU UM GOLPE: %d\n", ataque);
			printf("HP RYU = %d\n", hp_ryu);
			printf("HP KEN = %d\n", hp_ken);
		} else {
			golpes_ryu++;
			/*Conta os golpes de Ryu*/
			hp_ken = batalha(hp_ken, ataque);
			printf("RYU APLICOU UM GOLPE: %d\n", ataque);
			printf("HP RYU = %d\n", hp_ryu);
			printf("HP KEN = %d\n", hp_ken);
		}
		if(hp_ryu == 0 || hp_ken == 0)
			break;
		/*Sai do while se um dos dois HPs chegar a 0*/
	}
	if(hp_ryu == 0)
		printf("LUTADOR VENCEDOR: KEN\n");
	else
		printf("LUTADOR VENCEDOR: RYU\n");
	printf("GOLPES RYU = %d\n", golpes_ryu);
	printf("GOLPES KEN = %d\n", golpes_ken);
	return 0;
}
