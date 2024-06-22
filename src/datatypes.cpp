#include "../include/Datatypes/DTAltaCliente.h"
#include "../include/Datatypes/DTAltaVendedor.h"
#include "../include/Datatypes/DTCliente.h"
#include "../include/Datatypes/DTComentario.h"
#include "../include/Datatypes/DTCompra.h"
#include "../include/Datatypes/DTDetalleCompra.h"
#include "../include/Datatypes/DTFecha.h"
#include "../include/Datatypes/DTNotificacion.h"
#include "../include/Datatypes/DTPromocion.h"
#include "../include/Datatypes/DTProducto.h"
#include "../include/Datatypes/DTProductoId.h"
#include "../include/Datatypes/ParProdCant.h"
#include "../include/Datatypes/DTProductosYVendedor.h"
#include "../include/Datatypes/DTVendedor.h"
#include "../include/Datatypes/EnviosPendientes.h"

DTAltaCliente::DTAltaCliente(string nickname, DTFecha fechaNac, string contrasenia, string ciudad, string direccion)
    : nickname(nickname), fechaNac(fechaNac), contrasenia(contrasenia), ciudad(ciudad), direccion(direccion) {}

DTAltaCliente::~DTAltaCliente(){}
DTAltaCliente::DTAltaCliente(){}

DTAltaVendedor::DTAltaVendedor(string nickname, DTFecha fechaNac, string contrasenia, string RUT)
    : nickname(nickname), fechaNac(fechaNac), contrasenia(contrasenia), RUT(RUT) {}

DTAltaVendedor::~DTAltaVendedor(){}    


DTCliente::DTCliente(string nickname, DTFecha fechaNach, string ciudad, string direccion)
    : nickname(nickname), fechaNac(fechaNac), ciudad(ciudad), direccion(direccion){}

DTCliente::~DTCliente(){}

DTComentario::DTComentario(int id, string contenido, DTFecha fecha)
    : id(id), contenido(contenido), fecha(fecha) {}

DTComentario::~DTComentario(){}

DTCompra::DTCompra(DTFecha fecha, double montoFinal, set<int> datosProductos)
    : fecha(fecha), montoFinal(montoFinal), datosProductos(datosProductos) {}

DTCompra::~DTCompra(){}    

DTDetalleCompra::DTDetalleCompra(int id, double montoFinal, DTFecha fechaCompra,map <int, bool> productosEnvio, set<ParProdCant> productos, string cliente)
    :id(id), montoFinal(montoFinal), fechaCompra(fechaCompra), productos(productos), cliente(cliente) {
        this->productosEnvio = productosEnvio;
    }

DTDetalleCompra::DTDetalleCompra() {}

DTDetalleCompra::~DTDetalleCompra() {}

bool DTDetalleCompra::operator<(const DTDetalleCompra &otra) const
{
    return id < otra.id;
}

DTFecha::DTFecha(int dia, int mes, int anio)
    : dia(dia), mes(mes), anio(anio) {}

DTFecha::~DTFecha(){}

bool DTFecha::operator>(const DTFecha &otra) const
{
    if (anio > otra.anio)
    {
        return true;
    }
    else if (anio == otra.anio)
    {
        if (mes > otra.mes)
        {
            return true;
        }
        else if (mes == otra.mes)
        {
            return dia > otra.dia;
        }
    }
    return false;
}

DTNotificacion::DTNotificacion(string nombreVendedor, set<int> productos, string nombrePromo)
    : nombreVendedor(nombreVendedor), productos(productos), nombrePromo(nombrePromo) {}

DTNotificacion::~DTNotificacion(){}    
bool DTNotificacion::operator<(const DTNotificacion &otra) const {
	return (this->nombrePromo.compare(otra.nombrePromo) == -1);
}

DTProducto::DTProducto(int codigo, int stock, double precio, string nombre, string descripcion, string tipo)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), tipo(tipo) {}

bool DTProducto::operator<(const DTProducto &other) const
{
    return codigo < other.codigo;
}
DTProducto::~DTProducto() {}

DTPromocion::DTPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVencimiento)
    : nombre(nombre), descripcion(descripcion), descuento(descuento), fechaVencimiento(fechaVencimiento) {}

DTPromocion::~DTPromocion(){}

bool DTPromocion::operator<(const DTPromocion &other) const
{
    return (nombre.compare(other.nombre) < 0);
}

EnviosPendientes::EnviosPendientes(int id, string nickname, DTFecha fecha)
    : id(id), nickname(nickname), fecha(fecha){}

EnviosPendientes::~EnviosPendientes(){}

bool EnviosPendientes::operator<(const EnviosPendientes& otro) const {
	return id < otro.id;
}

ParProdCant::ParProdCant(int codigo, int cantidad)
    : codigo(codigo), cantidad(cantidad) {}


ParProdCant::~ParProdCant() {}
bool ParProdCant::operator<(const ParProdCant &other) const
{
    return codigo < other.codigo;
}

DTProductosYVendedor::DTProductosYVendedor(std::set<DTProducto> productos, Vendedor vendedor)
    : productos(productos), vendedor(vendedor) {}

bool DTComentario::operator<(const DTComentario &other) const

{
    return id < other.id;
}

DTVendedor::DTVendedor(string nickname, DTFecha fechaNac, string RUT)
    : nickname(nickname), fechaNac(fechaNac), RUT(RUT){}

DTVendedor::~DTVendedor(){}
