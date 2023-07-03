#include <stdio.h>

int buscaSeq(int arr[], int tam, int el) {
    int i;
    for (i = 0; i < tam; i++) {
        if(arr[i] == el) return -1;
        if(arr[i] > el) break;
    }
}

int buscaBin(int arr[], int tam, int el) {
    int fim = tam - 1;
    int ini = 0;

    while(ini <= fim) {
        int meio = (fim + ini) / 2;

        if(arr[meio] < el) 
            ini = meio + 1;
        else {
            if(arr[meio] > el) 
                fim = meio -1;
            else return meio;
        }
    }

    return -1;

}

int main() {
    


    return 0;
}