#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//for getch

#include <unistd.h>
#include <locale.h>
#include <ncurses.h>

#define fila  30
#define columna 100

#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)

#define LESSVEL 0.5

char matriz[fila][columna];

double xbola = 8;
double ybola = 8;

int arrow;


//////bola

double xvel = 1;
double yvel = 1;

double xdireccion = 1;
double ydireccion = 1;


/////Palas

double xpala =  20;
double ypala =  10;
double xpala1 = 80;
double ypala1 = 10;





void dibujar_Marco();


void movimiento_Bola() {

    //                Movimiento de la bola
    //   mvprintw(xbola,ybola); printw("   ");
    mvprintw(ybola,xbola,"(_)");

    xbola = xbola +   xdireccion*LESSVEL  ;// + (xvel*LESSVEL);
    ybola = ybola +   ydireccion*LESSVEL  ;// + (yvel*LESSVEL);


    if ( ((xbola == xpala)||(xbola+1 == xpala)||(xbola+2 == xpala)) && ((ybola == ypala)||(ybola == ypala+1)||(ybola == ypala+2)||(ybola == ypala+3)||(ybola == ypala+4)) ){
        xdireccion *= -1;
        ydireccion *= -1;
    }
    if ( ((xbola == xpala1)||(xbola+1 == xpala1)||(xbola+2 == xpala1)) && ((ybola == ypala1)||(ybola == ypala1+1)||(ybola == ypala1+2)||(ybola == ypala1+3)||(ybola == ypala1+3)) ){
        xdireccion *= -1;
        ydireccion *= -1;
    }


    if((xbola<=1)|| (xbola>=99))
        xdireccion *= -1;
    if((ybola<=1) || (ybola>=29))
        ydireccion *= -1;



//    mvprintw(10,8, "La bola esta en: x = %lf,\n x = %lf,  \n y =  %lf", xbola,xbola+2,ybola);            // situacion de la bola
    //    mvprintw(10,9,"%c", arrow);            // situacion de la bola
    refresh();
}
void pala1() {
    mvprintw(10,20,"%c",arrow);
    mvprintw(ypala,   xpala,"█");
    mvprintw(ypala+1, xpala,"█");
    mvprintw(ypala+2, xpala,"█");
    mvprintw(ypala+3, xpala,"█");
    mvprintw(ypala+4, xpala,"█");
    refresh();


}

void pala2() {
    mvprintw(ypala1,   xpala1,"█");
    mvprintw(ypala1+1, xpala1,"█");
    mvprintw(ypala1+2, xpala1,"█");
    mvprintw(ypala1+3, xpala1,"█");
    mvprintw(ypala1+4, xpala1,"█");

    refresh();
}


void iniciar_Curses(){
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    halfdelay(1);
    noecho();
    cbreak();
    nodelay(stdscr,true);
}

void finalizar_Curses(){
    curs_set(1);
    endwin();
}
int teclas(double yy, double yy1, double *y, double *y1){
//    arrow = getch();

//    printw("Pala esta en %lf y la direccion de la Pala es %lf", yy, *y);
 //   printw("Pala esta en Y = %lf\n Y = %lf e X = %lf",  yy,yy+4, xpala);

    switch(getch()){//arrow){

        case KEY_UP:
            if(yy1>=minf+2)
                //          if(ypala1>=minf+2)
                *y1-=1;
            break;

        case KEY_DOWN:
            if(yy1+4<=maxf-2)
                //            if(ypala1+4<=maxf-2)
                *y1+=1;
            break;

        case 'w':
            if(yy>=minf+2)
                //            if(ypala>=minf+2)
                *y-=1;
            break;
        case 's':
            if(yy+4<=maxf-2)
                //           if(ypala+4<=maxf-2)
                *y+=1;
            break;
        case 'p':
            getchar();
            break;
    }

    return arrow;
}

int main() {
    /*TODO pasar todo a double y comprobar que funcione bien*/
    setlocale(LC_ALL,"");
    iniciar_Curses();


    char matriz[fila][columna];

    for(int i=0;i<fila;i++) {
        for(int j=0;j<columna;j++) {
            matriz[i][j] = 'x';
        }
    }
    while(teclas(ypala, ypala1, &ypala, &ypala1) != KEY_BREAK){
        clear();
        dibujar_Marco();
        pala1();
        pala2();
        movimiento_Bola();
//        teclas(ypala, ypala1, &ypala, &ypala1);
        usleep(20000*1.2);
    }
    finalizar_Curses();
    return 0;
}



void dibujar_Marco(){

    /*Dibujar marco*/


    for(int f=0; f<fila;f++) {
        for(int c=0;c<columna;c++) {
            if(((f) == minf) || ((f) == maxf)){
                if( ((f==minf)&&(c==minc)) || ((f==minf)&&(c==maxc)) || ((f==maxf)&&(c==minc)) || ((f==maxf)&&(c==maxc)) )
                    printw("%cx", matriz[f][c] );
                else printw("x");
            }
            else
                if(((f) >= (minf)/*2*/) || ((f) <= (maxf)/*8*/)) {
                    if( (c<(minc+1)) ||(c>(maxc-1)) )
                        printw("l%c",matriz[f][c]);
                    else
                        printw(" ");
                }


        }
        printw("\n");
    }
    refresh();

}


