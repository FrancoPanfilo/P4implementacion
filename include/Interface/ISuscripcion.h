#ifndef ISUSCRIPCION_H
#define ISUSCRIPCION_H

#include <set>
#include <string>
#include "../Datatypes/DTNotificacion.h"

using namespace std;

class ISuscripcion
{
public:
    virtual set<string> listarNoSuscritos(string nickname) = 0;
    virtual void agregarSuscripcion(string nickname) = 0;
    virtual void confirmarSuscripcion() = 0;
    virtual set<string> listarVendedoresSuscritos(string nickname) = 0;
    virtual void eliminarSuscriptor(string nickname) = 0;
    virtual set<DTNotificacion> consultarNotificacionesRecibidas(string nickname) = 0;
    virtual void eliminarNotificaciones() = 0;
    virtual ~ISuscripcion(){};
};

#endif // ISUSCRIPCION_H