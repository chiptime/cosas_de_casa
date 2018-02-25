#include <stdio.h>
#include <stdlib.h>

#define N 3
#define I 0
int main(){
	
	int a[N][N] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

/*	for (int desplaz=0;desplaz<N;desplaz++){
		for (int elem=0;elem<N;elem++)
			printf("%4i", a[elem%N][(elem+desplaz)%N]);

			printf("%4i", a[elem%N][(desplaz+elem)%N]);
				printf("\n");
	}
*/
/*		for (int desplaz=3;desplaz>0;desplaz--){*/
			for (int desplaz=3;desplaz>0;desplaz--){
		for (int elem=0;elem<N;elem++){
			
			if(elem=2 && desplaz=1){
				desplaz=0;
			printf("%4i", a[elem%N][(desplaz-elem)%N]);}
			else
			printf("%4i", a[elem%N][(desplaz-elem)%N]);
		}

/*			printf("%4i", a[elem%N][(desplaz+elem)%N]);*/
				printf("\n");
	}



return EXIT_SUCCESS;
}
