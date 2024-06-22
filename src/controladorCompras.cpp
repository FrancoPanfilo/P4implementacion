#include "../include/controladorCompras.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorProductos.h"
#include "../include/controladorPromociones.h"

#include <ctime>
#include <stdexcept>

using namespace std;

ControladorCompras *ControladorCompras::instance = NULL;

ControladorCompras::ControladorCompras()
{
	int idC = 0;
}
ControladorCompras::~ControladorCompras(){};

ControladorCompras *ControladorCompras::getInstance()
{
	if (instance == NULL)
	{
		instance = new ControladorCompras();
	}
	return instance;
}

set<string> ControladorCompras::listarClientes()
{
	ControladorUsuarios *cu = ControladorUsuarios::getInstance();
	set<string> resultado = cu->listarClientes();
	return resultado;
}

void ControladorCompras::seleccionarUsuario(String nickname)
{
	ControladorUsuarios *cu = ControladorUsuarios::getInstance();
	cliente = cu->obtenerCliente(nickname);
	time_t ahora = time(0);
	tm *local = localtime(&ahora);
	fechaActual = DTFecha(local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
}

void ControladorCompras::seleccionarProducto(int cantidad, int id)
{
	ControladorProductos *cpro = ControladorProductos::getInstance();
	Producto prod = cpro->obtenerProducto(id);
	ParProdCant par = ParProdCant(prod, cantidad);
	// control producto no repetido
	bool repetido = false;
	for (auto p : datosProductos)
	{
		repetido = (p.producto.getCodigo() == par.producto.getCodigo());
		if (repetido)
		{
			throw std::runtime_error("Producto ya seleccionado anteriormente. ");
		}
	}
	datosProductos.insert(par);
	envios.insert(std::pair<int, bool>(id, false));
	// bajar y controlar el stock
}

DTDetalleCompra ControladorCompras::devolverDetalles()
{
	// checkear si el carrito esta vacio?
	double total = 0;
	ControladorPromociones *cprom = ControladorPromociones::getInstance();
	Promocion *promo = cprom->obtenerPromocion(datosProductos);
	if (promo != NULL)
	{
		double desc = promo->getDescuento();
		set<DTProducto> pd = promo->getProductos();
		for (auto p : datosProductos)
		{
			Producto pr = p.producto;
			if (pd.count(DTProducto(pr.getCodigo(), pr.getStock(), pr.getPrecio(), pr.getNombre(), pr.getDescripcion(), pr.getTipo())) == 1)
			{
				total += (p.cantidad * pr.getPrecio()) - (p.cantidad * pr.getPrecio() * desc / 100); //(p.cantidad * pr.getPrecio()) - (p.cantidad * pr.getPrecio()) / desc;
			}
			else
			{
				total += p.cantidad * pr.getPrecio();
			}
		}
	}
	else
	{
		for (auto p : datosProductos)
		{
			Producto pr = p.producto;
			total += p.cantidad * pr.getPrecio();
		}
	};
	idC++;
	compraActual = DTDetalleCompra(idC, total, fechaActual, envios, datosProductos, nickname);
	return compraActual;
}

void ControladorCompras::registrarCompra()
{
	Compra compra = Compra(fechaActual, compraActual.montoFinal, idC, datosProductos, envios, cliente);
	Compra *c = new Compra(compra);
	cliente->getCompras().insert(std::pair<int, Compra *>(idC, c));
	compras.insert((std::pair<int, Compra *>(idC, c)));
}

void ControladorCompras::finalizarCompra()
{
	for (auto p : datosProductos)
	{
		p.producto.setStock(p.producto.getStock() - p.cantidad);
	};
	datosProductos.clear();
	nickname = "";
}

std::set<DTDetalleCompra> ControladorCompras::obtenerCompras(){
	set<DTDetalleCompra> resultado;
	for (auto c : compras){
		Compra* co = c.second;
		DTDetalleCompra dc = DTDetalleCompra(co->getId(), co->getMontoFinal(),co->getFechaCompra(),co->getEnvios(),co->getProductos(), cliente->getNickname());
		resultado.insert(dc);
	}
	return resultado;
}
