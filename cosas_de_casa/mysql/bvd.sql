DROP DATABASE IF EXISTS buscador_vuelos;

CREATE DATABASE buscador_vuelos;

use buscador_vuelos
/*Se eligen IATA, nombre y ciudad para evitar confundir aeropuertos*/
CREATE TABLE AEROPUERTO(
codIATA CHAR(3),
nombre VARCHAR(30),
ciudad VARCHAR(30),
pais VARCHAR(30),
PRIMARY KEY (codIATA,nombre,pais)
);

CREATE TABLE TERMINAL(
numero CHAR(1),
codIATA CHAR(3),
PRIMARY KEY (numero),
CONSTRAINT iata_FK FOREIGN KEY (codIATA) REFERENCES AEROPUERTO(codIATA) ON UPDATE CASCADE
);

CREATE TABLE ASIENTO(
    codasiento CHAR(4), 
    tipoclase ENUM('Turista','TuristaSuperior','Business','Primera'), 
    PRIMARY KEY (codasiento)
);

CREATE TABLE PASAJERO(
DNI CHAR(9),
nombre VARCHAR(30),
apellido1 VARCHAR(30),
apellido2 VARCHAR(30),
PRIMARY KEY(DNI)
);
/*introducir metodo de pago*/
CREATE TABLE RESERVA(
localizador INT AUTO_INCREMENT,
DNI CHAR(9),
precio DECIMAL (.3),
PRIMARY KEY(localizador),
CONSTRAINT DNI_FK FOREIGN KEY (DNI) REFERENCES PASAJERO(DNI) ON UPDATE CASCADE
);

CREATE TABLE COMPANIA(
codcompania INT auto_increment,
nombre VARCHAR(30),
logo VARCHAR(30),
PRIMARY KEY(codcompania)
);
/*ESTADO: RESERVA, RETRASO Y CANCELADO*/
CREATE TABLE VUELO(
    codvuelo INT AUTO_INCREMENT, 
    codcompania INT, 
    aeropuertoorigen VARCHAR(30), 
    aeropuertodestino VARCHAR(30), 
    estado ENUM('lleno','incompleto'), 
    escala ENUM('directo','1_escala','2_escala','3_escala','4_escala','5_escala'), 
    hora TIME,
    PRIMARY KEY (codvuelo), 
    CONSTRAINT codcomp_FK FOREIGN KEY (codcompania) REFERENCES COMPANIA(codcompania) ON UPDATE CASCADE
);

CREATE TABLE BILLETE(
    localizador INT, 
    codvuelo INT, 
    DNI CHAR(3), 
    nombre VARCHAR(30), 
    maleta_mano ENUM('si','no'), 
    maleta_bodega ENUM('0','1','2','3'), 
    codcompania INT, 
    de VARCHAR(30), 
    a VARCHAR(30), 
    hora_llegada TIME,
    hora_salida TIME,


    CONSTRAINT local_FK FOREIGN KEY (localizador) REFERENCES RESERVA(localizador) ON UPDATE CASCADE, 
    CONSTRAINT cod_vuelo_FK FOREIGN KEY (codvuelo) REFERENCES VUELO(codvuelo) ON UPDATE CASCADE, 
    CONSTRAINT codcomp_FK FOREIGN KEY (codcompania) REFERENCES COMPANIA(codcompania) ON UPDATE CASCADE,
    CONSTRAINT de_ciudad_FK FOREIGN KEY (de) REFERENCES AEROPUERTO(ciudad) ON UPDATE CASCADE,
    CONSTRAINT a_ciudad_FK FOREIGN KEY (a) REFERENCES AEROPUERTO(ciudad) ON UPDATE CASCADE,
    CONSTRAINT hora_llegada_FK FOREIGN KEY (hora_llegada) REFERENCES VUELO(hora) ON UPDATE CASCADE,
    CONSTRAINT hora_salida_FK FOREIGN KEY (hora_salida) REFERENCES VUELO(hora) ON UPDATE CASCADE

);


/*Inserción de datos al menos 5 filas por cada tabla. Se requiere actualizar y borrar al menos 3 datos.*/

