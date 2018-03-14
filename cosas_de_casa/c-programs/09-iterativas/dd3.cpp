#include <stdio.h>
#include <stdlib.h>
#define l 5

/*int x, f;*/
/*
int f;
int diagonal_inversa(int x){
    for(x=0;x>l;x--)
        return x;
}*/

int main(){

//    int x = 6;
    system("toilet --gay -fpagga D+D=W");
    printf("Dime cuanto quieres de lado: \n");
    //    scanf(" %i", &l);
    for(int f=0;f<l;f++){
        for(int t=0;t<l;t++)
            for(int c=0, x=l;c<l;c++,x--){

               /* printf("f = %i,  t = %i\t", f,t);
                printf("c = %i,  x = %i", c,x);*/
                if(f == c || f  == l - c)
                    printf("*");
                else
                    printf(" ");
            }
        printf("\n");


    }


    return EXIT_SUCCESS;
}
