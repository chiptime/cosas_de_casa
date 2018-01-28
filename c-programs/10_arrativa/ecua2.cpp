#include <stdio.h>
#include <stdlib.h>

#define n 3
#define N 2
double xa,ya,ra,xb,yb,rb;
double a[N][n] = {
    {xa,ya,ra},
    {xb,yb,rb}
};

double scanear_ecua(){

      char    incognita[n] = {'x','y','r'};
      for(int f=0;f<N;f++)
        for(int c=0;c<n;c++){
            printf("Introduce el numero de la ecuacion %i, incognita %c: \n", f+1, incognita[c]);
            scanf("%lf",&(a[f][c]));
        }

}

void imprimir_ecua(double a[N][n]){
    printf("\n");
    for(int f=0;f<N;f++){
        for(int c=0;c<n;c++)
            printf("%6.2lf", a[f][c]);
        printf("\n");
    }
    printf("\n");
}

double 

int main(){

    scanear_ecua();
    imprimir_ecua(a);

    return EXIT_SUCCESS;
}

