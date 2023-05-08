#include <stdio.h>

//WHILE

int retangulo(int a, int b) {
    int largura = a;
    int altura = b;

    while(altura > 0) {
        largura = a;

        while(largura > 0) {
            printf("#");

            largura = largura - 1;
        }

        altura = altura - 1;
        printf("\n");
    }
}



int main() {
    int altura, largura;

    printf("Dẽ o valor de uma largura e de uma altura: ");
    scanf("%i %i", &largura, &altura);

    retangulo(largura, altura);

    return 0;
}