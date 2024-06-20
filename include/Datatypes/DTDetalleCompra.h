#ifndef DT_DETALLE_COMPRA_H
#define DT_DETALLE_COMPRA_H

#include "DTFecha.h"
#include "DTProducto.h"
#include "ParProdCant.h"
#include <set>
#include <map>
class DTDetalleCompra {
	public:
		int id;
		double montoFinal;
		DTFecha fechaCompra;
		map<int, bool> productosEnvio; 
		set<ParProdCant> productos;
		DTDetalleCompra(int id, double montoFinal, DTFecha fechaCompra, map<int, bool> productosEnvio, set<ParProdCant> productos);
		DTDetalleCompra();
		~DTDetalleCompra();
		bool operator<(const DTDetalleCompra &otra) const;
};

#endif // !DT_DETALLE_COMPRA_H
