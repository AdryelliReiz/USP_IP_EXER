#include <stdio.h>
#include <stdlib.h>

/*struct casa
{
    float lateral;
    float cquarto;
     
};*/

typedef struct auxCasa {
    float lateral;
    float cquarto;
}  casa;

typedef struct auxPic {
    float raio;
} piscina;

typedef struct aucCaba {
    casa cas;
    piscina pis;
} cabana;

typedef struct auxP {
    int cpf;
    //conjuge do tipo referencia para o struct
    struct auxP* conjuge;
} Pessoa;


int main() {
    casa c1;
    c1.lateral = 11;
    c1.cquarto = 15;

    piscina p1;
    p1.raio = 3.5;

    cabana cab1;
    cab1.cas = c1;
    cab1.pis = p1;
    cab1.cas.lateral = 12;

    Pessoa p1;
    p1.cpf = 12345;
 
    Pessoa* p2 = (Pessoa*) malloc(sizeof(Pessoa));
    p2->cpf = 56789;

    Pessoa p3;
    p3.cpf = 44444;

    p1.conjuge = p2;
    p2->conjuge = &p1;
    p3.conjuge = NULL;

    return 0;
}