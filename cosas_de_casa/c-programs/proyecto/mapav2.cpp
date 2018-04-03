#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
//for mygetch
#include <termios.h>
#include <unistd.h>

#include <time.h>


#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)

//#define ARRIBA  "\033[A"
//#define ABAJO  "\033[B"


int fila = 30;
int columna= 100;
int xbola = 50;
int ybola = 15;

void gotoxy(int x, int y){
    int MAX_SCREEN_AREA = 100;
    char essq[MAX_SCREEN_AREA]={0}; // String variable to hold the escape sequence
    sprintf(essq, "\033[%d;%df", y,x); //\033 = ESC, [X;X valores fila, columna, "f" para indicar que es localizacion espacial
    printf("%s", essq); //imprime la linea de texto en esa localizacion
}

int mygetch( ) {
    struct termios oldt,
                   newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
/*
   void movimiento_bola(){
   gotoxy(xbola,ybola); printf("(_)");
//gotoxy(xbola,ybola); printf(" ");
ybola++;
if(ybola > maxf){
xbola = rand() % 50 +4;
ybola = 4;
}

}*/

int main() {
    /*TODO pasar todo a double y comprobar que funcione bien*/

    int x = 5;
    int y = 5;
    char tecla;



    //////bola

    double xvel = 1.5;
    double yvel = 1.5;

    int xdireccion = 1;
    int ydireccion = 1;


    /////Palas

    int xpala = 20;
    int ypala = 10;

    int xpala1 = 80;
    int ypala1 = 10;

    char flecha;



    char matriz[fila][columna];

    for(int i=0;i<fila;i++) {
        for(int j=0;j<columna;j++) {
            matriz[i][j] = 'x';
        }
    }





    do{
        __fpurge(stdin);



        /*Dibujar marco*/
        for(int f=0; f<fila;f++) {
            for(int c=0;c<columna;c++) {
                if(((f) == minf) || ((f) == maxf)){
                    if( ((f==minf)&&(c==minc)) || ((f==minf)&&(c==maxc)) || ((f==maxf)&&(c==minc)) || ((f==maxf)&&(c==maxc)) )
                        printf("%cx", matriz[f][c] );
                    else printf("x");
                }
                else
                    if(((f) >= (minf)/*2*/) || ((f) <= (maxf)/*8*/)) {
                        if( (c<(minc+1)) ||(c>(maxc-1)) )
                            printf("l%c",matriz[f][c]);
                        else
                            printf(" ");
                    }


            }
            printf("\n");
        }




        //                Movimiento de la pelota
        gotoxy(xbola,ybola); printf("(_)");

        xbola = xbola + ( xvel * xdireccion );
        ybola = ybola + ( yvel * ydireccion );




        if((xbola<=5) || (xbola>=99))
            xdireccion *= -1;
        if((ybola<=3) || (ybola>=29))
            ydireccion *= -1;

        gotoxy(55,8);printf("%d , %d", xbola,ybola);            // situacion de la bola


        gotoxy(55,5);printf("%d , %d", xpala,ypala);
                  gotoxy(xpala,ypala);
                  printf(" ");
                  gotoxy(xpala,ypala+1);
                  printf(" ");
                  gotoxy(xpala,ypala+2);
                  printf(" ");
                  gotoxy(xpala,ypala+3);
                  printf(" ");

                  gotoxy(xpala,ypala);
                  printf("█");
                  gotoxy(xpala,ypala+1);
                  printf("█");
                  gotoxy(xpala,ypala+2);
                  printf("█");
                  gotoxy(xpala,ypala+3);
                  printf("█");

                 tecla=mygetch();

                  if(tecla=='w' && ypala>=minf+3)
                  ypala--;
                  if(tecla=='s' && ypala+3<=maxf-1)
                  ypala++;

                  gotoxy(xpala1,ypala1);
                  printf(" ");
                  gotoxy(xpala1,ypala1+1);
                  printf(" ");
                  gotoxy(xpala1,ypala1+2);
                  printf(" ");
                  gotoxy(xpala1,ypala1+3);
                  printf(" ");

                  gotoxy(xpala1,ypala1);
                  printf("█");
                  gotoxy(xpala1,ypala1+1);
                  printf("█");
                  gotoxy(xpala1,ypala1+2);
                  printf("█");
                  gotoxy(xpala1,ypala1+3);
                  printf("█");

        if (mygetch() == '\033') {
            mygetch();
        flecha=mygetch();
        if(flecha=='A' && ypala1>=minf+3)
            ypala1--;
        if(flecha=='B' && ypala1+3<=maxf-1)
            ypala1++;
        }
        system("clear");
    }while(1);

    return 0;
}


//        gotoxy(55,5);printf("%d , %d", x,y);                    // situacion de ||

