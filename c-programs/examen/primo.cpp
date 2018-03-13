#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(){

    int matriz[N];

    int numero;
    int divisores;

    for(int i=0;i<N;i++){
        matriz[N] = rand() % 20;
        if(matriz[i]%i==0)
            divisores++;
    }
    if(divisores==2)
        printf(" %lf es primo", &numero);
    else
        printf(" %lf NO es primo", &numero);

return EXIT_SUCCESS;

}
