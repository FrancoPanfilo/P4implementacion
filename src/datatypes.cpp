#include "../include/Datatypes/DTAltaCliente.h"
#include "../include/Datatypes/DTAltaVendedor.h"
#include "../include/Datatypes/DTComentario.h"
#include "../include/Datatypes/DTCompra.h"
#include "../include/Datatypes/DTFecha.h"
#include "../include/Datatypes/DTNotificacion.h"
#include "../include/Datatypes/DTPromocion.h"
#include "../include/Datatypes/DTProducto.h"
#include "../include/Datatypes/ParProdCant.h"

DTAltaCliente::DTAltaCliente(string nickname, DTFecha fechaNac, string contrasenia, string ciudad, string direccion)
    : nickname(nickname), fechaNac(fechaNac), contrasenia(contrasenia), ciudad(ciudad), direccion(direccion) {}

DTAltaVendedor::DTAltaVendedor(string nickname, DTFecha fechaNac, string contrasenia, int RUT)
    : nickname(nickname), fechaNac(fechaNac), contrasenia(contrasenia), RUT(RUT) {}

DTComentario::DTComentario(int id, string contenido, DTFecha fecha)
    : id(id), contenido(contenido), fecha(fecha) {}

DTCompra::DTCompra(DTFecha fecha, int montoFinal, set<int> datosProductos)
    : fecha(fecha), montoFinal(montoFinal), datosProductos(datosProductos) {}

DTFecha::DTFecha(int dia, int mes, int anio)
    : dia(dia), mes(mes), anio(anio) {}

DTNotificacion::DTNotificacion(string nombreVendedor, set<int> productos, string nombrePromo)
    : nombreVendedor(nombreVendedor), productos(productos), nombrePromo(nombrePromo) {}

DTProducto::DTProducto(int codigo, int stock, int precio, string nombre, string descripcion, string tipo)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), tipo(tipo) {}

DTPromocion::DTPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVencimiento)
    : nombre(nombre), descripcion(descripcion), descuento(descuento), fechaVencimiento(fechaVencimiento) {}

ParProdCant::ParProdCant(Producto producto, int cantidad)
    : producto(producto), cantidad(cantidad) {}