#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int main(){

    char palabra[N];
    int longitud;
    char **l = NULL;
    int NumPalabras;

    printf("¿Cuantas palabras quieres?\n");
    scanf(" %i", &NumPalabras);

    for(int c=0;c<NumPalabras;c++){

        if(c<1)
            printf("Dame una palabra\n");

        else
            printf("Give me other: \n");

         scanf(" %[^\n]", &palabra);
         longitud = strlen(palabra);
         l = (char **) realloc(l, (c+1) * sizeof(char  *));
         *(l+c) =(char *) malloc (longitud/* + 1*/);
         strcpy(*(l+c), palabra);


         printf("Toma tu palabra: %s\n", *(l+c));
         printf(" %i\n\n", c);
    }

         for(int pal=0;pal<NumPalabras;pal++){
             if(pal<1)
                 printf("Mi lista es: \n");
         printf(" %s\n", *(l+pal));
         }
    free(l);
    for(int c=0;c<NumPalabras;c++)
        free(*(l+c));
    return EXIT_SUCCESS;

}
