#include "../include/controladorPromociones.h"
#include <cstddef>
#include <set>
#include <string>
#include <ctime>
#include "../include/Interface/IUsuario.h"
#include "../include/fabrica.h"
using namespace std;

ControladorPromociones *ControladorPromociones::instance = NULL;

ControladorPromociones::ControladorPromociones() {}
ControladorPromociones::~ControladorPromociones() {}

ControladorPromociones *ControladorPromociones::getInstance()
{
	if (instance == NULL)
	{
		instance = new ControladorPromociones();
	}
	return instance;
}

set<DTPromocion> ControladorPromociones::obtenerPromocionesVigentes()
{
	// TODO
	set<DTPromocion> promocionesVigentes;
	for (auto promo : promociones)
	{
		time_t ahora = time(0);
		tm *local = localtime(&ahora);
		DTFecha fecha = DTFecha(local->tm_mday, local->tm_mon, local->tm_year);
		if (fecha > promo.second.getVencimiento())
		{
			promocionesVigentes.insert(DTPromocion(promo.second.getNombre(), promo.second.getDescripcion(), promo.second.getDescuento(), promo.second.getVencimiento()));
		}
	}
	return promocionesVigentes;
}

DTProductosYVendedor ControladorPromociones::seleccionarPromocionPorNombre(string nombre)
{
	Promocion p = promociones.at(nombre);
	return DTProductosYVendedor(p.getProductos(), p.getVendedor());
}

void ControladorPromociones::ingresarDatosPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVenc)
{
	promocionTmp = DTPromocion(nombre, descripcion, descuento, fechaVenc);
}

/*
 * Devuelve una promoción si el conjunto de productos y cantidades aplica para la promoción
 * Si no, devuelve NULL
 * */
Promocion *ControladorPromociones::obtenerPromocion(set<ParProdCant>)
{
	Promocion *promo;
	return promo;
}
set<string> ControladorPromociones::obtenerNicknames()
{
	Fabrica *f = Fabrica::getFabrica();
	IUsuario *contUsuarios = f->getIUsuarios();
	return contUsuarios->listarVendedores();
}

void ControladorPromociones::seleccionarNickname(String)
{
	// TODO
}
void ControladorPromociones::agregarProductoAPromocion(int, int)
{
	// TODO
}
set<DTProducto> ControladorPromociones::obtenerProductosAsociados(String)
{
	// TODO
}
void ControladorPromociones::confirmarCrearPromocion()
{
	// TODO
}
int ControladorPromociones::obtenerDescuento(ParProdCant)
{
	// TODO
	return 0;
}
