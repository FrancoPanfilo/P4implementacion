#ifndef _IPROMOCION_H
#define _IPROMOCION_H

#include <string>
#include <set>
#include "./promocion.h"
#include "./Datatypes/ParProdCant.h"
#include "./Datatypes/DTProducto.h"
#include "./Datatypes/DTFecha.h"

using String = std::string;

class IPromocion
{
public:
    virtual void ingresarDatosPromocion(String, String, int, DTFecha) = 0;
    virtual Promocion obtenerPromocion(std::set<ParProdCant>) = 0;
    virtual std::set<String> obtenerNicknames() = 0;
    virtual void seleccionarNickname(String) = 0;
    virtual void agregarProductosAPromocion(int, int) = 0;
    virtual std::set<DTProducto> obtenerProductosAsociados(String) = 0;
    virtual void confirmarCrearPromocion() = 0;
    virtual int obtenerDescuento(ParProdCant) = 0;
    virtual ~IPromocion(){};
};

#endif // _IPROMOCION_H