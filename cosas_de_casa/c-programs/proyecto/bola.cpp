#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
//for mygetch
#include <termios.h>
#include <unistd.h>

#include <time.h>


#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)

//#define xbola 50
//#define ybola 15

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


    char matriz[fila][columna];

    for(int i=0;i<fila;i++) {
        for(int j=0;j<columna;j++) {
            matriz[i][j] = 'x';
        }
    }





    do{
        __fpurge(stdin);
     gotoxy(55,5);printf("%d , %d", x,y);

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





        //void movimiento_bola();
        /*
           gotoxy(xbola,ybola); printf("(_)");

           if(xbola>=minc+4 && xbola<=maxc-1)
           xbola--;
           if(xbola<=maxc-1)
           xbola++;

        //arriba abajo
        if(ybola>=minf+3 && ybola<=maxf-1)
        ybola--;
        if(ybola<=maxf-1)
        ybola++;*/
sleep(1);
/*        gotoxy(xbola,ybola); printf("(_)");

        xbola=xbola+1;
        ybola=ybola+1;
        if(xbola=minc+4)
            xbola = -xbola;
        if(xbola=maxc-1)
            xbola = -xbola;
        //teclas arriba abajo
        if(ybola=minf+3)
            ybola = -ybola;
        if(ybola=maxf-1)
            ybola = -ybola;*/

x++;

   
        system("clear");
    }while(1);

    return 0;
}



