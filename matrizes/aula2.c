#include <stdio.h>
#include <stdlib.h>

double precos[] = {1500, 1100, 750, 500};

void carregaValores(double** m) {
    int i, j;
    for(i=0;i<4;i++) {
        for(j=50; j<=200; j+=50) {
            m[i][j/50 - 1] = precos[i] * j;
            printf("%9.2f  || \t", m[i][j/50 -1]);
        }
        printf("\n");
    }
}

int main() {
    int i;
    double** valores = (double**) malloc(sizeof(double*)*4);
    for(i = 0;i<4;i++) valores[i] = (double*) malloc(sizeof(double)*4);

    carregaValores(valores);

    return 0;
}