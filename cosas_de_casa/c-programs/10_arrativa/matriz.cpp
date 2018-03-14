#include <stdio.h>
#include <stdlib.h>

#define N 3

int main(){

    int sum = 0;
    int a[N][N] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (int desplaz=0;desplaz<N;desplaz++){
        int diag=1;
        for (int elem=0;elem<N;elem++)
            diag *= a[elem][(elem+desplaz)%N];
        printf("diag = %i\n", diag);
        sum +=diag;
    }

    for (int desplaz=0;desplaz<N;desplaz++){
        int diag=1;
        for (int elem=0;elem<N;elem++)
            diag *= a[(desplaz+elem)%N][N-1-elem];
         printf("diag = - %i\n", diag);
       sum -=diag;
    }
        printf("Determinante = %i\n", sum);



    return EXIT_SUCCESS;
}

