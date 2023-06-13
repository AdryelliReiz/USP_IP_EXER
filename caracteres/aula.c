#include <stdio.h>

int main () {
    char c;

    c = 'M';
    //passa para minusculo
    c = c - 'A' + 'a';
    //passa para maiusculo
    c = c - 'a' + 'A';

    printf("%c\n", c);

    for(char i = 0; i <= 122; i++) {
        printf("%c", i);
    }
    printf("\n");

    return 0;
}