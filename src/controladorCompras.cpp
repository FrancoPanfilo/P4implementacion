#include "../include/controladorCompras.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorProductos.h"
#include "../include/controladorPromociones.h"

#include <ctime>
#include <stdexcept>

using namespace std;

ControladorCompras *ControladorCompras::instance = NULL;

ControladorCompras::ControladorCompras()
    : idC(0), cliente(NULL) {}

// ControladorCompras::ControladorCompras()
// {
// 	int idC = 0;
// }

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
	Producto *prod = cpro->obtenerProducto(id);
	string err = "Stock insuficiente: (" + to_string(prod->getStock()) + ")";
	if (prod->getStock() < cantidad){
		
		throw std::runtime_error(err);
	}
	ParProdCant par = ParProdCant(prod->getCodigo(), cantidad);
	// control producto no repetido
	for (auto p : datosProductos)
	{
		if (p.codigo == par.codigo)
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
	ControladorProductos *cprod = ControladorProductos::getInstance();
	if (promo != NULL)
	{	
		cout << "Aplicando promocion " << promo->getNombre() << endl;
		double desc = promo->getDescuento();
		promocionUsada = promo->getNombre();
		set<DTProducto> pd = promo->getProductos();
		for (auto p : datosProductos)
		{	
			Producto *pr = cprod->obtenerProducto(p.codigo);
			if (pd.count(DTProducto(p.codigo, pr->getStock(), pr->getPrecio(), pr->getNombre(), pr->getDescripcion(), pr->getTipo())) == 1)
			{
				total += (p.cantidad * pr->getPrecio()) - (p.cantidad * pr->getPrecio() * desc / 100); //(p.cantidad * pr.getPrecio()) - (p.cantidad * pr.getPrecio()) / desc;
			}
			else
			{
				total += p.cantidad * pr->getPrecio();
			}
		}
	}
	else
	{	
		cout << "NO HAY PROMO PARA APLICAR" << endl;
		promocionUsada = "";
		for (auto p : datosProductos)
		{
			Producto *pr = cprod->obtenerProducto(p.codigo);
			total += p.cantidad * pr->getPrecio();
		}
	};
	idC++;
	compraActual = DTDetalleCompra(idC, total, fechaActual, envios, datosProductos, nickname);
	return compraActual;
}

void ControladorCompras::registrarCompra()
{
	Compra *c = new Compra(fechaActual, compraActual.montoFinal, compraActual.id, datosProductos, envios, cliente, promocionUsada);
	//Compra *c = new Compra(compra);
	//if promo != " " entonces agregarpromo a c
	c->getCliente()->agregarCompra(c);
	std::pair<int, Compra *> p;
    p.first = c->getId();
    p.second = c;
	compras.insert(p);
}

void ControladorCompras::finalizarCompra()
{
	ControladorProductos *cprod = ControladorProductos::getInstance();
	for (auto p : datosProductos)
	{
		Producto *pr = cprod->obtenerProducto(p.codigo);
		pr->setStock(pr->getStock() - p.cantidad);
	};
	datosProductos.clear();
	envios.clear();
	nickname = "";
}

std::set<DTDetalleCompra> ControladorCompras::obtenerCompras(){
	set<DTDetalleCompra> resultado;
	for (auto c : compras){
		Compra* co = c.second;
		DTDetalleCompra dc = DTDetalleCompra(co->getId(), co->getMontoFinal(),co->getFechaCompra(),co->getEnvios(),co->getProductos(), co->getCliente()->getNickname());
		resultado.insert(dc);
	}
	return resultado;
}

void ControladorCompras::eliminarTodasLasCompras()
{
    for (auto it = compras.begin(); it != compras.end(); ++it) {
        delete it->second;
    }
    compras.clear();
}

void ControladorCompras::cargarCompra(Compra c){
	idC++;
	Compra * compra = new Compra(c);
	ControladorUsuarios *cu = ControladorUsuarios::getInstance();
	compra->getCliente()->agregarCompra(compra);
	compras.insert(std::pair<int, Compra *> (compra->getId() ,compra));
}