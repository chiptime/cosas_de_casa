#include <stdlib.h>
#include <stdio.h>

int main(){

    int num = 0x1234;


    FILE *tubo = fopen("b.dat","wb");
    fwrite(&num, sizeof(int), 1, tubo);

    fclose(tubo);

    return EXIT_SUCCESS;
}
