#ifndef CONTROLADOR_SUSCRIPCIONES_H
#define CONTROLADOR_SUSCRIPCIONES_H

#include <set>
#include <string>
#include "./Datatypes/DTNotificacion.h"
#include "./Interface/ISuscripcion.h"
#include "./cliente.h"
using namespace std;

class ControladorSuscripciones : public ISuscripcion
{
private:
    static ControladorSuscripciones *instance;
    ControladorSuscripciones();
    ~ControladorSuscripciones();
    Cliente suscriptor;

public:
    static ControladorSuscripciones *getInstance();
    set<string> listarNoSuscritos(string nickname);
    void agregarSuscripcion(string nickname);
    void confirmarSuscripcion();
    set<string> listarVendedoresSuscritos(string nickname);
    void eliminarSuscriptor(string nickname);
    set<DTNotificacion> consultarNotificacionesRecibidas(string nickname);
    void eliminarNotificaciones();
};

#endif // !CONTROLADOR_SUSCRIPCIONES_H
