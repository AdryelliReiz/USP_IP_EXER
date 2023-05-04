#include <stdio.h>

int main() {
    int a, b;
    
    printf("Entre com dois números: ");
    scanf("%d %d", &a, &b);
    printf("a = %d; b = %d \n", a, b);

    a % 2 
        ? printf("O valor de a é impar!\n") 
        : printf("O valor de a é par!\n");
    b % 2 
        ? printf("O valor de b é impar!\n") 
        : printf("O valor de b é par!\n");

    return 0;

    if(!0) {
        printf("passa");
    }
}