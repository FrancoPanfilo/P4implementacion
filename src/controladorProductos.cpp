// // File: controladorProductos.cpp

#include "../include/controladorProductos.h"
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
    // for (auto producto : productos)
    // {
    //     dtProductos.insert(DTProducto(
    //         producto.second.getCodigo(),
    //         producto.second.getStock(),
    //         producto.second.getPrecio(),
    //         producto.second.getNombre(),
    //         producto.second.getDescripcion(),
    //         producto.second.getTipo()
    //     ));
    // }
    return dtProductos;
}

int ControladorProductos::seleccionarProducto(int codigo, int cantidad)
{
    for (auto producto : productos)
    {
        if (producto.second.getCodigo() == codigo)
        {
            if (producto.second.getStock() >= cantidad)
            {
                // TODO
                return 0; // Operación exitosa
            }
            else
            {
                return -2; // No hay suficiente stock
            }
        }
    }
    return -1; // Producto no encontrado
}

void ControladorProductos::agregarAPromo(String nombrePromo, int codigo, int cantidad)
{
    for (auto producto : productos)
    {
        if (producto.second.getCodigo() == codigo)
        {
            if (producto.second.getStock() >= cantidad)
            {
                producto.second.agregarAPromo(nombrePromo, cantidad);
                return;
            }
        }
    }
}

Producto ControladorProductos::obtenerProducto(int codigo)
{
    for (auto producto : productos)
    {
        if (producto.second.getCodigo() == codigo)
        {
            return producto.second;
        }
    }
	// TODO: verificar si esto es razonable
	Producto prod;
	return prod;
}


std::set<DTProductoId> ControladorProductos::listarProductosConId(){
	// TODO
	std::set<DTProductoId> productos;
	return productos;
}
void ControladorProductos::seleccionarProductoPorCodigo(int){

}

DTProducto ControladorProductos::mostrarProducto(){
	DTProducto prod;
	return prod;
}

std::set<string> ControladorProductos::listarVendedores(){
	// TODO
	std::set<std::string> vendedores;
	return vendedores;
}

std::set<DTProducto> ControladorProductos::seleccionarVendedor(string nickname){
	// TODO
	std::set<DTProducto> productos;
	return productos;
}
std::set<EnviosPendientes> ControladorProductos::seleccionarProductoAEnviar(int){
	// TODO
	std::set<EnviosPendientes> envios;
	return envios;
}

void ControladorProductos::seleccionarVenta(EnviosPendientes env){
	// TODO
}
