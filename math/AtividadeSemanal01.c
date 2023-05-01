#include <stdio.h>

int main() {

    int areaSala;
    int areaQuarto;
    int areaBanheiro;
    int areaTotal;

    printf("Programa para cálculo da área da cabana!\n");

    areaSala = 10*10;
    printf("A área da sala é %im²\n", areaSala);

    areaQuarto = 5*7;
    printf("A área do quarto é %im²\n", areaQuarto);

    areaBanheiro = 5*7;
    printf("A área do banheiro é %im²\n", areaBanheiro);

    areaTotal = areaSala + areaQuarto + areaBanheiro;
    printf("A área total da cabana é %im²\n", areaTotal);

    return 0;
}