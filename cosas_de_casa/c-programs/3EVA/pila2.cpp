#include <stdio.h>
#include <stdlib.h>

#ifndef NODEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 6

typedef struct{
    int data[N];
    int cima;
}Pila;



bool push(Pila *meter, int numero){
    if(meter->cima >= N)
        return false;
    meter->data[meter->cima++] = numero;
    DEBUG("--> %i",numero);
    return true;
}

/*int pop(Pila *sacar){
    sacar->cima--;
    DEBUG("<-- %i ",sacar->data[sacar->cima]);

    return sacar->data[sacar->cima];
}*/

int main(){
    int dato;
    Pila pila;
    push(&pila, 3);
//    push(&pila, 3);
  //  push(&pila, 15);
 //   pop(&pila);
  //  push(&pila, 0);
//    push(&pila, 25);

    DEBUG("llega aqui\n");
    return EXIT_SUCCESS;
}
