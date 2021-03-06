DROP DATABASE IF EXISTS buscador_vuelos_mod;

CREATE DATABASE buscador_vuelos_mod;

use buscador_vuelos_mod

CREATE TABLE AEROPUERTO(codIATA CHAR(3), nombre VARCHAR(30), ciudad VARCHAR(30), pais VARCHAR(30), PRIMARY KEY (codIATA));

CREATE TABLE TERMINAL(numero CHAR(1), codIATA CHAR(3),PRIMARY KEY (numero), CONSTRAINT iata_FK FOREIGN KEY (codIATA) REFERENCES AEROPUERTO(codIATA) ON UPDATE CASCADE);

CREATE TABLE ASIENTO(codasiento INT auto_increment, tipoclase ENUM('turista','turista_superior','business','primera'), PRIMARY KEY (codasiento));

CREATE TABLE PASAJERO(DNI CHAR(9), nombre VARCHAR(30), apellido1 VARCHAR(30), apellido2 VARCHAR(30), PRIMARY KEY(DNI));

CREATE TABLE RESERVA(localizador INT AUTO_INCREMENT, DNI CHAR(9), precio DECIMAL (.3), PRIMARY KEY(localizador));

CREATE TABLE COMPANIA(codcompania INT auto_increment, nombre VARCHAR(30), logo VARCHAR(30), PRIMARY KEY(codcompania));

CREATE TABLE VUELO(codvuelo INT AUTO_INCREMENT, codcompania INT, aeropuertoorigen VARCHAR(30), aeropuertodestino VARCHAR(30), estado ENUM('lleno','incompleto'), escala ENUM('directo','1_escala','2_escala','3_escala','4_escala','5_escala'), PRIMARY KEY (codvuelo), CONSTRAINT codcomp_FK FOREIGN KEY (codcompania) REFERENCES COMPANIA(codcompania) ON UPDATE CASCADE);

CREATE TABLE RESERVA_VUELO(localizador INT, codvuelo INT, CONSTRAINT local_FK FOREIGN KEY (localizador) REFERENCES RESERVA(localizador), CONSTRAINT cod_vuelo_FK FOREIGN KEY (codvuelo) REFERENCES VUELO(codvuelo) ON UPDATE CASCADE);

/*Creación de usuarios posibles (anónimo que consulta, admin o por ejemplo un usuario que realiza una reserva) junto con sus permisos.*/
CREATE USER 'anonimo';
GRANT USAGE ON *.* TO anonimo;
flush privileges;

CREATE USER 'bruno'@'localhost' IDENTIFIED BY 'contrasena';
GRANT ALL PRIVILEGES ON * . * TO 'bruno'@'localhost';
flush privileges;

CREATE USER 'reserva';
GRANT INSERT ON * . * TO 'reserva';
flush privileges;


