#include <stdio.h>
#include <stdlib.h>

#define N 16
#define MAX 6


#ifndef NODEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

int error = 0;
const char *mssg[] = {
    "Todo OK.",
    "Pila vacía.",
    "Pila llena."
};

typedef struct {
    char nombre[N];
    double (*op)(double, double);
} Operacion;

typedef struct {
    int data[MAX];
    int cima;
} Pila;


enum {
    suma,
    resta,
    multi,
    division,
    OPERA
};

bool push(int dato, Pila *pila){
    if (pila->cima >= MAX){
        error = 2;
        return false;
    }
    error = 0;
    pila->data[pila->cima++] = dato;
    DEBUG("--> %i\n",dato);
    return true;
}

int pop(Pila *pila) {
    if (pila->cima == 0){
        error = 1;
        return 0;
    }
    error = 0;
    pila->cima--;
    DEBUG("<-- %i\n", pila->data[pila->cima]);
    return pila->data[pila->cima];
}

double sum(double op2, double op1) { return op1 + op2; }
double res(double op2, double op1) { return op1 - op2; }
double mul(double op2, double op1) { return op1 * op2; }
double div(double op2, double op1) { return op1 / op2; }

int main(){

    bool test = true;
    Pila op, datos;
    double op1, op2;
    char opera;
    Operacion catalogo[] = {
        {"suma",         &sum},
        {"resta",        &res},
        {"multiplacion", &mul},
        {"division",     &div}
    };
    while(test == true){
        printf("Operacion: ");
        scanf(" %lf %c %lf", &op1, &opera, &op2);
        test = push(op2, &datos);
        test = push(op1, &datos);
        printf("Los datos introducidos son: %5.2lf %c %5.2lf\n", op1, opera, op2);
        if(test == true){
            switch(opera) {
                case '+':
                    push(suma, &op);
                    break;
                case '-':
                    push(resta, &op);
                    break;
                case '*':
                    push(multi, &op);
                    break;
                case '/':
                    push(division, &op);
                    break;
                default:
                    printf("El operador no es correcto");
            }
        }
    }
    for(int i=0;i<MAX/2;i++){
        int selector;
        selector = pop(&op);
        double resultado =   catalogo[selector].op( (double) pop(&datos), (double) pop(&datos) );
        //    printf("Operacion: %s \n Resultado: %lf",catalogo[selector].nombre, catalogo[selector].op( (double) (pop(&datos)), (double) (pop(&datos))) );
        printf(" %lf\n", resultado);
    }

    return EXIT_SUCCESS;
}

