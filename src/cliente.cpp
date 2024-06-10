// File cliente.cpp

#include "../include/cliente.h"

#include <string>

using namespace std;

// Constructor

Cliente::Cliente(string direccion, string ciudad, set<DTNotificacion> notificacionesPendientes, set<string> suscripciones) 
    : direccion(direccion), ciudad(ciudad), notificacionesPendientes(notificacionesPendientes), suscripciones(suscripciones) {}

// Destructor

Cliente::~Cliente() {}

// Getters

string Cliente::getDireccion() {
    return direccion;
}

string Cliente::getCiudad() {
    return ciudad;
}

set<DTNotificacion> Cliente::getNotificacionesPendientes() {
    return notificacionesPendientes;
}

set<string> Cliente::getSuscripciones() {
    return suscripciones;
}

string Cliente::getNickname() {
    return Usuario::getNickname();
}

// Setters

void Cliente::setDireccion(string direccion) {
    this->direccion = direccion;
}

void Cliente::setCiudad(string ciudad) {
    this->ciudad = ciudad;
}

void Cliente::setNotificacionesPendientes(set<DTNotificacion> notificacionesPendientes) {
    this->notificacionesPendientes = notificacionesPendientes;
}

void Cliente::setSuscripciones(set<string> suscripciones) {
    this->suscripciones = suscripciones;
}

// Metodos

void Cliente::eliminarNotificacionesPendientes() {
    notificacionesPendientes.clear();
}

void Cliente::create(DTAltaCliente altaCliente) {
    // TODO
}
