#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#define M 30

char DevolverLetra(const char *n){

    printf("%c \n", *n);
    if(*(n+1)  != '\0' )
        DevolverLetra(n + 1) ;

//        return EXIT_SUCCESS;

//    strcpy(&letra);
  //  return DevolverLetra(n + 1) ;
}
void Preguntar(char *lineaChars){
    printf("Escribe una frase: \n ");
///    scanf("%[^\n]", frase);
    fgets(lineaChars, M, stdin);
//    printf(" %s \n", lineaChars);
}
int main(){
    char frase[M];

    Preguntar(frase);

    char *fra = frase;
    DevolverLetra(fra);



    return EXIT_SUCCESS;
}
