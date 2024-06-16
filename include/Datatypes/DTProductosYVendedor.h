#ifndef DT_PRODUCTOS_Y_VENDEDOR
#define DT_PRODUCTOS_Y_VENDEDOR

#include "DTProducto.h"
#include "DTVendedor.h"
#include "../vendedor.h"
#include <set>
class DTProductosYVendedor
{
public:
	std::set<DTProducto> productos;
	Vendedor vendedor;
	DTProductosYVendedor(std::set<DTProducto> productos, Vendedor vendedor);
};

#endif // !DT_PRODUCTOS_Y_VENDEDOR
