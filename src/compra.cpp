#include "../include/compra.h"

DTFecha Compra::getFechaCompra()
{
    return fechaCompra;
}
double Compra::getMontoFinal()
{
    return montoFinal;
}

int Compra::getId()
{
    return id;
}

set<ParProdCant> Compra::getProductos()
{
    return productos;
}

map<int, bool> Compra::getEnvios()
{
    return envios;
}

Cliente* Compra::getCliente() {
	return cliente;
}

Compra::Compra(DTFecha fechaCompra, double montoFinal, int id, set<ParProdCant> productos, map<int, bool> envios, Cliente* cliente, string promo)
    : fechaCompra(fechaCompra), montoFinal(montoFinal), id(id), productos(productos), envios(envios), cliente(cliente) {}

Compra::Compra(DTFecha fechaCompra, double montoFinal, int id, Cliente *cliente)
    : fechaCompra(fechaCompra), montoFinal(montoFinal), id(id), cliente(cliente) {}

Compra::Compra()
    : cliente(NULL) {}
Compra::~Compra(){}

void Compra::enviarEnCompra(int cp){
    envios.at(cp) = true;
}

void Compra::agregarProductosYEnvios(int codigo, int cantidad, bool enviado){
    productos.insert(ParProdCant(codigo, cantidad));
    envios.insert(std::pair<int, bool>(codigo, enviado));
}

void Compra::agregarPromocion(string nombrePromo){
    promocionCumplida = nombrePromo;
}