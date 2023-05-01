#include <stdio.h>

int ispar(int n) {
    return n % 2 == 0 ? 1 : 0;
}

int main() {
    int a, b;
    int res_a, res_b;

    printf("Entre com dois números: ");
    scanf("%d %d", &a, &b);

    printf("a = %d; b = %d \n", a, b);

    ispar(a) ? printf("O valor de a é par!\n") : printf("O valor de a é impar!\n");
    ispar(b) ? printf("O valor de b é par!\n") : printf("O valor de b é impar!\n");

    return 0;
}