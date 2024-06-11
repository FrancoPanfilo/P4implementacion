#ifndef ISUSCRIPCION_H
#define ISUSCRIPCION_H

#include <set>
#include <string>
#include "./Datatypes/DTNotificacion.h"

using namespace std;

class ISuscripcion
{
public:
    virtual set<string> listarNoSuscritos(string nickname);
    virtual void agregarSuscripcion(string nickname);
    virtual void confirmarSuscripcion();
    virtual set<string> listarVendedoresSuscritos(string nickname);
    virtual void eliminarSuscriptor(string nickname);
    virtual set<DTNotificacion> consultarNotificacionesRecibidas(string nickname);
    virtual void eliminarNotificaciones();
    virtual ~ISuscripcion(){};
};

#endif // ISUSCRIPCION_H