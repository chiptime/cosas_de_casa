#include <stdio.h>
#include <stdlib.h>

#define l 5

int main(){

    system("toilet --gay -fpagga TRIANGULO");
    printf("Dime cuanto quieres de lado: \n");
    //    scanf(" %i", &l);
    for(int f=0;f<l;f++){
        for(int t=0;t<l;t++)
            for(int c=t?1:0;c<l;c++)
                if(f == c){
                    printf("*");
                    if(f || c )
                     printf("*");
                }
                else
                    printf(" ");
        printf("\n");


    }


    return EXIT_SUCCESS;
}
