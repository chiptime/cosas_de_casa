#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    double lado,
   	   area,
   	   perimetro;

    system("toilet --gay -fpagga CUADRADO");

    /* Entrada de datos */
    printf("Lado: ");
    scanf(" %u", &lado);
    /* Calculos */
    area = lado * lado;
    perimetro = 4 * lado;
    /* Salida de datos */
    printf( "Area: %d\n" "Perimetro: %d\n", (int)area, (int)perimetro );
    
    return EXIT_SUCCESS;
}


