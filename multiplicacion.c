#include <stdio.h>
int main()
{
	int num1, num2, resultado;
	int a=12;
	int b=3;
	printf("Ingresa el primer numero \n");
	scanf("%d", &num1);
	printf("Ingresa el segundo numero \n");
	scanf("%d", &num2);
	resultado = a*(num1 * num2) +b*(b + num2);
	printf("El resultado es: %d\n", resultado);
	return 0;
	
}
