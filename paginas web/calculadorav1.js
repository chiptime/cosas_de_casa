
let resultado;
var dato1;
var dato2;
var dato = [];
/*
function ObtenerDatos (dato1,dato2) {

	var miParrafo;
	var miDato;

	miDato = document.getElementById('Dato1');
	miResultado = document.getElementById('Dato1');
	miResultado.innerHTML = 
		"El valor es " + miDato.value;


}
*/



function obtenerDatos() {

	this.dato1 = dato1;
	this.dato2 = dato2;


	dato1 = document.getElementById('Dato1');
	dato2 = document.getElementById('Dato2');
/*	miResultado = document.getElementById('Dato1');
	miResultado.innerHTML = 
		"El valor es " + miDato.value;*/

		return [parseInt(this.dato1.value), parseInt(this.dato2.value)];
}


/*function operar() {
	let resultado;
	ObtenerDatos(casilla1,casilla2);
	casilla1 += casilla2;
	return resultado;
}*/

function operar(){//operador) {
	var operador = '+';
	let resultado;
	
	dato.push( obtenerDatos() );
	if(operador == '+'){
		//resultado = dato[0].value + dato[1].value;
		resultado = dato[0] + dato[1];
	
	return resultado
	}

	if(operador == '-'){
		resultado = dato[0] - dato[1];
	
	return resultado
	}

	if(operador == '*'){
		resultado = dato[0] * dato[1];
	
	return resultado
	}

	if(operador == '/'){
		resultado = dato[0] / dato[1];
		return resultado

	}

}



function DarResultado () {


let miResultado = operar(); 

let Res = document.getElementById('resultado');
miResultado.innerHTML = 
	"El valor es " + miResultado.value;
}

/*function DarResultado () {
let miResultado; 
miResultado = document.getElementById('resultado');
miResultado.innerHTML = 
	"El valor es " + miResultado.value;
}*/
