#ifndef _IPRODUCTO_H
#define _IPRODUCTO_H

#include <string>
#include <set>
#include "../producto.h"
#include "../Datatypes/DTProductoId.h"
#include "../Datatypes/DTProducto.h"
#include "../Datatypes/ParProdCant.h"
#include "../Datatypes/EnviosPendientes.h"

using String = std::string;
class IProducto
{

public:
	virtual std::set<DTProducto> listarProductosConId() = 0;
	virtual void seleccionarProductoPorCodigo(int) = 0;
	virtual DTProducto mostrarProducto() = 0;
	virtual ParProdCant seleccionarProducto(int, int) = 0;
	virtual Producto* obtenerProducto(int) = 0;
	virtual void altaProducto(string, DTProducto) = 0;

	// virtual std::set<string> listarVendedores() = 0;
	// virtual std::set<DTProducto> seleccionarVendedor(string nickname) = 0;
	virtual std::set<EnviosPendientes> seleccionarProductoAEnviar(int) = 0;
	virtual void seleccionarVenta(EnviosPendientes env) = 0;


	virtual void elegirProducto(string) = 0;
	virtual void crearProducto(DTProducto) = 0;
	virtual ~IProducto(){};
	virtual void eliminarTodosLosProductos() = 0;
};

#endif // _IPRODUCTO_H
