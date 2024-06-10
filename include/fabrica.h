#ifndef _FABRICA_H
#define _FABRICA_H

#include <string>
#include <set>
#include "./controladorProductos.h"
#include "./controladorComentarios.h"
#include "./controladorPromociones.h"
#include "./controladorUsuarios.h"
#include "./controladorCompras.h"
#include "./controladorSuscripciones.h"
using String = std::string;
class Fabrica
{
private:
    ControladorComentarios iComentarios;
    ControladorUsuarios iUsuarios;
    ControladorSuscripciones iSuscripciones;
    ControladorProductos iProductos;
    ControladorCompras iCompras;
    ControladorPromociones iPromociones;

public:
    Fabrica();
    ~Fabrica();

    void setIComentarios(ControladorComentarios);
    ControladorComentarios getIComentarios();
    void setIUsuarios(ControladorUsuarios);
    ControladorUsuarios getIUsuarios();
    void setISuscripciones(ControladorSuscripciones);
    ControladorSuscripciones getISuscripciones();
    void setIProductos(ControladorProductos);
    ControladorProductos getIProductos();
    void setICompras(ControladorCompras);
    ControladorCompras getICompras();
    void setIPromociones(ControladorPromociones);
    ControladorPromociones getIPromociones();
};
#endif // _FABRICA_H