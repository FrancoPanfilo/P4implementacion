#include "../include/compra.h"

DTFecha Compra::getFechaCompra()
{
    return fechaCompra;
}
int Compra::getMontoFinal()
{
    return montoFinal;
}
map<DTProducto, int> Compra::getProductos()
{
    return productos;
}
Compra::Compra::Compra(DTFecha fechaCompra, int montoFinal, int id, map<DTProducto, int> productos)
    : fechaCompra(fechaCompra), montoFinal(montoFinal), id(id), productos(productos) {}
Compra::Compra(){}
Compra::~Compra(){}