#include <stdio.h>

int calculador(int arr[], int tam) {
    int i, media, mediana, quartil1, quartil3, soma, inicio, fim;
    inicio = arr[0];
    fim = arr[tam - 1];
    soma = 0;

    for(i = 0; i < tam ; i++) {
        soma += arr[i];
    }

    media = soma / tam;
    mediana = arr[(inicio + fim) / 2];
    quartil1 = arr[(inicio + fim) / 4];
    quartil3 = arr[((inicio + fim) / 4) * 3];

    printf("Media: %i \n", media);
    printf("Mediana: %i \n", mediana);
    printf("Primeiro Quartil: %i \n", quartil1);
    printf("Terceiro Quartil: %i \n", quartil3);

    return 0;
}

int main() {
    int lista[] = {0,1,2,3,4,5,6,7,8,9};

    calculador(lista, 10);

    return 0;
}