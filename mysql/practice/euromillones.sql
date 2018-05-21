DROP DATABASE IF EXISTS euroMillones;
CREATE DATABASE euroMillones;

USE euroMillones;

CREATE TABLE Bote(
		  ID int auto_increment,
		  Cantidad int,
		  PRIMARY KEY (ID)
		 );
/*SET @bote = 0;*/

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






CREATE FUNCTION hello (s CHAR(20))
RETURNS CHAR(50) DETERMINISTIC
RETURN CONCAT('Hello, ',s,'!');
SELECT hello('world');
+----------------+
| hello('world') |
+----------------+
| Hello, world!  |
+----------------+

CREATE FUNCTION meses(numMes TINYINT)
DECLARE mes ENUM('Enero','Febrero','Marzo','Abril','Mayo','Junio','Julio','Agosto','Septiembre','Octubre','Noviembre','Diciembre');
IF(mes == numMes)
RETURNS CONCAT('El mes es: ',mes);




