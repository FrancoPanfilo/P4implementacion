// File: dtAltaVendedor.cpp

#include "../include/dtAltaVendedor.h"

// Constructor

DTAltaVendedor::DTAltaVendedor(string nickname, DTFecha fechaNac, string contrasenia, string rut)
    : nickname(nickname), fechaNac(fechaNac), contrasenia(contrasenia), rut(rut) {}

// Destructor

DTAltaVendedor::~DTAltaVendedor() {}

// Getters

string DTAltaVendedor::getNickname() {
    return this->nickname;
}

DTFecha DTAltaVendedor::getFechaNac() {
    return this->fechaNac;
}

string DTAltaVendedor::getContrasenia() {
    return this->contrasenia;
}

string DTAltaVendedor::getRut() {
    return this->rut;
}

// Setters

void DTAltaVendedor::setNickname(string nickname) {
    this->nickname = nickname;
}

void DTAltaVendedor::setFechaNac(DTFecha fechaNac) {
    this->fechaNac = fechaNac;
}

void DTAltaVendedor::setContrasenia(string contrasenia) {
    this->contrasenia = contrasenia;
}

void DTAltaVendedor::setRut(string rut) {
    this->rut = rut;
}
