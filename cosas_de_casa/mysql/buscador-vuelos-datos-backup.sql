DROP DATABASE IF EXISTS buscador_vuelos_datos;

CREATE DATABASE buscador_vuelos_datos;

use buscador_vuelos_datos

CREATE TABLE AEROPUERTO(codIATA CHAR(3), nombre VARCHAR(30), ciudad VARCHAR(30), pais VARCHAR(30), PRIMARY KEY (codIATA));

CREATE TABLE TERMINAL(numero CHAR(1), codIATA CHAR(3),PRIMARY KEY (numero), CONSTRAINT iata_FK FOREIGN KEY (codIATA) REFERENCES AEROPUERTO(codIATA) ON UPDATE CASCADE);

CREATE TABLE ASIENTO(codasiento INT auto_increment, tipoclase ENUM('turista','turista_superior','business','primera'), PRIMARY KEY (codasiento));

CREATE TABLE PASAJERO(DNI CHAR(9), nombre VARCHAR(30), apellido1 VARCHAR(30), apellido2 VARCHAR(30), PRIMARY KEY(DNI));

CREATE TABLE RESERVA(localizador INT AUTO_INCREMENT, DNI CHAR(9), precio DECIMAL (.3), PRIMARY KEY(localizador));

CREATE TABLE COMPANIA(codcompania INT auto_increment, nombre VARCHAR(30), logo VARCHAR(30), PRIMARY KEY(codcompania));

CREATE TABLE VUELO(codvuelo INT AUTO_INCREMENT, codcompania INT, aeropuertoorigen VARCHAR(30), aeropuertodestino VARCHAR(30), estado ENUM('lleno','incompleto'), escala ENUM('directo','1_escala','2_escala','3_escala','4_escala','5_escala'), PRIMARY KEY (codvuelo), CONSTRAINT codcomp_FK FOREIGN KEY (codcompania) REFERENCES COMPANIA(codcompania) ON UPDATE CASCADE);

CREATE TABLE RESERVA_VUELO(localizador INT, codvuelo INT, CONSTRAINT local_FK FOREIGN KEY (localizador) REFERENCES RESERVA(localizador), CONSTRAINT cod_vuelo_FK FOREIGN KEY (codvuelo) REFERENCES VUELO(codvuelo) ON UPDATE CASCADE);

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
/*Datos TERMINAL(numero CHAR(1), codIATA CHAR(3)*/
/*INSERT INTO TERMINAL(numero, codIATA)
VALUES ('Los Angeles', 900, '10-Jan-1999');*/
/*Datos ASIENTO(codasiento INT auto_increment, tipoclase ENUM('turista','turista_superior','business','primera')*/

/*Datos PASAJERO(DNI CHAR(9), nombre VARCHAR(30), apellido1 VARCHAR(30), apellido2 VARCHAR(30)*/


/*Datos RESERVA(localizador INT AUTO_INCREMENT, DNI CHAR(9), precio DECIMAL (.3)*/

/*Datos COMPANIA(codcompania INT auto_increment, nombre VARCHAR(30), logo VARCHAR(30));
VUELO(codvuelo INT AUTO_INCREMENT, codcompania INT, aeropuertoorigen VARCHAR(30), aeropuertodestino VARCHAR(30), estado ENUM('lleno','incompleto'), escala ENUM('directo','1_escala','2_escala','3_escala','4_escala','5_escala')*/

/*Datos RESERVA_VUELO(localizador INT, codvuelo INT)*/
