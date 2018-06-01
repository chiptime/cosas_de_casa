#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 8
#define MAX 50


int main(){


    char buffer[N];
    char *palabra = NULL;
    int longitud;


    printf("Dime una palabra: \n");
    fgets(buffer, N , stdin);

    longitud = strlen(buffer);
    palabra = (char *) malloc( longitud + 1 );
    strcpy(palabra, buffer);

//    for(int i=0; i<MAX; i++)
    printf("%s\n", palabra);

    free(palabra);




    return EXIT_SUCCESS;
}
