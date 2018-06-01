#include <stdio.h>
#include <stdlib.h>

bool tieneDivisor(int dividendo, int p_divisor){
    printf("El dividendo actual es: %i\n", p_divisor );
    if( dividendo % p_divisor == 0 && p_divisor > 0)
        return true;
    else
      printf("%i no es un divisor valido\n\n", p_divisor);
//      if(p_divisor == 0)
//          return true;

    return tieneDivisor(dividendo, p_divisor - 1);
//    else
//        printf("No es divisor")
}

void preguntar(int numero1, int numero2, char *listaNumeros){
    printf("Dame un dividendo: \n");
    fgets(listaNumeros, 5, stdin);

    &numero1 = &listaNumeros;

    printf("Dame un divisor: \n");
    fgets(listaNumeros, 5, stdin);

    &numero2 = &listaNumeros;
}

int main() {

    int dividendo;
    int divisor;
    char *lista = NULL;

    preguntar(dividendo,divisor,*lista);





    if(tieneDivisor(dividendo,divisor))
      printf("El %i tiene, al menos, un divisor.\n", dividendo);
    return EXIT_SUCCESS;
}
