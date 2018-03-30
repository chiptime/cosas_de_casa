#include <stdio.h>
#include <stdlib.h>

void rellenar(int *n1, int *n2){

        printf("Numero 1: ");
        scanf(" %i", n1);
        printf("Numero 2: ");
        scanf(" %i", n2);
    }


int main(){

    int v1,v2;

   rellenar(&v1,&v2);
        printf("Numeros: \n\t%i\n\t%i\n", v1,v2);


return EXIT_SUCCESS;

}

