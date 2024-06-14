// File: cliente.h

#ifndef _CLIENTE_H
#define _CLIENTE_H

#include "./Datatypes/DTNotificacion.h"
#include "./Datatypes/DTAltaCliente.h"
#include "usuario.h"
#include "observer.h"

#include <string>
#include <set>

using namespace std;

class Cliente : public Usuario, public ObserverNotificacion
{
private:
    string direccion;
    string ciudad;
    set<DTNotificacion> notificacionesPendientes;
    set<string> suscripciones;

public:
    // Constructor
    Cliente(string nickname, string contrasenia, DTFecha fechaNac, string direccion, string ciudad);

    // Destructor
    virtual ~Cliente();

    // Getters
    string getDireccion();
    string getCiudad();
    set<DTNotificacion> getNotificacionesPendientes();
    set<string> getSuscripciones();
    string getNickname();

    // Setters
    void setNotificacionesPendientes(set<DTNotificacion> notificacionesPendientes);
    void setSuscripciones(set<string> suscripciones);

    // Metodos
    void notificar();
    void eliminarNotificacionesPendientes(); // Se eliminan todas las instancias de DTNotificacion del campo notifiacionesPendientes del cliente
    Cliente *create(DTAltaCliente altaCliente);
};

#endif // _CLIENTE_H
