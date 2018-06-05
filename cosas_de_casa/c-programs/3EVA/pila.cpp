#include <stdio.h>
#include <stdlib.h>

#define N 6

#ifndef NODEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

typedef struct{
    int cima;
    int data[N];
}Pila;


bool push(Pila *pushing, int dato){
    if(pushing->cima >= N)
        return false;

    pushing->data[pushing->cima++] = dato;
    DEBUG("--> %i\n",dato);
    return true;
}

int pop(Pila *poping){
    poping->cima--;

    DEBUG("<-- %i\n", poping->data[poping->cima]);
    return poping->data[poping->cima];
}

int main(){
    int datos;
    Pila pila;
    push(&pila, 3);

    pop(&pila);

    return EXIT_SUCCESS;
}