/*Datos AEREOPUERTO(codIATA CHAR(3), nombre VARCHAR(30), ciudad VARCHAR(30), pais VARCHAR(30)*/
INSERT INTO AEROPUERTO (codIATA, nombre, ciudad, pais)
VALUES ('MAD', 'Madrid-Barajas', 'Madrid', 'España');
INSERT INTO AEROPUERTO (codIATA, nombre, ciudad, pais)
VALUES ('BCN', 'Barcelona-El Prat', 'Barcelona', 'España');
INSERT INTO AEROPUERTO (codIATA, nombre, ciudad, pais)
VALUES ('VLC', 'Valencia', 'Valencia', 'España');
INSERT INTO AEROPUERTO (codIATA, nombre, ciudad, pais)
VALUES ('LAX', 'Los Angeles-International', 'Los Angeles', 'USA');
INSERT INTO AEROPUERTO (codIATA, nombre, ciudad, pais)
VALUES ('LIM', 'Jorge Chavez', 'Lima', 'Peru');

UPDATE AEROPUERTO SET nombre = 'Madrid' WHERE nombre='Madrid-Barajas';
UPDATE AEROPUERTO SET nombre = 'Lima' WHERE nombre='Jorge Chavez';
UPDATE AEROPUERTO SET nombre = 'LA' WHERE nombre='Los Angeles-Internacional';

DELETE FROM AEROPUERTO WHERE nombre = 'LA';
DELETE FROM AEROPUERTO WHERE nombre = 'Barcelona-El Prat';
DELETE FROM AEROPUERTO WHERE nombre = 'Madrid';
/*Datos TERMINAL(
numero CHAR(1),
codIATA CHAR(3),
PRIMARY KEY (numero),
CONSTRAINT iata_FK FOREIGN KEY (codIATA) REFERENCES AEROPUERTO(codIATA) ON UPDATE CASCADE*/
INSERT INTO TERMINAL (numero,codIATA) 
VALUES (1,'MAD');
INSERT INTO TERMINAL (numero,codIATA)
VALUES (2,'BCN');
INSERT INTO TERMINAL (numero,codIATA)
VALUES (3,'VLC');
INSERT INTO TERMINAL (numero,codIATA)
VALUES (4,'LAX');
INSERT INTO TERMINAL (numero,codIATA)
VALUES (5,'LIM');

UPDATE TERMINAL SET numero = 3 WHERE numero = 1;
UPDATE TERMINAL SET numero = 1 WHERE numero = 2;
UPDATE TERMINAL SET numero = 4 WHERE numero = 5;

DELETE FROM TERMINAL WHERE codIATA = 'MAD';
DELETE FROM TERMINAL WHERE codIATA = 'BCN';
DELETE FROM TERMINAL WHERE codIATA = 'VLC';

/*Datos ASIENTO(codasiento INT auto_increment, tipoclase ENUM('turista','turista_superior','business','primera')*/
INSERT INTO ASIENTO (tipoclase)
VALUES ('Business');
INSERT INTO ASIENTO (tipoclase)
VALUES ('Primera');
INSERT INTO ASIENTO (tipoclase)
VALUES ('Turista');
INSERT INTO ASIENTO (tipoclase)
VALUES ('Turista');
INSERT INTO ASIENTO (tipoclase)
VALUES ('TuristaSuperior');

UPDATE ASIENTO SET tipoclase = 'Business' WHERE tipoclase = 'Primera';
UPDATE ASIENTO SET tipoclase = 'Turista' WHERE tipoclase = 'TuristaSuperior';
UPDATE ASIENTO SET tipoclase = 'Primera' WHERE tipoclase = 'Turista';

DELETE FROM ASIENTO WHERE tipoclase = 'Primera';
DELETE FROM ASIENTO WHERE tipoclase = 'Business';
DELETE FROM ASIENTO WHERE tipoclase = 'Turista';
/*Datos PASAJERO(DNI CHAR(9), nombre VARCHAR(30), apellido1 VARCHAR(30), apellido2 VARCHAR(30)*/
INSERT INTO PASAJERO (DNI,nombre,apellido1,apellido2)
VALUES ('02765391D', 'bruno', 'silva', 'narro');
INSERT INTO PASAJERO (DNI,nombre,apellido1,apellido2)
VALUES ('02765392D','ana','narro','carrasco');
INSERT INTO PASAJERO (DNI,nombre,apellido1,apellido2)
VALUES ('02765393D','sebastian','silva','narro');
INSERT INTO PASAJERO (DNI,nombre,apellido1,apellido2)
VALUES ('02765394D','william','silva','pescoran');
INSERT INTO PASAJERO (DNI,nombre,apellido1,apellido2)
VALUES ('02765395D','sandra','silva','silva');

UPDATE PASAJERO SET DNI = '02765390P' WHERE DNI = '02765392D';
UPDATE PASAJERO SET nombre = 'leon' WHERE nombre = 'sebastian';
UPDATE PASAJERO SET apellido2 = '' WHERE apellido2 = 'silva';

