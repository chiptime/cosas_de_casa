#include <stdio.h>
#include <stdlib.h>

int main(){
//    char *num = NULL;
    char *num = NULL; //= (char *) malloc(sizeof(char));
    num = (char *) malloc(sizeof(char));

    FILE *pf = fopen("b.txt", "rt");
    fread(num, sizeof(num), 3, pf);
    printf("Leido: %s \n", num);


    fclose(pf);

    return EXIT_SUCCESS;
}

