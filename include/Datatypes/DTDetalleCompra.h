#ifndef DT_DETALLE_COMPRA_H
#define DT_DETALLE_COMPRA_H

#include "DTFecha.h"
#include "DTProducto.h"
#include <set>
class DTDetalleCompra {
	public:
		int precio;
		DTFecha fechaActual;
		std::set<DTProducto> productos;
};

#endif // !DT_DETALLE_COMPRA_H
