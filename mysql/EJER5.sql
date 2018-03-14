DROP DATABASE IF EXISTS ejer5;

CREATE DATABASE ejer5;

use ejer5
/*Se eligen IATA, nombre y ciudad para evitar confundir aeropuertos*/
CREATE TABLE PERSONA(
ID INT AUTO_ICREMENT,
preciopujado DECIMAL(10,2),
ciudad VARCHAR(30),
PRIMARY KEY (ID));

CREATE TABLE ORDEN(
ID INT AUTO_INCREMENT,
numeroorden TINYINT UNSIGNED,
ID_Persona INT,
PRIMARY KEY (ID),
CONSTRAINT FK_persona FOREIGN KEY (ID_Persona) REFERENCES PERSONA(ID) ON UPDATE CASCADE
);

INSERT INTO PERSONA(nombre, apellido,fechadenacimiento,preciopujado,ciudad) VALUES ('fernando','delamata',1985-12-06,2350.5,'Madrid');
INSERT INTO ORDEN(numeroorden,ID_Persona) VALUES (1,3), (2,2), (3,1);


SELECT * FROM ORDEN;

SELECT ORDEN.numeroorden,
PERSONA.nombre,
PERSONA.apellido,
PERSONA.perciopujado
FROM ORDEN,PERSONA
WHERE ORDEN.ID_Persona=PERSONA.ID;



