DROP DATABASE IF EXISTS buscador_vuelos;

CREATE DATABASE buscador_vuelos;

use buscador_vuelos
/*Se eligen IATA, nombre y ciudad para evitar confundir aeropuertos*/
CREATE TABLE AEROPUERTO(codIATA CHAR(3), nombre VARCHAR(30), ciudad VARCHAR(30), pais VARCHAR(30), PRIMARY KEY (codIATA,nombre,pais));

CREATE TABLE TERMINAL(numero CHAR(1), codIATA CHAR(3),PRIMARY KEY (numero), CONSTRAINT iata_FK FOREIGN KEY (codIATA) REFERENCES AEROPUERTO(codIATA));

CREATE TABLE ASIENTO(codasiento CHAR(4), tipoclase ENUM('turista','turista_superior','business','primera'), PRIMARY KEY (codasiento));

CREATE TABLE PASAJERO(DNI CHAR(9), nombre VARCHAR(30), apellido1 VARCHAR(30), apellido2 VARCHAR(30), PRIMARY KEY(DNI));
/*introducir metodo de pago*/
CREATE TABLE RESERVA(localizador INT AUTO_INCREMENT, DNI CHAR(9), precio DECIMAL (.3), PRIMARY KEY(localizador));

CREATE TABLE COMPANIA(codcompania INT auto_increment, nombre VARCHAR(30), logo VARCHAR(30), PRIMARY KEY(codcompania));
/*ESTADO: RESERVA, RETRASO Y CANCELADO*/
CREATE TABLE VUELO(codvuelo INT AUTO_INCREMENT, codcompania INT, aeropuertoorigen VARCHAR(30), aeropuertodestino VARCHAR(30), estado ENUM('lleno','incompleto'), escala ENUM('directo','1_escala','2_escala','3_escala','4_escala','5_escala'), PRIMARY KEY (codvuelo), CONSTRAINT codcomp_FK FOREIGN KEY (codcompania) REFERENCES COMPANIA(codcompania));

CREATE TABLE /*BILLETE-> agregar otras columnas como  etc*/RESERVA_VUELO(localizador INT, codvuelo INT, DNI CHAR(3), nombre VARCHAR(30), maleta_mano ENUM('si','no'), maleta_bodega ENUM('0','1','2','3'), aeropuertoorigen VARCHAR(30), aeropuertodestino VARCHAR(30), CONSTRAINT local_FK FOREIGN KEY (localizador) REFERENCES RESERVA(localizador), CONSTRAINT cod_vuelo_FK FOREIGN KEY (codvuelo) REFERENCES VUELO(codvuelo));
/*localizador INT, codvuelo INT, DNI, nombre, maleta_mano, maleta_bodega, aeropuertoorigen, aeropuertodestino*/





