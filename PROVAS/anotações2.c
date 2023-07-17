//ANOTAÇÔES DO EP2
#include <stdlib.h>
#include <stdio.h>

int main() {
    int lista[] = {0,1,2,3,4,5,6,7,8,9};
    //int*[] listaEnd[] = &lista;

    for(int i = 0; i < 10; i++) {
        printf("Endereço de memória %d: %p\n", i, &lista[i]);
    }
    printf("Endereço padrão: %p\n", &lista);

    //
    double* precos = (double*) malloc(sizeof(double)*4);


    return 0;
}