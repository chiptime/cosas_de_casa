AEROPUERTO(codIATA, nombre, ciudad, pais);

TERMINAL(numero CHAR(1), codIATA CHAR(3));

ASIENTO(codasiento INT auto_increment, tipoclase ENUM('turista','turista_superior','business','primera'));

PASAJERO(DNI CHAR(9), nombre VARCHAR(30), apellido1 VARCHAR(30), apellido2 VARCHAR(30));

RESERVA(localizador INT AUTO_INCREMENT, DNI CHAR(9), precio DECIMAL (.3));

COMPANIA(codcompania INT auto_increment, nombre VARCHAR(30), logo VARCHAR(30));
VUELO(codvuelo INT AUTO_INCREMENT, codcompania INT, aeropuertoorigen VARCHAR(30), aeropuertodestino VARCHAR(30), estado ENUM('lleno','incompleto'), escala ENUM('directo','1_escala','2_escala','3_escala','4_escala','5_escala'));

RESERVA_VUELO(localizador INT, codvuelo INT);
