#include <stdio.h>
#include <stdlib.h>
#define filas 4
#define columnas 4

int cuadrado(){

    for(int i = 0; i < filas; i++){
        for(int i = 0; i < columnas; i++){
        printf("*");
        }
    printf(" \n");
    }
}

int main(){

    int i, j;

    for (i = 1; i <= filas; i++){
        for(j = 1; j <= columnas ; j++)
            if (i == 1 || i == filas || j == 1 || j == columnas)
                printf("*");
            else
                printf(" ");

        printf("\n");
    }


    return EXIT_SUCCESS;

}
