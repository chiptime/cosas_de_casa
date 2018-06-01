#include <stdlib.h>
#include <stdio.h>
#define N 10
int factorial(int numero, int array[]){
    static int i = 0;
    array[N];
        if(numero == 0)
            return 1;

    if(numero == 1)
        return 1;
    array[i++] = numero * 1;
    numero--;

    return numero * factorial(numero - 1);
}


int main (){


    return EXIT_SUCCESS;
}
