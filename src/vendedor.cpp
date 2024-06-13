// File vendedor.cpp

#include "../include/vendedor.h"
#include "../include/observer.h"
#include "../include/Datatypes/DTAltaVendedor.h"
#include <string>

using namespace std;

// Constructor

Vendedor::Vendedor(string nickname, string contrasenia, DTFecha fechaNac, string rut)
    : Usuario(nickname, contrasenia, fechaNac), rut(rut) {}

// Destructor

Vendedor::~Vendedor() {}

// Getters

string Vendedor::getRUT()
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

// Setters

void Vendedor::setNickname(string rut)
{
    Usuario::setNickname(rut);
}

// Metodos

void Vendedor::agregarSuscriptor(Cliente *c)
{
    ObserverNotificacion *o = c;
    this->observers.insert(o);
}

void Vendedor::eliminarSuscriptor(Cliente *c)
{
    //
}

void Vendedor::notificar(DTNotificacion dtNotif)
{
    // TODO
}

Vendedor *Vendedor::create(DTAltaVendedor altaVendedor)
{
    Vendedor *v = new Vendedor(altaVendedor.nickname, altaVendedor.fechaNac, altaVendedor.contrasenia, altaVendedor.RUT);
    return v;
}
