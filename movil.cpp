#include <stdio.h>
#include <stdlib.h>


typedef struct {

    double x;
    double y;
}Coordenada;


typedef struct{
    Coordenada pos;
    Coordenada vel;
    Coordenada acel;
    void (*haz) (Movil);

}Movil;


typedef struct{
    double data[N];
    int cima;
}Pila;


void push(Pila *push, double dato){
    push->data[push->cima] = dato;
    printf("El dato introducido es %lf", dato);
    cima++;

}

void pop(Pila *pop){

    cima--;
   //pop->data[pop->cima];
   printf("La cima es = %i\n,Su dato es = %lf ", pop->cima,pop->data[pop->cima] );

}

void hola( Movil *pos){

    pos->pos.x = 1;
    pos->pos.y = 1;


    if( pos->pos.x >=1, pos->pos.y >= 1 ){
        printf("hola");

    }
    else
        printf("adios");

}


void mover(Movil *mover){

    pos->pos.x = pos->vel.x + pos->acel.x;

    pos->pos.y = pos->vel.y + pos->acel.y;
}

void imprimir(Movil imp){
    printf(" La posicion x = %lf, La posicion y = %lf ", pos->pos.x, pos->pos.y );
}



typedef struct{
  char *nombre;
  void (*op) (Movil);
}Funciones;

enum cual_es{
    push,
    pop,
    hola,
    mover,
    imprimir
}

int main(){

    Movil barco;
    Funciones funs[] = {
//        {"push", &push},
//        {"pop" , &pop},
        {"hola", &hola},
        {"mover",&mover},
        {"imprimir", &imprimir},
    };
    int seleccion;
    while(1){

        printf("Introduce los datos del barco:\n x,y,funcion\n %s", &funs);
        scanf(" %lf, %lf, %i", barco->pos.x, barco->pos.y, seleccion);

        push(&barco.pos.x,seleccion);

        push(&barco.pos.y,seleccion);


        switch(seleccion){
            case hola:
                push(hola,&seleccion);
                break;
            case mover:
                push(mover,&seleccion);
                break;
            case imprimir:
                push(imprimir,&seleccion);
                break;
       }
    }







    return EXIT_SUCCESS;
}
