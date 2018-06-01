#include <stdio.h>
int inicial = 0;
int inicial2 = 1;
int generado = 0;
// la funcion fibonacci funciona como un ciclo for
int fibonacci()
{

	inicial = inicial2;
	inicial2 = generado;
	generado = inicial + inicial2;
		
	return generado;
	
}

int main()
{
	int numero;
	printf("Ingresa un numero\n");
	scanf("%i",&numero);
	for (int i = 0; i < numero; i++)
	{
		printf("%d\n", fibonacci());
	}
	return 0;

}
