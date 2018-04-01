#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)



static void init_ball();
void marco();

int main() {
    /*TODO pasar todo a double y comprobar que funcione bien*/
    int fila = 30;
    int columna= 100;

    bool finPrograma = false;
int x 5
int y 5
    /*
    typedef struct ball_s {

        int x, y; position on the screen 

        int dx, dy;  movement vector
    } ball_t;

    typedef struct paddle {

        int x,y;
        int w,h;
    } paddle_t;

    static ball_t ball;
    static paddle_t paddle[2];
*/


    /* Movimiento de la pelota*/
    double xpos, ypos;

    double xspeed = 2.8;
    double yspeed = 2.2;

    int xdirection = 1;
    int ydirection = 1;

    /* Punto de inicio de la pelota*/
    double width;
    double height;
  /*  width = maxc;
    height = maxf;
    xpos = width/2;
    ypos = height/2;*/

 void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
 }

        char matriz[fila][columna];

        for(int i=0;i<fila;i++) {
            for(int j=0;j<columna;j++) {
                matriz[i][j] = 'x';
            }
        }
        /*Dibujar marco*/
        for(int f=0; f<fila;f++) {
            for(int c=0;c<columna;c++) {
                if(((f) == minf) || ((f) == maxf)){
                    if( ((f==minf)&&(c==minc)) || ((f==minf)&&(c==maxc)) || ((f==maxf)&&(c==minc)) || ((f==maxf)&&(c==maxc)) )
                        printf("%cx", matriz[f][c] );
                    else printf("i");
                }
                else
                    if(((f) >= (minf)/*2*/) || ((f) <= (maxf)/*8*/)) {
                        if( (c<(minc+1)) ||(c>(maxc-1)) )
                            printf("%c0",matriz[f][c]);
                        else
                            printf(" ");
                    }


            }
            printf("\n");
        }
/*
static void init_ball() {

    ball.x = screen->w / 2;
    ball.y = screen->h / 2;
    ball.w = 10;
    ball.h = 10;
    ball.dy = 1;
    ball.dx = 1;

    paddle[0].x = 20;
    paddle[0].y = screen->h / 2 - 50 ;
    paddle[0].w = 10;
    paddle[0].h = 50;

    paddle[1].x = screen->w - 20 - 10;
    paddle[1].y = screen->h / 2 - 50;
    paddle[1].w = 10;
    paddle[1].h = 50;
}*/

       do{
           gotoxy(x,y);printf("||");

           tecla=getch();
           if(tecla=='a') x--;
           if(tecla=='d') x++;

           if(tecla=='w') y--;
           if(tecla=='s') y++;
           /*
         Update the position of the shape
         xpos = xpos + ( xspeed * xdirection );
         ypos = ypos + ( yspeed * ydirection );
*/
    /* Test to see if the shape exceeds the boundaries of the screen
     *  If it does, reverse its direction by multiplying by -1*/
  /*          if (xpos > width-rad || xpos < rad) {
              xdirection *= -1;
              }
              if (ypos > height-rad || ypos < rad) {
              ydirection *= -1;
              }*/
system("CLS");
              }while(1);


    return 0;
}



