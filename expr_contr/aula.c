#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;

    printf("%d\n", a++);
    printf("%d\n", ++b);
    printf("%d\n", a);
    printf("%d\n", b);

    for (int i = 10; i > 0; i++) {
        printf("%d\n", i);

        printf("new %d\n", --i);
    }

    return 0;
}