// // File: producto.cpp

#include "../include/producto.h"
Producto::Producto(DTProducto dtp)
    : codigo(dtp.codigo), stock(dtp.stock), precio(dtp.precio),
      nombre(dtp.nombre), descripcion(dtp.descripcion), tipo(dtp.tipo) {}

Producto::Producto(int cod, int stk, double prc, string nom, string desc, string tp)
    : codigo(cod), stock(stk), precio(prc), nombre(nom), descripcion(desc), tipo(tp) {}

int Producto::getCodigo() const
{
    return codigo;
}

int Producto::getStock()
{
    return stock;
}

double Producto::getPrecio()
{
    return precio;
}

string Producto::getNombre()
{
    return nombre;
}

string Producto::getDescripcion()
{
    return descripcion;
}

string Producto::getTipo()
{
    return tipo;
}
