#include <stdio.h>
#include <stdlib.h>

int eleccion;

int opcion(int numero){
    if(((eleccion) > 0) && ((eleccion) < 6)){
        printf("Tu numero es: %i\n", eleccion);
        return EXIT_SUCCESS;
    }
    else
        printf("No me vale ese numero\n");

}
int main(){

    do{
    printf("Dime un numero del 1 al 5\n");
    scanf(" %i", &eleccion);
    }while(opcion(eleccion));


return EXIT_SUCCESS;

}
