// File vendedor.cpp

#include "../include/vendedor.h"

#include <string>

using namespace std;

// Constructor

Vendedor::Vendedor(string rut) 
    : rut(rut) {}

// Destructor

Vendedor::~Vendedor() {}

// Getters

string Vendedor::getRUT() {
    return rut;
}

string Vendedor::getNickname() {
    return Usuario::getNickname();
}

void Vendedor::getProductosAsociados() {
    return productosAsociados;
}

// Setters

void Vendedor::setNickname(string rut) {
    Usuario::setNickname(rut);
}

// Metodos

void Vendedor::agregarSuscriptor() {
    // TODO
}

void Vendedor::eliminarSuscriptor() {
    // TODO
}

void Vendedor::notificar(DTNotificacion dtNotif) {
    // TODO
}

void Vendedor::create(DTAltaVendedor altaVendedor) {
    // TODO
}
