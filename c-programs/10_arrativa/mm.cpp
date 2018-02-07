#include <stdio.h>
#include <stdlib.h>

#define F 2
#define C 3

int main(){

    int a[F][C] = {
        {1,1,1},
        {2,4,6}
    };
    int b[C][F] = {
        {7,10},
        {8,11},
        {9,12}
    };
    int k[F][F] = {
        {0,0},
        {0,0}
    };
    int mm[F][F] = {
        {0,0},
        {0,0}
    };

    for(int f=0;f<F;f++){
        for(int c=0;c<C;c++){
        for(int cc=0;cc<F;cc++)
            k[f][c] += (a[f][cc] * b[cc][c]);

        }



    }
    printf("El total sera: %i\n", k[1][3]);

    return EXIT_SUCCESS;
}

