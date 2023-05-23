#include <stdio.h>

int main() {
    long long unsigned int long_int;

    printf("Tamanho do long long int: %lu (bytes)\n",sizeof(long long unsigned int));
    
    if (1 == scanf("%llu", &long_int)) {
        printf("Numero lido: %llu\n", long_int);
    }
    
    return 0;
}