#ifndef DT_PRODUCTOS_Y_VENDEDOR
#define DT_PRODUCTOS_Y_VENDEDOR

#include "DTProducto.h"
#include "DTVendedor.h"
#include <set>
class DTProductosYVendedor {
public:
	std::set<DTProducto> productos;
	DTVendedor vendedor;
};

#endif // !DT_PRODUCTOS_Y_VENDEDOR
