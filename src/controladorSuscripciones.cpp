#include "../include/controladorSuscripciones.h"
#include "../include/controladorUsuarios.h"
#include <iostream>
#include <set>
#include <map>
#include <stdexcept>

ControladorSuscripciones *ControladorSuscripciones::instance = NULL;

ControladorSuscripciones::ControladorSuscripciones() {}
ControladorSuscripciones::~ControladorSuscripciones() {}

ControladorSuscripciones *ControladorSuscripciones::getInstance()
{
  if (instance == NULL)
  {
    instance = new ControladorSuscripciones();
  }
  return instance;
}

set<string> ControladorSuscripciones::listarNoSuscritos(string nickname)
{
  set<string> r;
  ControladorUsuarios *cu;
  *ControladorUsuarios::getInstance() = *cu;
  r = cu->listarNoSuscritos(nickname);
  suscriptor = cu->obtenerCliente(nickname); 
  //suscriptor = 
  return r;
}
void ControladorSuscripciones::agregarSuscripcion(string nickname)
{
  suscriptor.getSuscripciones().insert(nickname);
}
void ControladorSuscripciones::confirmarSuscripcion()
{
  
}
set<string> ControladorSuscripciones::listarVendedoresSuscritos(string nickname)
{
}
void ControladorSuscripciones::eliminarSuscriptor(string nickname)
{
}
set<DTNotificacion> ControladorSuscripciones::consultarNotificacionesRecibidas(string nickname)
{
}
void ControladorSuscripciones::eliminarNotificaciones()
{
}
