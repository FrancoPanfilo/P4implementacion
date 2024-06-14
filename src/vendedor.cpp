// File vendedor.cpp

#include "../include/vendedor.h"
#include "../include/observer.h"
#include "../include/Datatypes/DTAltaVendedor.h"
#include <string>

using namespace std;

// Constructor

Vendedor::Vendedor(string nickname, string contrasenia, DTFecha fechaNac, int rut)
    : Usuario(nickname, contrasenia, fechaNac), rut(rut) {}

// Destructor

Vendedor::~Vendedor() {}

// Getters

int Vendedor::getRUT()
{
    return rut;
}

string Vendedor::getNickname()
{
    return Usuario::getNickname();
}

set<string> Vendedor::getProductosAsociados()
{
    return productosAsociados;
}

// Metodos

void Vendedor::agregarSuscriptor(Cliente *c)
{
    ObserverNotificacion *o = c;
    this->observers.insert(o);
}

void Vendedor::eliminarSuscriptor(Cliente *c)
{
    this->observers.erase(c);
}

void Vendedor::notificar(DTNotificacion dtNotif)
{
    // TODO
}

Vendedor *Vendedor::create(DTAltaVendedor altaVendedor)
{
    Vendedor *v = new Vendedor(altaVendedor.nickname, altaVendedor.contrasenia, altaVendedor.fechaNac, altaVendedor.RUT);
    return v;
}
