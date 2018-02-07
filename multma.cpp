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
            printf("Introduce el numero de la ecuacion %i, incognita %c: \n", f+1, incognita[c]);
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
  /*       for (int col=0; col<N-1; col++)*/
       for (int col=0; col<N+1; col++)
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
    double   coef[N], det=1,Y,X,R;
    if (!diagonaliza(a, coef)){

        det = 0;
    }

/*    (a[1][1] == a[1][2]);*/
    Y = a[1][2];
    a[0][1] *= a[1][2];
    R   =  (a[0][2] -= a[0][1]);
    X   =  (a[0][2] /= a[0][0]);

    printf("Las incognitas son: X = %6.2lf \n Y = %6.2lf \n", X,Y);


    return EXIT_SUCCESS;
}



