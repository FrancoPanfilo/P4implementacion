// // File: controladorProductos.cpp

#include "../include/controladorProductos.h"
#include "../include/Interface/IUsuario.h"
#include "../include/fabrica.h"
#include <string>

ControladorProductos *ControladorProductos::instance = NULL;

ControladorProductos::ControladorProductos() {}
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
        dtProductos.insert(DTProducto(producto.second.getCodigo(), producto.second.getStock(), producto.second.getPrecio(), producto.second.getNombre(), producto.second.getDescripcion(), producto.second.getTipo()));
    }
    return dtProductos;
}

ParProdCant ControladorProductos::seleccionarProducto(int codigo, int cantidad)
{
    Producto p = productos.at(codigo);
    ParProdCant ppc = ParProdCant(p, cantidad);
    return ppc;
}

Producto ControladorProductos::obtenerProducto(int codigo)
{
    return productos.at(codigo);
}

std::set<DTProducto> ControladorProductos::listarProductosConId()
{
    std::set<DTProducto> dtProductos;
    for (auto producto : productos)
    {
        dtProductos.insert(DTProducto(producto.second.getCodigo(), 0, 0, producto.second.getNombre(), "", ""));
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
    Fabrica *f = Fabrica::getFabrica();
    IUsuario *contUsuarios = f->getIUsuarios();
    Producto producto(p);
    productos.insert(std::pair<int, Producto>(producto.getCodigo(), producto));
    Vendedor *v = contUsuarios->obtenerVendedor(nickname);
    v->agregarProducto(producto);
}

std::set<DTProducto> ControladorProductos::seleccionarVendedor(string nickname)
{
    // TODO
    std::set<DTProducto> productos;
    return productos;
}
std::set<EnviosPendientes> ControladorProductos::seleccionarProductoAEnviar(int)
{
    // TODO
    std::set<EnviosPendientes> envios;
    return envios;
}

void ControladorProductos::seleccionarVenta(EnviosPendientes env)
{
    // TODO
}
