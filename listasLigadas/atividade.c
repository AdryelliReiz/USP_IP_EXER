#include <stdio.h>
#include <string.h>

typedef struct aux
{
    float nota;
    char nome[30];
} estudanteIP;

void sortNotaIP(estudanteIP turma[], int tam) {
    int ult, i, i2;
    estudanteIP aux;
    for (ult = tam - 1; ult > 0; ult--) {
        printf("Faltam %i interações\n", ult);
        for (i = 0; i < ult; i++) {
            aux = turma[i];
            if(aux.nota > turma[i+1].nota) {
                turma[i] = turma[i + 1];
                turma[i + 1] = aux;
            }
        }
    }

    for (i2 = 0; i2 < tam; i2++) {
        printf("Nome: %s    ||  ", turma[i2].nome);
        printf("Nota: %02.02f\n", turma[i2].nota);
    }
    printf("\n");
}

int main() {
    char entrada[30]; 
    estudanteIP turma02[67];
    int i = 0;

    strcmp(entrada, "");

    while( i < 67) {
        printf("Entre com o nome: ");
        scanf("%s", entrada);

        if(strcmp(entrada, "fim")) {
            strcpy(turma02[i].nome, entrada);

            printf("Entre com a nota do aluno: ");
            scanf("%f", &turma02[i].nota);
        } else break;

        i++;
    }

    sortNotaIP(turma02, i);

    return 0;
}