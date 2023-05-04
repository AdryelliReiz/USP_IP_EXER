#include <stdio.h>

double valor(double area) {
    if(area >= 0) {
        return(area*2);
    } else {
        return -1;
    }
}

int main() {
    double dobro;
    double numero;

    printf("Digite um número: \n");
    scanf("%lf", &numero);

    dobro = valor(numero);

    if(dobro >= 0) printf("O valor %lf é positivo e seu dobro é %lf!\n", numero, dobro);
    else printf("Valor negativo!\n");

    return 0;
}