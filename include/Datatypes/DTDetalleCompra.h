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
		int montoFinal;
		DTFecha fechaCompra;
		map<int, bool> produtosEnvio; 
		set<ParProdCant> productos;
		DTDetalleCompra(int id, int montoFinal, DTFecha fechaCompra, map<int, bool> produtosEnvio, set<ParProdCant> productos);
		~DTDetalleCompra();
		bool operator<(const DTDetalleCompra &otra) const;
};

#endif // !DT_DETALLE_COMPRA_H
