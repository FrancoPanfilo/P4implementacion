// File: cliente.h

#ifndef _CLIENTE_H
#define _CLIENTE_H

#include "./Datatypes/DTNotificacion.h"
#include "./Datatypes/DTAltaCliente.h"
#include "usuario.h"
#include "observer.h"
#include "compra.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Cliente : public Usuario, public ObserverNotificacion
{
private:
    string direccion;
    string ciudad;
    set<DTNotificacion> notificacionesPendientes;
    set<string> suscripciones;
    map<int, Compra *> compras;

public:
    // Constructor
    Cliente(string nickname, string contrasenia, DTFecha fechaNac, string direccion, string ciudad);
    Cliente();
    // Destructor
    ~Cliente();
    // Getters
    string getDireccion();
    string getCiudad();
    set<DTNotificacion> getNotificacionesPendientes();
    set<string> getSuscripciones();
    string getNickname();
    map<int, Compra *> getCompras();

    // Setters
    void setNotificacionesPendientes(set<DTNotificacion> notificacionesPendientes);
    void setSuscripciones(set<string> suscripciones);

    // Metodos
    void notificar(DTNotificacion notificacion);
    void eliminarNotificacionesPendientes(); // Se eliminan todas las instancias de DTNotificacion del campo notifiacionesPendientes del cliente
    Cliente *create(DTAltaCliente altaCliente);

    void agregarSub(string nickname);
    void eliminarSub(string nickname);
    void agregarCompra(Compra*);
    void enviar(int cC, int cP);
};

#endif // _CLIENTE_H
