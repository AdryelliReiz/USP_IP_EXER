#include <stdio.h>

void bolha(int v[], int tam) {
    int ult, aux, i, i2;
    for (ult = tam - 1; ult > 0; ult--) {
        printf("Faltam %i interações\n", ult);
        for (i = 0; i < ult; i++) {
            aux = v[i];
            if(aux > v[i+1]) {
                v[i]= v[i + 1];
                v[i + 1] = aux;
            }
        }
        i = 0;
        for (i2 = 0; i2 < tam; i2++) {
            printf("%i ", v[i2]);
        }
        printf("\n");
    }
}

int main() {
    int valores[10] = {9,3,8,2,7,1,6,4,5};

    bolha(valores, 10);

    return 0;
}