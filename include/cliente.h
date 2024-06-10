// File: cliente.h

#ifndef _CLIENTE_H
#define _CLIENTE_H

#include "dtNotificacion.h"
#include "dtAltaCliente.h"
#include "usuario.h"

#include <string>
#include <set>

using namespace std;

class Cliente : private Usuario, public ObserverNotificacion {
private:
    string direccion;
    string ciudad;
    set<DTNotificacion> notificacionesPendientes;
    set<string> suscripciones;
public:
    // Constructor
    Cliente(string direccion, string ciudad, set<DTNotificacion> notificacionesPendientes, set<string> suscripciones);

    // Destructor
    virtual ~Cliente();

    // Getters
    string getDireccion();
    string getCiudad();
    set<DTNotificacion> getNotificacionesPendientes();
    set<string> getSuscripciones();
    string getNickname();

    // Setters
    void setDireccion(string direccion);
    void setCiudad(string ciudad);
    void setNotificacionesPendientes(set<DTNotificacion> notificacionesPendientes);
    void setSuscripciones(set<string> suscripciones);

    // Metodos
    void notificar();
    void eliminarNotificacionesPendientes(); // Se eliminan todas las instancias de DTNotificacion del campo notifiacionesPendientes del cliente
    void create(DTAltaCliente altaCliente);
};

#endif  // _CLIENTE_H