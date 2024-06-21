#include "../include/controladorPromociones.h"
#include <cstddef>
#include <cstdio>
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
		DTFecha fecha = DTFecha(local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
		Promocion *p = promo.second;
		if (p->getVencimiento() > fecha)
		{
			promocionesVigentes.insert(DTPromocion(p->getNombre(), p->getDescripcion(), p->getDescuento(), p->getVencimiento()));
		}
	}
	return promocionesVigentes;
}

DTProductosYVendedor ControladorPromociones::seleccionarPromocionPorNombre(string nombre)
{
	Promocion *p = promociones.at(nombre);
	Fabrica *f = f->getFabrica();
	IUsuario *cu = f->getIUsuarios();
	Vendedor *v = cu->obtenerVendedor(p->getVendedor());
	return DTProductosYVendedor(p->getProductos(), *v);
}

// no seberia devolver un set DTPromos?
map<string, Promocion *> ControladorPromociones::listarPromociones()
{
	return promociones;
}

void ControladorPromociones::ingresarDatosPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVenc)
{
	this->promocionTmp = DTPromocion(nombre, descripcion, descuento, fechaVenc);
}

void ControladorPromociones::agregarPromocion(Promocion p)
{
	Promocion *promo = new Promocion(p);
	promociones.insert(std::pair<string, Promocion *>(p.getNombre(), promo));
}

set<string> ControladorPromociones::obtenerNicknames()
{
	Fabrica *f = Fabrica::getFabrica();
	IUsuario *contUsuarios = f->getIUsuarios();
	return contUsuarios->listarVendedores();
}

void ControladorPromociones::seleccionarNickname(String n)
{
	this->nickname = n;
}

set<DTProducto> ControladorPromociones::obtenerProductosAsociados()
{
	Fabrica *f = Fabrica::getFabrica();
	IUsuario *contUsuarios = f->getIUsuarios();
	return contUsuarios->prodDeVendedor(this->nickname);
}
void ControladorPromociones::agregarProductoAPromocion(int codigo, int cantidad)
{
	Fabrica *f = Fabrica::getFabrica();
	IProducto *contProducto = f->getIProductos();
	Producto p = contProducto->obtenerProducto(codigo);
	ParProdCant ppp(p, cantidad);
	productosTmp.insert(ppp);
}

void ControladorPromociones::confirmarCrearPromocion()
{
	set<int> pCodigos;
	Promocion promo(promocionTmp, nickname);

	for (auto p : productosTmp)
	{
		pCodigos.insert(p.producto.getCodigo());
		promo.agregarAPromo(p.producto, p.cantidad);
	}
	Promocion *p = new Promocion(promo);
	this->promociones.insert(std::pair<string, Promocion *>(promo.getNombre(), p));
	Fabrica *f = Fabrica::getFabrica();
	IUsuario *contUsuarios = f->getIUsuarios();
	Vendedor *v = contUsuarios->obtenerVendedor(nickname);
	DTNotificacion notificacion(nickname, pCodigos, promo.getNombre());
	v->notificar(notificacion);
}

std::set<DTPromocion> ControladorPromociones::listarPromocionesVendedor(String nickname)
{
	std::set<DTPromocion> dtpromo;
	for (auto p : promociones)
	{
		Promocion *promo = p.second;
		if (promo->getVendedor() == nickname)
		{
			dtpromo.insert(DTPromocion(promo->getNombre(), promo->getDescripcion(), promo->getDescuento(), promo->getVencimiento()));
		}
	}
	return dtpromo;
}

Promocion *ControladorPromociones::obtenerPromocion(set<ParProdCant> ppp)
{
	Promocion *promo = NULL;
	std::map<string, Promocion *>::iterator it = this->promociones.begin();
	while (promo == NULL && it != promociones.end())
	{
		Promocion *p = it->second;
		promo = p->obtenerSiAplica(ppp);
		it++;
	}

	return promo;
}

int ControladorPromociones::obtenerDescuento(ParProdCant)
{
	// TODO
	return 0;
}
