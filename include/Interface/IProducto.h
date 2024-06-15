#ifndef _IPRODUCTO_H
#define _IPRODUCTO_H

#include <string>
#include <set>
#include "../producto.h"
#include "../Datatypes/DTProductoId.h"
#include "../Datatypes/DTProducto.h"
#include "../Datatypes/EnviosPendientes.h"

using String = std::string;
class IProducto
{

public:
	virtual std::set<DTProductoId> listarProductosConId() = 0;
	virtual void seleccionarProductoPorCodigo(int) = 0;
	virtual DTProducto mostrarProducto() = 0;
	// virtual int seleccionarProducto(int, int) = 0;
	// virtual void agregarAPromo(String, int, int) = 0;
	// virtual Producto obtenerProducto(int) = 0;

	virtual std::set<string> listarVendedores() = 0;
	virtual std::set<DTProducto> seleccionarVendedor(string nickname) = 0;
	virtual std::set<EnviosPendientes> seleccionarProductoAEnviar(int) = 0;
	virtual void seleccionarVenta(EnviosPendientes env) = 0;

	virtual ~IProducto(){};
};

#endif // _IPRODUCTO_H
