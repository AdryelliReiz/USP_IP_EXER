#include <stdio.h>

/*
Faixa 1: Até R$ 1.903,98: isento
Faixa 2: De R$ 1.903,99 até R$ 2.826,65: 7,5%
Faixa 3: De R$ 2.826,66 até R$ 3.751,05: 15%
Faixa 4: De R$ 3.751,06 até R$ 4.664,68: 22,5%
Faixa 5: Acima de R$ 4.664,68: 27,5%
*/

int main () {
    double renda, imposto, totalimposto;

    printf("Programa que cálculo seu imposto de renda!\n");

    printf("Digite o seu salário: ");
    scanf("%lf", &renda);

    if (renda <= 1903.98) {
        imposto = 0;
    } if (renda >= 1903.98) {
        imposto = 7.5;
    } if (renda >= 2826.65) {
        imposto = 15;
    } if (renda >= 3751.05) {
        imposto = 22.5;
    } if (renda >= 4664.68) {
        imposto = 27.5;
    }

    if(imposto == 0) {
        printf("Sua renda de R$%lf está insenta de imposto\n", renda);
    } else {
        totalimposto = (renda * imposto) / 100;

        printf("Sua renda de R$%lf possuí taxação de imposto de %lf e seu valor é de R$ %lf\n", renda, imposto, totalimposto);
    }

    return 0;
}