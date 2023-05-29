#include <stdio.h>

//Exercicio 01
int exercicio01() {
    double centimetros, polegadas, pes, jardas;

    printf("Entre com um valor em centímetros: ");
    scanf("%lf", &centimetros);

    polegadas = centimetros * 2.54;
    pes = polegadas * 12;
    jardas = pes * 3;

    printf("Valores convertidos!\nPolegadas = %lf\nPés = %lf\nJardas = %lf\n", polegadas, pes, jardas);

    return 0;
}

//Exercicio 03
double areaDoRetangulo(double altura, double largura){
    double area = altura * largura;
    //Exercicio 04
    long unsigned int bytes = sizeof(altura) + sizeof(largura);
    printf("%ld bytes são usados como parametros\n", sizeof(bytes));
    return area;
}

double areaDoQuadrado(double lado) {
    return areaDoRetangulo(lado, lado);
}

int exercicio03() {
    double lado;
    double area;

    printf("Entre com um valor referente ao lado do quadrado:");
    scanf("%lf", &lado);

    
    area = areaDoQuadrado(lado);
    printf("A área do quadrado é %lf\n", area);

    return 0;
}

//Exercicio 05
int exercicio05() {
    double lado1, lado2, lado3;

    printf("Informe os 3 lados do triângulo!\n");
    printf("Lado 01:");
    scanf("%lf", &lado1);
    printf("Lado 02:");
    scanf("%lf", &lado2);
    printf("Lado 03:");
    scanf("%lf", &lado3);

    if(lado1 + lado2 <= lado3 || lado1 + lado3 <= lado2 || lado2 + lado3 <= lado1) {
        printf("Esse triângulo não é válido!\n");
        return 0;
    } else printf("Esse triângulo é válido!\n");

    if(lado1 == lado2 && lado2 == lado2) {
        printf("Esse triângulo é equilátero!\n");
    } if(lado1 == lado2 && lado1 != lado3 || lado1 == lado3 && lado1 != lado2 || lado2 == lado3 && lado2 != lado1) {
        printf("Esse triângulo é Isósceles!\n");
    } if(lado1 != lado2 && lado1 != lado3 && lado2 != lado3) {
        printf("Esse triângulo é escaleno!\n");
    }

    return 0;
}

//exercicio 6
int exercicio06() {
    int numero;
    int somaDosAlgarismos;

    printf("Escolha um número:");
    scanf("%d", &numero);

    while (numero >= 10)
    {
        somaDosAlgarismos = somaDosAlgarismos + (numero % 10);
        numero = numero / 10;
    }
    somaDosAlgarismos = somaDosAlgarismos + numero;

    printf("A soma dos algarismos é %d\n", somaDosAlgarismos);
    

    return 0;
}

int main() {
    exercicio01();

    //exercicio ok02
    //o compilador é resposável por traduzir o código-fonte em escrito em linguagem C
    //para uma linguagem de maquina compreendida pelo computador.

    exercicio03();

    exercicio05();

    exercicio06();

    return 0;
}