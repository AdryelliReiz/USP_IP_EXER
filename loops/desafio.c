#include <stdio.h>

int main() {
    int n, s;

    printf("Programa que mostra se um número é primo ou não!\n");
    printf("Escolha um número:");
    scanf("%d", &n);

    s = n - 1;
    while(s > 1) {
        
        if(n % s == 0) {
            printf("O número %d não é primo\n", n);

            return 0;
        }

        s--;
    }

    printf("O número %d é primo\n", n);

    return 0;
}