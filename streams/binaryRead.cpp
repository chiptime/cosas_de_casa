#include <stdlib.h>
#include <stdio.h>

int main(){

    int num;// = 0x1234;


    FILE *tubo = fopen("b.dat","rb");
    fread(&num, sizeof(int), 1, tubo);
//    fwrite("leido.txt", "");
    fclose(tubo);

    printf("Ha leido %i (%Xh)\n", num, num);
    return EXIT_SUCCESS;
}
