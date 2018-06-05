#include <stdio.h>
#include <stdlib.h>

int main(){
    char num[20];

    FILE *pf = fopen("b.txt", "rt");
    fread(&num, sizeof(num), 1, pf);
    printf("Leido: %s \n", num);


    fclose(pf);

    return EXIT_SUCCESS;
}