DELETE FROM PASAJERO WHERE DNI = '02765395D';
DELETE FROM PASAJERO WHERE nombre = 'william';
DELETE FROM PASAJERO WHERE nombre = 'bruno';

/*Datos RESERVA(localizador INT AUTO_INCREMENT, DNI CHAR(9), precio DECIMAL (.3), CONSTRAINT DNI_FK FOREIGN KEY (DNI) REFERENCES PASAJERO(DNI) ON UPDATE CASCADE*/
INSERT INTO RESERVA (DNI,precio)
VALUES ((SELECT DNI FROM PASAJERO WHERE DNI = '02765391D' ),'20');
INSERT INTO RESERVA (DNI,precio)
VALUES ((SELECT DNI FROM PASAJERO WHERE DNI = '02765392D'), '30');
INSERT INTO RESERVA (DNI,precio)
VALUES ((SELECT DNI FROM PASAJERO WHERE DNI = '02765393D'), '40');
INSERT INTO RESERVA (DNI,precio)
VALUES ((SELECT DNI FROM PASAJERO WHERE DNI = '02765394D'), '50');
INSERT INTO RESERVA (DNI,precio)
VALUES ((SELECT DNI FROM PASAJERO WHERE DNI = '02765395D'), '60');

UPDATE RESERVA SET precio = '60' WHERE DNI = '02765391D';
UPDATE RESERVA SET precio = '80' WHERE DNI = '02765392D';
UPDATE RESERVA SET precio = '100' WHERE DNI = '02765393D';

DELETE FROM RESERVA WHERE precio = '100';
DELETE FROM RESERVA WHERE precio = '50';
DELETE FROM RESERVA WHERE DNI = '02765391D';
/*Datos COMPANIA(codcompania INT auto_increment, nombre VARCHAR(30), logo VARCHAR(30));*/
INSERT INTO COMPANIA (nombre, logo)
VALUES ('bruno','ruta1');
INSERT INTO COMPANIA (nombre,logo)
VALUES ('sebastian','ruta2');
INSERT INTO COMPANIA (nombre,logo)
VALUES ('ana','ruta3');
INSERT INTO COMPANIA (nombre,logo)
VALUES ('william','ruta4');
INSERT INTO COMPANIA (nombre,logo)
VALUES ('sandra','ruta5');

UPDATE COMPANIA SET logo = './logo' WHERE = 'ruta1';
UPDATE COMPANIA SET logo = './logo2' WHERE = 'ruta2';
UPDATE COMPANIA SET logo = './logo3' WHERE = 'ruta3';

DELETE FROM COMPANIA WHERE logo = 'ruta4';
DELETE FROM COMPANIA WHERE logo = 'ruta5';
DELETE FROM COMPANIA WHERE logo = 'ruta6';
/*VUELO(codvuelo INT AUTO_INCREMENT, codcompania INT, aeropuertoorigen VARCHAR(30), aeropuertodestino VARCHAR(30), estado ENUM('lleno','incompleto'), escala 'directo','1_escala'*/
INSERT INTO VUELO (aeropuertoorigen, aeropuertodestino,estado,escala)
VALUES ('Madrid','Barcelona','Espera','directo');
INSERT INTO VUELO (aeropuertoorigen, aeropuertodestino,estado,escala)
VALUES ('Madrid','Lima','Espera','directo');
INSERT INTO VUELO (aeropuertoorigen, aeropuertodestino,estado,escala)
VALUES ('Madrid','Valencia','Espera','directo');
INSERT INTO VUELO (aeropuertoorigen, aeropuertodestino,estado,escala)
VALUES ('Madrid','Los Angeles','Espera','2_escala');
INSERT INTO VUELO (aeropuertoorigen, aeropuertodestino,estado,escala)
VALUES ('Madrid','Barcelona','Espera','1_escala');

UPDATE VUELO SET aeropuertoorigen = 'Lima' WHERE aeropuertoorigen = 'Madrid';
UPDATE VUELO SET aeropuertoorigen = 'Lima' WHERE aeropuertoorigen = 'Madrid' WHERE escala = '2_escala';
UPDATE VUELO SET aeropuertoorigen = 'Lima' WHERE aeropuertoorigen = 'Madrid' WHERE escala = 'directo';

DELETE FROM VUELO WHERE aeropuertodestino = 'Lima';
DELETE FROM VUELO WHERE aeropuertodestino = 'Barcelona';
DELETE FROM VUELO WHERE aeropuertodestino = 'Los Angeles';
/*Datos RESERVA_VUELO(localizador INT, codvuelo INT)*/
INSERT INTO BILLETE
