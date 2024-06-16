#include "../include/Datatypes/DTAltaCliente.h"
#include "../include/Datatypes/DTAltaVendedor.h"
#include "../include/Datatypes/DTComentario.h"
#include "../include/Datatypes/DTCompra.h"
#include "../include/Datatypes/DTFecha.h"
#include "../include/Datatypes/DTNotificacion.h"
#include "../include/Datatypes/DTPromocion.h"
#include "../include/Datatypes/DTProducto.h"
#include "../include/Datatypes/DTProductoId.h"
#include "../include/Datatypes/ParProdCant.h"

DTAltaCliente::DTAltaCliente(string nickname, DTFecha fechaNac, string contrasenia, string ciudad, string direccion)
    : nickname(nickname), fechaNac(fechaNac), contrasenia(contrasenia), ciudad(ciudad), direccion(direccion) {}

DTAltaCliente::~DTAltaCliente(){}
DTAltaCliente::DTAltaCliente(){}

DTAltaVendedor::DTAltaVendedor(string nickname, DTFecha fechaNac, string contrasenia, string RUT)
    : nickname(nickname), fechaNac(fechaNac), contrasenia(contrasenia), RUT(RUT) {}

DTAltaVendedor::~DTAltaVendedor(){}    

DTComentario::DTComentario(int id, string contenido, DTFecha fecha)
    : id(id), contenido(contenido), fecha(fecha) {}

DTComentario::~DTComentario(){}

DTCompra::DTCompra(DTFecha fecha, int montoFinal, set<int> datosProductos)
    : fecha(fecha), montoFinal(montoFinal), datosProductos(datosProductos) {}

DTCompra::~DTCompra(){}    

DTFecha::DTFecha(int dia, int mes, int anio)
    : dia(dia), mes(mes), anio(anio) {}

DTFecha::~DTFecha(){}

DTNotificacion::DTNotificacion(string nombreVendedor, set<int> productos, string nombrePromo)
    : nombreVendedor(nombreVendedor), productos(productos), nombrePromo(nombrePromo) {}

DTNotificacion::~DTNotificacion(){}    

DTProducto::DTProducto(int codigo, int stock, int precio, string nombre, string descripcion, string tipo)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), tipo(tipo) {}

DTProducto::~DTProducto(){}

/*DTProductoId::DTProductoId(int codigo, string nombre)
    : codigo(codigo), nombre(nombre) {}
*/
bool DTProducto::operator<(const DTProducto& otro) const{
    return codigo < otro.codigo;
}

DTPromocion::DTPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVencimiento)
    : nombre(nombre), descripcion(descripcion), descuento(descuento), fechaVencimiento(fechaVencimiento) {}

DTPromocion::~DTPromocion(){}

bool DTPromocion::operator<(const DTPromocion& otro) const{
    return  (nombre.compare(otro.nombre) < 0);
}    

ParProdCant::ParProdCant(Producto producto, int cantidad)
    : producto(producto), cantidad(cantidad) {}

ParProdCant::~ParProdCant(){}  


