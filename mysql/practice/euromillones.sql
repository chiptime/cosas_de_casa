DROP DATABASE IF EXISTS euroMillones;
CREATE DATABASE euroMillones;

USE euroMillones;

CREATE TABLE Bote(
		  ID int auto_increment,
		  Cantidad int,
		  PRIMARY KEY (ID)
		 );

CREATE TABLE Meses(mes VARCHAR(20), num INT AUTO_INCREMENT PRIMARY KEY);
INSERT INTO Meses VALUES('Enero', 1);
INSERT INTO Meses(Mes) VALUES('Febrero'),('Marzo'),('Abril'),('Mayo'),('Junio'),('Julio'),('Agosto'),('Septiembre'),('Octubre'),('Noviembre'),('Diciembre');
/*DROP PROCEDURE meses;*/
DROP PROCEDURE dimeMES;//
DROP PROCEDURE imprimirMeses;//

delimiter //
CREATE PROCEDURE dimeMES (IN _numero INT)

BEGIN
/*DECLARE _numero INT DEFAULT 1;*/
/*SET _numero = 1;*/
       SELECT mes FROM Meses WHERE num = _numero;
END//
delimiter;
//

CALL dimeMES(2);//

DROP FUNCTION IF EXISTS dameMES //

CREATE FUNCTION dameMES (n INT)
RETURNS VARCHAR(20) DETERMINISTIC
BEGIN
DECLARE el_mes VARCHAR(20) DEFAULT "";
SELECT mes INTO el_mes FROM Meses WHERE num = n;
RETURN el_mes;
END;//

SELECT dameMES(6);//

delimiter //
CREATE PROCEDURE imprimirMeses(/*OUT mes VARCHAR(30)*/)
BEGIN
	SELECT * FROM Meses;
END//
delimiter;
//

DROP PROCEDURE IF EXISTS todosLosMeses //
CREATE PROCEDURE todosLosMeses()
BEGIN
  DECLARE i INT DEFAULT 0;
  WHILE i < 3 DO
   SET i = i + 1;
	SELECT mes FROM Meses WHERE num = i;
  END WHILE;
END//



DROP FUNCTION IF EXISTS funMeses //
CREATE FUNCTION funMeses()
RETURNS VARCHAR(20) DETERMINISTIC
BEGIN
DECLARE el_mes VARCHAR(20) DEFAULT "";
DECLARE 
SELECT mes, num FROM Meses WHERE num
RETURN ;
END//

CALL funMeses;//



DROP PROCEDURE IF EXISTS tomaMeses //
CREATE PROCEDURE tomaMeses()
BEGIN
SELECT mes, num FROM Meses;
END//

CALL tomaMeses;//

CALL imprimirMeses;
/*SET @bote = 0;*/
/*
delimiter $$/*//*/
CREATE PROCEDURE doreapeat(p1 INT)
BEGIN
SET @x = 0;
REPEAT SET @x = @x + 1;
UNTIL @x > p1 END REPEAT;
END
/*//*/
$$
delimiter;

CALL dorepeat(1000);

SELECT @x;
*/

/*
delimiter $$

CREATE TRIGGER BoteTrigger
AFTER INSERT ON Bote
FOR EACH ROW
BEGIN
SET @bote = @bote + NEW.Cantidad;
IF NEW.IDPersona=3 THEN
NEW.Saldo = @bote;
@bote = 0;
ENDIF;
END$$

delimiter;*/

/*CREATE TRIGGER ins_sum BEFORE INSERT ON Bote
       FOR EACH ROW SET @Bote = @Bote + NEW.Cantidad;*/

INSERT INTO Bote VALUES (1, 200);
INSERT INTO Bote VALUES (2, 50);
INSERT INTO Bote VALUES (3, 2);

/*CREATE TABLE meses (mes varchar[20]);*/




/*
CREATE FUNCTION hello (s CHAR(20))
RETURNS CHAR(50) DETERMINISTIC
RETURN CONCAT('Hello, ',s,'!');
SELECT hello('world');
+----------------+
| hello('world') |
+----------------+
| Hello, world!  |
+----------------+
NUM('Enero','Febrero','Marzo','Abril','Mayo','Junio','Julio','Agosto','Septiembre','Octubre','Noviembre','Diciembre') */
/*
delimiter //
CREATE FUNCTION meses(numMes INT)
RETURNS VARCHAR(50) DETERMINISTIC
IF (numMes = 1) THEN RETURN CONCAT('El mes es: Enero', numMes); ENDIF;


	ELSEIF (numMes = 2) THEN
		RETURN CONCAT('El mes es: Febrero', numMes)
	ELSE
		RETURN CONCAT('El mes es: Marzo', numMes)
//

*/

EJERCICIOS

Nos piden hacer un procedimiento :
actualizacion limite credito(){
	crear tabla limite credito(copiar la tabla original para evitar pisarlo meter fecha, codigocliente, incrementa,incremento total)
incrementar en un porcentaje del 15%;
Incrementar SOLO a los clientes mas antiguos a 2010;
LimiteCredito   %   IncrementoTotal
15 000          10    16 500


}

Facturacion (){

Tabla Facturas(crea una lista de facturas)

ID(codigoFACTURA)   codCliente     codPedidos     PrecioTotal
}

select Empleados.Nombre, Empleados.Apellido1, Empleados.Puesto from Empleados, Clientes where Empleados.CodigoEmpleado not in (select CodigoEmpleadoRepVentas from Clientes) group by Empleados.CodigoEmpleado;

