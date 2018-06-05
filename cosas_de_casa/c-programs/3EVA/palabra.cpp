#include <stdio.h>
#include <stdlib.h>

int main(){
    char *num;

    FILE *pf = fopen("b.txt", "rb");
    fread(&num, sizeof(*num), 1, pf);
    printf("Leido: %s \n", num);


    fclose(pf);

    return EXIT_SUCCESS;
}

