#ifndef _CONTROLADORPRODUCTOS_H
#define _CONTROLADORPRODUCTOS_H

#include <string>
#include <set>
#include "./producto.h"
#include "./datatypes.h"
using String = std::string;
class ControladorProductos
{
private:
    std::set<Producto> productos;
    // es posible que se agreguen mas atributos para facilitar algunos procesos
public:
    ControladorProductos();
    ~ControladorProductos();
    std::set<DTProducto> listarProductos();
    int seleccionarProducto(int, int);
    void agregarAPromo(String, int, int);
    Producto obtenerProducto(int);
};

#endif // _CONTROLADORPRODUCTOS_H
