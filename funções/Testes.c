#include <stdio.h>
#include <math.h>

//#define PI 3.14159

void areaCasa() {
    float lateral = 11;
    float cquarto = 7;
    float areaq;
    float areas;
    float areat;
    printf("Programa para cálculo da area da casa\n");
    areas = lateral*lateral;
    printf("A área da sala é %f\n", areas);
    areaq = cquarto*(lateral/2);
    printf("A área do quarto é %f\n", areaq);
    printf("A área do banheiro é %f\n", areaq);
    areat = areas + 2*areaq;
    printf("A área total é %f\n", areat);
}

double areaPiscina() {
    double raio = 2;

    double area = M_PI * pow(raio,2);
    return(area);
}

int main() {
    messageLog();
    double areap;
    areaCasa();

    areap = areaPiscina();
    printf("A área da piscina é %f\n", areap);

    return 0;
}
