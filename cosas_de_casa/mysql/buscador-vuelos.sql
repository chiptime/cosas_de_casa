DROP DATABASE IF EXISTS buscador_vuelos;

CREATE DATABASE buscador_vuelos;

use buscador_vuelos
/*Se eligen IATA, nombre y ciudad para evitar confundir aeropuertos*/
CREATE TABLE AEROPUERTO(codIATA CHAR(3), nombre VARCHAR(30), ciudad VARCHAR(30), pais VARCHAR(30), PRIMARY KEY (codIATA,nombre,pais));

CREATE TABLE TERMINAL(numero CHAR(1), codIATA CHAR(3),PRIMARY KEY (numero), CONSTRAINT iata_FK FOREIGN KEY (codIATA) REFERENCES AEROPUERTO(codIATA) ON UPDATE CASCADE);

CREATE TABLE ASIENTO(
codasiento CHAR(4), 
tipoclase ENUM('Turista','TuristaSuperior','Business','Primera'), 
PRIMARY KEY (codasiento));

CREATE TABLE PASAJERO(DNI CHAR(9), nombre VARCHAR(30), apellido1 VARCHAR(30), apellido2 VARCHAR(30), PRIMARY KEY(DNI));
/*introducir metodo de pago*/
CREATE TABLE RESERVA(localizador INT AUTO_INCREMENT, DNI CHAR(9), precio DECIMAL (.3), PRIMARY KEY(localizador));

CREATE TABLE COMPANIA(codcompania INT auto_increment, nombre VARCHAR(30), logo VARCHAR(30), PRIMARY KEY(codcompania));
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
CONSTRAINT codcomp_FK FOREIGN KEY (codcompania) REFERENCES COMPANIA(codcompania) ON UPDATE CASCADE);

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
CONSTRAINT hora_salida_FK FOREIGN KEY (hora_salida) REFERENCES VUELO(hora) ON UPDATE CASCADE,

);




