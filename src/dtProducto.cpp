// File: dtProducto.cpp

#include "../include/dtProducto.h"

// Constructor

DTProducto::DTProducto(int codigo, int stock, int precio, string nombre, string descripcion, string tipo)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), tipo(tipo) {}

// Destructor

DTProducto::~DTProducto() {}

// Getters

int DTProducto::getCodigo() {
    return this->codigo;
}

int DTProducto::getStock() {
    return this->stock;
}

int DTProducto::getPrecio() {
    return this->precio;
}

string DTProducto::getNombre() {
    return this->nombre;
}

string DTProducto::getDescripcion() {
    return this->descripcion;
}

string DTProducto::getTipo() {
    return this->tipo;
}

// Setters

void DTProducto::setCodigo(int codigo) {
    this->codigo = codigo;
}

void DTProducto::setStock(int stock) {
    this->stock = stock;
}

void DTProducto::setPrecio(int precio) {
    this->precio = precio;
}

void DTProducto::setNombre(string nombre) {
    this->nombre = nombre;
}

void DTProducto::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void DTProducto::setTipo(string tipo) {
    this->tipo = tipo;
}
