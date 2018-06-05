#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;

    FILE *pf = fopen("b.int", "rb");
    fread(&num, sizeof(int), 1, pf);
    printf("Leido: %i (%Xh) \n", num, num);


    fclose(pf);

    return EXIT_SUCCESS;
}

