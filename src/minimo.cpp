#include "../include/minimo.h"

Minimo::Minimo(Producto *p, int cantidad)
    : producto(p), cantidad(cantidad) {}
Minimo::Minimo()
    : producto(NULL) {}
int Minimo::getCantidad()
{
    return this->cantidad;
}
Producto* Minimo::getProducto()
{
    return this->producto;
}
/*
bool Minimo::verificarMinimo(std::set<ParProdCant> prod)
{
    return cantidad <= prod.cantidad;
} */
