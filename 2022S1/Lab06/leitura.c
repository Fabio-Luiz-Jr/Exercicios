#include <stdio.h>

void leitura(){

  int x, leu;

  leu = scanf("A = { %d", &x);
/*  printf("%d\n", leu); */
  while (leu) {
    printf("%d\n", x);
    leu = scanf(", %d", &x);
  }
  scanf("}");
  scanf("%d", &x);
  printf("%d\n", x);
}