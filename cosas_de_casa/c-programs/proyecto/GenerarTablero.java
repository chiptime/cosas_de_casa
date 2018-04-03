package monopolio;

/*
 * Algoritmo para generar el tablero de Monopoly.
 * El tablero consta de:
 * 						1 casilla grande por esquina, a la que llamaremos "y"
 * 						9 casillas normales entre las "y", las llamaremos "x"
 * Por lo que:
 * 			El alto sera igual a: 9x + 2y
 * 			El ancho sera igual a: 9x + 2y
 *
 * Asi que usaremos de base una matriz de 11x11, para simular la estructura del tablero
 *
 * */
public class GenerarTablero {

	public static void main(String[] args) {

		int fila = 11;
		int columna= 11;

		String[][] matriz = new String[fila][columna];

		for(int i=0;i<fila;i++) {
			for(int j=0;j<columna;j++) {
				matriz[i][j] = "x";
			}
		}

		for(int f = 0; f<fila;f++) {

			for(int c=0;c<columna;c++) {

				if(((f) == 0) || ((f) == 10)){
					if( ((f==0)&&(c==0)) || ((f==0)&&(c==10)) || ((f==10)&&(c==0)) || ((f==10)&&(c==10)) ) { 																																			System.out.print( matriz[f][c] + "x" );

					}
					else System.out.print("i");																	Change for normal box
				}

				else
				if(((f) >= 2) || ((f) <= 8)) {
					if( (c<1) ||(c>9) ) {

						System.out.print(matriz[f][c] + "0");
					}
					else {
						System.out.print("/");
					}
				}


			}
			System.out.println();
		}
	}

}
