Sacar la dirección del cliente que más se ha gastado.
SELECT Pedidos.CodigoPedido, Pedidos.CodigoCliente, SUM(DetallePedidos.PrecioUnidad*DetallePedidos.Cantidad) FROM Pedidos NATURAL JOIN DetallePedidos GROUP BY Pedidos.CodigoPedido ORDER BY SUM(DetallePedidos.PrecioUnidad*DetallePedidos.Cantidad) DESC LIMIT 1;

