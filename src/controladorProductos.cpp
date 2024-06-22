// // File: controladorProductos.cpp

#include "../include/controladorProductos.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorCompras.h"
#include <string>
#include <iostream>
#include <ostream>

ControladorProductos *ControladorProductos::instance = NULL;

ControladorProductos::ControladorProductos() {
	this->nickname = "";
	this->ultimaId = 0;
}
ControladorProductos::~ControladorProductos() {}

ControladorProductos *ControladorProductos::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorProductos();
    }
    return instance;
}

std::set<DTProducto> ControladorProductos::listarProductos()
{
    // TODO: esto no compila
    std::set<DTProducto> dtProductos;
    for (auto producto : productos)
    {
        Producto *p = producto.second;
        dtProductos.insert(DTProducto(p->getCodigo(), p->getStock(), p->getPrecio(), p->getNombre(), p->getDescripcion(), p->getTipo()));
    }
    return dtProductos;
}

ParProdCant ControladorProductos::seleccionarProducto(int codigo, int cantidad)
{
    Producto *p = productos.at(codigo);
    ParProdCant ppc = ParProdCant(*p, cantidad);
    return ppc;
}

Producto ControladorProductos::obtenerProducto(int codigo)
{
    return *productos.at(codigo);
}

std::set<DTProducto> ControladorProductos::listarProductosConId()
{
    std::set<DTProducto> dtProductos;
    for (auto producto : productos)
    {
        Producto *prod = producto.second;
        dtProductos.insert(DTProducto(prod->getCodigo(), 0, 0, prod->getNombre(), "", ""));
    }
    return dtProductos;
}
void ControladorProductos::seleccionarProductoPorCodigo(int)
{
}

DTProducto ControladorProductos::mostrarProducto()
{
    DTProducto prod;
    return prod;
}

void ControladorProductos::altaProducto(string nickname, DTProducto p)
{
    ControladorUsuarios *contUsuarios = ControladorUsuarios::getInstance();
    Producto producto(p);
    Producto *pr = new Producto(producto);
    productos.insert(std::pair<int, Producto *>(producto.getCodigo(), pr));
    Vendedor *v = contUsuarios->obtenerVendedor(nickname);
    v->agregarProducto(producto);
}

std::set<DTProducto> ControladorProductos::seleccionarVendedor(string nickname)
{
    // TODO
    std::set<DTProducto> productos;
    return productos;
}
std::set<EnviosPendientes> ControladorProductos::seleccionarProductoAEnviar(int codigo)
{   
    std::set<EnviosPendientes> envios;
    ControladorCompras *contCompras = ControladorCompras::getInstance();
    set<DTDetalleCompra> cs = contCompras->obtenerCompras();
    for (auto c : cs){
        if(!c.productosEnvio.at(codigo)){
            EnviosPendientes e = EnviosPendientes(c.cliente, c.fechaCompra);
            envios.insert(e);
        }
    }
    return envios;
}

void ControladorProductos::seleccionarVenta(EnviosPendientes env)
{
    
}

void ControladorProductos::elegirProducto(string nick) {
	this->nickname = nick;
}

void ControladorProductos::crearProducto(DTProducto dtprod) {
	this->ultimaId++;
	 
}
