#ifndef DT_DETALLE_COMPRA_H
#define DT_DETALLE_COMPRA_H

#include "DTFecha.h"
#include "DTProducto.h"
#include "ParProdCant.h"
#include <set>
#include <map>
#include <string>
class DTDetalleCompra {
	public:
		int id;
		double montoFinal;
		DTFecha fechaCompra;
		map<int, bool> productosEnvio; 
		set<ParProdCant> productos;
		string cliente;
		DTDetalleCompra(int id, double montoFinal, DTFecha fechaCompra, map<int, bool> productosEnvio, set<ParProdCant> productos, string cliente);
		DTDetalleCompra(int id, double montoFinal, DTFecha fechaCompra, string cliente);
		DTDetalleCompra();
		~DTDetalleCompra();
		bool operator<(const DTDetalleCompra &otra) const;
};

#endif // !DT_DETALLE_COMPRA_H
