#include <stdio.h>

//função que converte para número binário
void converterInteiroParaBinario(int numeroInput) {
    //resultado da divisão
    int restante = numeroInput;
    //index
    int i = 0;
    //lista dos numeros binarios
    int binario[32];

    while(restante > 0) {
        binario[i] = restante % 2;
        restante = restante / 2;
        i++;
    }

    printf("O binário de %i é ", numeroInput);
    //percorre a lista de binario para imprimir em ordem inversa
    for(int x = i - 1; x >= 0; x--) {
        printf("%i", binario[x]);
    }
    printf("\n");

    return;
}

int main() {
    int numeroInput;

    printf("Programa que converte números inteiros em binário!\n");
    printf("Escolha um número inteiro: ");
    //pede um input para o usuário
    scanf("%i", &numeroInput);
    
    //executa a função acima
    converterInteiroParaBinario(numeroInput);

    return 0;
}