#include <stdio.h>
#include <stdlib.h>

#define C 3
#define N 2
double xa,ya,ra,xb,yb,rb;
double a[N][C] = {
    {xa,ya,ra},
    {xb,yb,rb}
};

double scanear_ecua(){

    char    incognita[C] = {'x','y','r'};
    for(int f=0;f<N;f++)
        for(int c=0;c<C;c++){
            printf("Introduce el numero de la ecuacion %i, incognita %c: \n", f+1, incognita[C]);
            scanf("%lf",&(a[f][c]));
        }

}

void imprimir_ecua(double a[N][C]){
    printf("\n");
    for(int f=0;f<N;f++){
        for(int c=0;c<C;c++)
            printf("%6.2lf", a[f][c]);
        printf("\n");
    }
    printf("\n");
}

void intercambia(double a[N][C], int f1, int f2) {
        double copia;
            for (int c=0; c<C; c++){
                        copia = a[f1][c];
                                a[f1][c] = a[f2][c];
                                        a[f2][c] = copia;
                                            }
}


int diagonaliza(double a[N][C], double coef[N]){
    double k;
    int cima = 0;
    imprimir_ecua(a);

    for (int n=0; n<N; n++){
        for (int f=n; f<N; f++){
            coef[cima] = k = a[n][n];
            if (k)
                break;
            if (f == N-1)
                return 0;
            intercambia(a, n, f+1);
            coef[cima] *= -1;
        }
        cima++;
        for (int col=0; col<N; col++)
            a[n][col] /= k;
        for (int f=n+1; f<N; f++){
            k = a[f][n];
            for (int col=0; col<C; col++)
                a[f][col] -= (a[n][col] * k);
        }
        imprimir_ecua(a);
    }
    return 1;
}


int main(){

    scanear_ecua();
    imprimir_ecua(a);
    double   coef[N], det=1;
        if (!diagonaliza(a, coef)){
                    fprintf(stderr, "Rango menor que 3.\n");
                            det = 0;
                                }

            for (int i=0; i<N; i++)
                        det *= coef[i];

                printf("Determinante: %lf\n", det);


    return EXIT_SUCCESS;
}

