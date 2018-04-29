#include <stdio.h>
#include <stdlib.h>

int main(){
    double *reserva = NULL;

    reserva = (double*) malloc(sizeof(double));
    *reserva = 3.5;
    reserva = (double*) realloc(reserva, 2*sizeof(double));
    *(reserva + 1) = 7.8;

    free(reserva);
    free(reserva + 1);
    return EXIT_SUCCESS;

}
