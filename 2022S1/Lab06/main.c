#include <stdio.h>
#include "balloc.h"

void leitura(){
    int x, leu;
    char *B;
    void *A;
    B = malloc(sizeof(char));
    B[0] = ' ';
    leu = scanf("A = { %d", &x);
    A = balloc(B, leu, sizeof(int));
    while (leu) {
        leu = scanf(", %d", &x);
        A = balloc(B, leu, sizeof(int));
    }
    scanf("}");
    printf("%p\n%s", A, B);
    free(B);
    bfreeall();
}

int main() {
    leitura();
    return 0;
}