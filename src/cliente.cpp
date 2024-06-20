// File cliente.cpp

#include "../include/cliente.h"

#include <string>

using namespace std;

// Constructor

Cliente::Cliente(string nickname, string contrasenia, DTFecha fechaNac, string direccion, string ciudad)
    : Usuario(nickname, contrasenia, fechaNac), direccion(direccion), ciudad(ciudad) {}

Cliente::Cliente(){};
// Destructor

Cliente::~Cliente() {}

// Getters

string Cliente::getDireccion() 
{
    return direccion;
}

string Cliente::getCiudad() 
{
    return ciudad;
}

set<DTNotificacion> Cliente::getNotificacionesPendientes()
 {
    return notificacionesPendientes;
}

set<string> Cliente::getSuscripciones() 
{
    return suscripciones;
}

string Cliente::getNickname()
{
    return Usuario::getNickname();
}

map <int, Compra> Cliente::getCompras()
{
    return compras;
}

// Setters

void Cliente::setNotificacionesPendientes(set<DTNotificacion> notificacionesPendientes) 
{
    this->notificacionesPendientes = notificacionesPendientes;
}

void Cliente::setSuscripciones(set<string> suscripciones) 
{
    this->suscripciones = suscripciones;
}

// Metodos

void Cliente::notificar(DTNotificacion notificacion) 
{
	notificacionesPendientes.insert(notificacion);
}

void Cliente::eliminarNotificacionesPendientes() 
{
    notificacionesPendientes.clear();
}

void Cliente::agregarSub(string nickname)
{
    suscripciones.insert(nickname);
}

void Cliente::eliminarSub(string nickname)
{
    suscripciones.erase(nickname);
}

Cliente *Cliente::create(DTAltaCliente altaCliente) 
{    
    
    Cliente *c = new Cliente(altaCliente.nickname, altaCliente.contrasenia, altaCliente.fechaNac, altaCliente.direccion, altaCliente.ciudad);
    return c;
}
