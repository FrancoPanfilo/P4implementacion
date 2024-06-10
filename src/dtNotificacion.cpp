// File: dtNotificacion.cpp

#include "../include/dtNotificacion.h"

// Constructor

DTNotificacion::DTNotificacion(string nombreVendedor, set<int> productos, string nombrePromo)
    : nombreVendedor(nombreVendedor), productos(productos), nombrePromo(nombrePromo) {}

// Destructor

DTNotificacion::~DTNotificacion() {}

// Getters

string DTNotificacion::getNombreVendedor() {
    return this->nombreVendedor;
}

set<int> DTNotificacion::getProductos() {
    return this->productos;
}

string DTNotificacion::getNombrePromo() {
    return this->nombrePromo;
}

// Setters

void DTNotificacion::setNombreVendedor(string nombreVendedor) {
    this->nombreVendedor = nombreVendedor;
}

void DTNotificacion::setProductos(set<int> productos) {
    this->productos = productos;
}

void DTNotificacion::setNombrePromo(string nombrePromo) {
    this->nombrePromo = nombrePromo;
}
