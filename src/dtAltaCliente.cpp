// File: dtAltaCliente.cpp

#include "../include/dtAltaCliente.h"

// Constructor

DTAltaCliente::DTAltaCliente(string nickname, DTFecha fechaNac, string contrasenia, string ciudad, string direccion)
    : nickname(nickname), fechaNac(fechaNac), contrasenia(contrasenia), ciudad(ciudad), direccion(direccion) {}

// Destructor

DTAltaCliente::~DTAltaCliente() {}

// Getters

string DTAltaCliente::getNickname() {
    return this->nickname;
}

DTFecha DTAltaCliente::getFechaNac() {
    return this->fechaNac;
}

string DTAltaCliente::getContrasenia() {
    return this->contrasenia;
}

string DTAltaCliente::getCiudad() {
    return this->ciudad;
}

string DTAltaCliente::getDireccion() {
    return this->direccion;
}

// Setters

void DTAltaCliente::setNickname(string nickname) {
    this->nickname = nickname;
}

void DTAltaCliente::setFechaNac(DTFecha fechaNac) {
    this->fechaNac = fechaNac;
}

void DTAltaCliente::setContrasenia(string contrasenia) {
    this->contrasenia = contrasenia;
}

void DTAltaCliente::setCiudad(string ciudad) {
    this->ciudad = ciudad;
}

void DTAltaCliente::setDireccion(string direccion) {
    this->direccion = direccion;
}
