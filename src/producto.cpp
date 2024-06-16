// // File: producto.cpp

#include "../include/producto.h"

int Producto::getCodigo() {
    return codigo;
}

int Producto::getStock() {
    return stock;
}

int Producto::getPrecio() {
    return precio;
}

String Producto::getNombre() {
    return nombre;
}

String Producto::getDescripcion() {
    return descripcion;
}

String Producto::getTipo() {
    return tipo;
}

void Producto::agregarAPromo(String nombrePromo, int cantidad) {
    // TODO
}
