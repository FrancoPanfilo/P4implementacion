#ifndef _IPRODUCTO_H
#define _IPRODUCTO_H

#include <string>
#include <set>
#include "../producto.h"
#include "../Datatypes/DTProducto.h"
using String = std::string;
class IProducto
{

public:
    // virtual std::set<DTProducto> listarProductos() = 0;
    // virtual int seleccionarProducto(int, int) = 0;
    // virtual void agregarAPromo(String, int, int) = 0;
    // virtual Producto obtenerProducto(int) = 0;
    virtual ~IProducto(){};
};

#endif // _IPRODUCTO_H
