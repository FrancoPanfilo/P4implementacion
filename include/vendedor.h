// File: vendedor.h

#ifndef _VENDEDOR_H
#define _VENDEDOR_H

#include "dtNotificacion.h"
#include "dtAltaVendedor.h"
#include "usuario.h"

#include <string>

using namespace std;

class Vendedor : public Usuario {
private:
    string rut;
    set<string> productosAsociados;
public:
    // Constructor
    Vendedor(string rut);

    // Destructor
    virtual ~Vendedor();

    // Getters
    string getRUT();
    string getNickname();
    void getProductosAsociados();

    // Setters
    void setNickname(string rut);

    // Metodos
    void agregarSuscriptor();
    void eliminarSuscriptor();
    void notificar(DTNotificacion dtNotif);
    void create(DTAltaVendedor altaVendedor);
};

#endif  // _VENDEDOR_H