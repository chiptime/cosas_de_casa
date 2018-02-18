DROP DATABASE IF EXISTS zoo

CREATE DATABASE zoo;

use zoo

CREATE TABLE ZOO (nombre VARCHAR(30), ciudad VARCHAR(30), pais VARCHAR(30), tamaño ENUM('Categoria A','Categoria B'), presupuesto DECIMAL UNSIGNED, PRIMARY KEY (nombre));

CREATE TABLE ESPECIE (nomcientifico VARCHAR(30), nomvulgar VARCHAR(30) NOT NULL, familia VARCHAR(30), peligro VARCHAR(30), PRIMARY KEY (nomcientifico));

CREATE TABLE ANIMAL (ID INT, nomzoo VARCHAR(30), nomespecie VARCHAR(30), sexo ENUM('Masculino','Femenino'), añonacim YEAR, pais VARCHAR(30), continente VARCHAR(30), PRIMARY KEY(ID), FOREIGN KEY (nomzoo) REFERENCES ZOO(nombre), FOREIGN KEY (nomespecie) REFERENCES ESPECIE(nomcientifico));

ALTER TABLE ANIMAL MODIFY ID INT AUTO_INCREMENT FIRST;

UPDATE ANIMAL INNER JOIN ZOO
ON ANIMAL.nomzoo = ZOO.nombre
SET ANIMAL.nomzoo = ZOO.nombre

ALTER TABLE ANIMAL DROP FOREIGN KEY ANIMAL_ibfk_1;

ALTER TABLE ANIMAL ADD CONSTRAINT ANIMAL_ibfk_1 FOREIGN KEY (nomzoo) REFERENCES ZOO(nombre) ON DELETE SET NULL;

INSERT INTO ZOO VALUES('Zoo Madrid','Madrid','España','Categoria A','608.42');

INSERT INTO ESPECIE VALUES('Panthera tigris','Tigre','Felinos','Altos');

INSERT INTO ANIMAL(nomzoo,nomespecie,sexo,añonacim,pais,continente) VALUES('Zoo Madrid','Panthera tigris','Masculino','2013','India','Asia');

UPDATE ZOO SET nombre = 'Zoo Madrid - Vodafone';
