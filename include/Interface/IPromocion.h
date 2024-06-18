#ifndef _IPROMOCION_H
#define _IPROMOCION_H

#include <string>
#include <set>
#include "../promocion.h"
#include "../Datatypes/ParProdCant.h"
#include "../Datatypes/DTProducto.h"
#include "../Datatypes/DTPromocion.h"
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DTProductosYVendedor.h"

using string = std::string;

class IPromocion
{
public:
    virtual void agregarPromocion(Promocion) = 0;
    virtual void ingresarDatosPromocion(string, string, int, DTFecha) = 0;
    // virtual Promocion obtenerPromocion(std::set<ParProdCant>) = 0;
    virtual std::set<string> obtenerNicknames() = 0;
    virtual void seleccionarNickname(string) = 0;
    virtual void agregarProductoAPromocion(int, int) = 0;
    virtual std::set<DTProducto> obtenerProductosAsociados(string) = 0;
    virtual void confirmarCrearPromocion() = 0;
    // virtual int obtenerDescuento(ParProdCant) = 0;
    virtual ~IPromocion(){};
    virtual std::set<DTPromocion> listarPromocionesVendedor(string) = 0;
    virtual std::set<DTPromocion> obtenerPromocionesVigentes() = 0;
    virtual DTProductosYVendedor seleccionarPromocionPorNombre(string) = 0;
};

#endif // _IPROMOCION_H
