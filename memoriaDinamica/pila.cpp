#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct{

  int cima;
  int data[N];
}Pila;


void push(Pila *porReferencia, int dato){//, Pila porValor){
  porReferencia->data[porReferencia->cima]    = dato;
  porReferencia->cima++;
  printf("--> %i\n",dato);
}

int pop(Pila *porReferencia){
  porReferencia->cima--;
  printf("<-- %i\n", porReferencia->data[porReferencia->cima]);

  return porReferencia->data[porReferencia->cima];

}


int main(){
    Pila paraDatos;
    int numero = 0;

    push(&paraDatos,3);
    pop(&paraDatos);

    return EXIT_SUCCESS;
}
