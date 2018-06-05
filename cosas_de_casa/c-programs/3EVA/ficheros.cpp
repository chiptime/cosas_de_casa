#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero = 10;

    FILE *stream = fopen("a.int","w+");
    fwrite(&numero,sizeof(int),1,stream);
    fclose(stream);
    return EXIT_SUCCESS;
}

