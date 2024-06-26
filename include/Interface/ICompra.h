#ifndef _ICOMPRA_H
#define _ICOMPRA_H

#include <string>
#include <set>
#include "../promocion.h"
#include "../compra.h"
#include "../Datatypes/ParProdCant.h"
#include "../Datatypes/DTDetalleCompra.h"
using String = std::string;
class ICompra
{
public:
    virtual void eliminarTodasLasCompras() = 0;
    virtual void cargarCompra(Compra) = 0;
    virtual void registrarCompra() = 0;
    virtual void finalizarCompra() = 0;
    virtual std::set<String> listarClientes() = 0;
    virtual void seleccionarUsuario(String) = 0;
    virtual void seleccionarProducto(int, int) = 0;
    virtual DTDetalleCompra devolverDetalles() = 0;
    virtual ~ICompra(){};
    virtual std::set<DTDetalleCompra> obtenerCompras() = 0; 
};
#endif // _ICOMPRA_H
