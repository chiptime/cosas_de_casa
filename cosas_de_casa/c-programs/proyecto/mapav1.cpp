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

int main() {
    /*TODO pasar todo a double y comprobar que funcione bien*/
    int fila = 15;
    int columna= 15;
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
        gotoxy(55,5);printf("%d , %d", x,y);
        gotoxy(x,y);
        printf("||");

        tecla=mygetch();

        //tecla isquierda derecha minc=0 maxc=columna-1
         if((x>=(minc+3)) && (x<=maxc-1)){ //minc = 0
            if(tecla=='a')
                x--;
           if(tecla=='d')
                x++;
         }else{
             if(x<=minc+3)
                 x++;
             if(x>=maxc-1)
                 x--;
         }
        //teclas arriba abajo
        if((y>=(minf+2)) && (y<=maxf-1)){ //minf = 0
            if(tecla=='w')
                y--;
            if(tecla=='s')
                y++;
        }
        else{
             if(y<=minf+2)
                 y++;
             if(y>maxf-1)
                 y--;
        }

        system("clear");
    }while(1);

    return 0;
}



