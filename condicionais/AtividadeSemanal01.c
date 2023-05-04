#include <stdio.h>

int main() {
    double number01, number02, number03;
    double maiornumero;

    printf("Programa que mostra o maior número dos três escolhidos!\n");
    printf("Escolha três números distintos:");
    scanf("%lf %lf %lf", &number01, &number02, &number03);

    if(number01 >= number02) {
        maiornumero = number01;
    } else {
        maiornumero = number02;
    }

    if(maiornumero < number03) {
        maiornumero = number03;
    }

    printf("O maior dos números escolhidos é %f\n", maiornumero);

    return 0;
}