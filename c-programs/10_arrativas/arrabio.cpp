#include <stdio.h>
#include <stdlib.h>

#define N 3
int main(){
	
	int a[N][N] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	for (int desplaz=0;desplaz<N;desplaz++){
		for (int elem=0;elem<N;elem++)
			printf("%4i", a[elem%N][(desplaz+elem)%N]);
		printf("\n");
	}
return EXIT_SUCCESS;
}
