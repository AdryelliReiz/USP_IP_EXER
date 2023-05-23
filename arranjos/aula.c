#include <stdio.h>
#include <stdlib.h>

#define ALVENARIA 0
#define VINIL 1
#define FIBRA 2
#define PLASTICO 3

int main() {
    const double P_ALVENARIA = 1500;
    const double P_VINIL = 1100;
    const double PFIBRA = 750;
    const double P_PLASTICO = 500;

    double precos[] = {1500, 1100, 500};

    
    //double* precos = (double*)malloc(sizeof(double)*4);



    return 0;
}

//então o ponteiro de um array vai apontar para um conjunto de slots ou só para um slot?
//R: aponta só para o primeiro slot (primeiro indicie do array)