#ifndef DT_PRODUCTOS_Y_VENDEDOR
#define DT_PRODUCTOS_Y_VENDEDOR

#include "DTVendedor.h"
#include "../vendedor.h"
#include "ParProdCant.h"
#include <set>

class DTProductosYVendedor
{
public:
	std::set<ParProdCant> productos;
	Vendedor vendedor;
	DTProductosYVendedor(std::set<ParProdCant> productos, Vendedor vendedor);
};

#endif // !DT_PRODUCTOS_Y_VENDEDOR
