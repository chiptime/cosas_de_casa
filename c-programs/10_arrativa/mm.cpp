#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 2
#define C 3

double a[F][C] = {
        {1,1,1},
        {2,4,6}
    };
    double k[F][F];
void imprimir_ecua(double k[F][F]){
    printf("\n");
    for(int f=0;f<F;f++){
        for(int c=0;c<F;c++)
            printf("%8.2lf", k[f][c]);
        printf("\n");
    }
    printf("\n");
}

int main(){

    double suma = 0;

    double a[F][C] = {
        {1,1,1},
        {2,4,6}
    };
    double b[C][F] = {
        {7,10},
        {8,11},
        {9,12}
    };
    double k[F][F];
    double mm[F][F];
    double mult= 0;


    for(int f=0;f<F;f++){

        int c = 0;
        for(c;c<F;c++){
            k[f][c] = 0;
            for(int cc=0;cc<C;cc++)
                k[f][c] += a[f][cc] * b[cc][c];


        }
        mm[f][c] == k[f][c];


    }
     imprimir_ecua(k);
    return EXIT_SUCCESS;
}

