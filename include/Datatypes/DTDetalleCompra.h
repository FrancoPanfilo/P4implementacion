#ifndef DT_DETALLE_COMPRA_H
#define DT_DETALLE_COMPRA_H

#include "DTFecha.h"
#include "DTProducto.h"
#include <set>
#include <map>
class DTDetalleCompra {
	public:
		int id;
		int montoFinal;
		DTFecha fechaCompra;
		//map<DTProducto, bool> produtosEnvio; cuidar cantidad si se usa esto
		map<DTProducto, int> productos;
		bool todoEnviado;
		DTDetalleCompra(int id, int montoFinal, DTFecha fechaCompra,map<DTProducto, int> productos, bool todoEnviado);
		~DTDetalleCompra();
		bool operator<(const DTDetalleCompra &otra) const;
};

#endif // !DT_DETALLE_COMPRA_H
