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

set<DTProducto> Vendedor::getProductosAsociados()
{
    set<DTProducto> pa;
    for (auto p : productosAsociados)
    {
        DTProducto elem(p.second.getCodigo(), p.second.getStock(), p.second.getPrecio(), p.second.getNombre(), p.second.getDescripcion(), p.second.getTipo());
        pa.insert(elem);
    }
    return pa;
}

// Metodos
void Vendedor::agregarProducto(Producto p)
{
    productosAsociados.insert(std::pair<int, Producto>(p.getCodigo(), p));
}
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
