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
  ControladorUsuarios *cu =  ControladorUsuarios::getInstance();
  r = cu->listarNoSuscritos(nickname);
  suscriptor = cu->obtenerCliente(nickname); 
  return r;
}
void ControladorSuscripciones::agregarSuscripcion(string nickname)
{
  suscriptor->getSuscripciones().insert(nickname);
}
void ControladorSuscripciones::confirmarSuscripcion()
{
  
}
set<string> ControladorSuscripciones::listarVendedoresSuscritos(string nickname)
{
  set<string> vs;
  ControladorUsuarios *cu = ControladorUsuarios::getInstance();
  set<string>  lv = cu->listarVendedores();
  set<string>  ns = cu->listarNoSuscritos(nickname);
  for (auto v: lv){
    if(ns.count(v) == 0){
      vs.insert(v);
    }
  }
  return vs;
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
