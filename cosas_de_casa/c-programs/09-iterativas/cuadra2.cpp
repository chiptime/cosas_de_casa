#include <stdio.h>
#include <stdlib.h>

#define A 3
#define B 7
#define C 11
int main(){
    for (int f=0; f<A; f++){
        for (int c=0; c<A; c++){
            printf ("*");
        }
        for (int c1=4; c1<B; c1++){
            printf (" ");
        }
        for (int c2=8; c2<C; c2++){
            printf ("*");
        }
        printf ("\n");
    }
    for (int f1=0; f1<A; f1++){
        for (int c=0; c<A; c++){
            printf (" ");
        }
        for (int c1=4; c1<B; c1++){
            printf ("*");
        }
        for (int c2=8; c2<C; c2++){
            printf (" ");
        }
        printf ("\n");
    }
    for (int f=0; f<A; f++){
        for (int c=0; c<A; c++){
            printf ("*");
         }
         for (int c1=4; c1<B; c1++){
             printf (" ");
        }
         for (int c2=8; c2<C; c2++){
            printf ("*");
         }
         printf ("\n");
    }




    return EXIT_SUCCESS;
}
