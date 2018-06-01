#include <stdio.h>
#include <stdlib.h>

typedef struct(){
    int x, y;
}Coordenadas;

void escribir(Coordenadas *referencia, int numerox, int numeroy){
    referencia-> x = numerox;
    referencia-> y = numeroy;
    printf("x:%i y:%i \n", numerox, numeroy);//datos introducidos
}

void mostrar(){
    
}


int main(){
    Coordenadas coordenadas;
    return EXIT_SUCCESS;
}
