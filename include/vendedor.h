// File: vendedor.h

#ifndef _VENDEDOR_H
#define _VENDEDOR_H

#include "./Datatypes/DTAltaVendedor.h"
#include "./Datatypes/DTNotificacion.h"
#include "usuario.h"
#include "observer.h"
#include "cliente.h"

#include <string>
using namespace std;

class Vendedor : public Usuario
{
private:
    string rut;
    set<string> productosAsociados;
    set<ObserverNotificacion *> observers;

public:
    // Constructor
    Vendedor(string nickname, string contrasenia, DTFecha fechaNac, string rut);

    // Destructor
    virtual ~Vendedor();

    // Getters
    string getRUT();
    string getNickname();
    set<string> getProductosAsociados();

    // Setters
    void setNickname(string rut);

    // Metodos
    void agregarSuscriptor(Cliente *c);
    void eliminarSuscriptor(Cliente *c);
    void notificar(DTNotificacion dtNotif);
    Vendedor *create(DTAltaVendedor altaVendedor);
};

#endif // _VENDEDOR_H
