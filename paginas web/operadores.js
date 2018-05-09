function CalcularOperadores () {

	var miParrafo;
	var valor = 22.65;

	miParrafo = document.getElementById('Resultado');
	valor = 12 + 20;
	miParrafo.innerHTML += "Sumando los numeros 12 y 20 = " + valor + "<br>";
	
	valor = 12 - 20;
	miParrafo.innerHTML += "Sumando los numeros 12 y 20 = " + valor + "<br>";
	
	valor = 3 * 20;
	miParrafo.innerHTML += "Sumando los numeros 3 y 20 = " + valor + "<br>";
	
	valor = 36 / 6;
	miParrafo.innerHTML += "Sumando los numeros 36 y 6 = " + valor + "<br>";
	
	valor = 3 * 20;
	miParrafo.innerHTML += "Sumando los numeros 3 y 20 = " + valor + "<br>";
	
	valor = 8;
	miParrafo.innerHTML += "Sumando los numeros 3 y 20 = " + (valor++) + "<br>";
	valor = 8;
	miParrafo.innerHTML += "Sumando los numeros 3 y 20 = " + (++valor) + "<br>";
}