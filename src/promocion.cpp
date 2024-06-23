#include "../include/promocion.h"
#include "../include/Datatypes/DTProducto.h"
#include <set>
string Promocion::getVendedor()
{
    return nickVendedor;
}
int Promocion::getDescuento()
{
    return descuento;
}
DTFecha Promocion::getVencimiento()
{
    return vencimiento;
}
String Promocion::getDescripcion()
{
    return descripcion;
}
String Promocion::getNombre()
{
    return nombre;
}

Promocion::Promocion(DTPromocion p, string v)
    : nickVendedor(v), descuento(p.descuento), vencimiento(p.fechaVencimiento),
      nombre(p.nombre), descripcion(p.descripcion) {}

// std::map<Producto, Minimo> Promocion::getMinimos()
// {
//     return productos;
// }
Promocion *Promocion::obtenerSiAplica(std::set<ParProdCant> carrito)
{
    std::map<int, ParProdCant> mapa;
    for (auto producto : carrito)
    {
        mapa.insert(std::pair<int, ParProdCant>(producto.codigo, producto));
    }
    Promocion *p = NULL;
    bool cp = true;
    for (auto producto : productos)
    {
		int codigo = producto.first;
		Minimo minimo = producto.second;
		// Si el producto no esta en el carrito o compramos menos que la cantidad minima, entonces se descarta la promo
        // if (ppp2.count(producto.first) == 0 || ppp2.at(producto.first).getCantidad() < producto.second.getCantidad())
        if (mapa.count(codigo) == 0 || mapa.at(codigo).codigo < minimo.getCantidad())
        {
            cp = false;
        }
        if (!cp)
        {
            break;
        }
    }
	// Si la iteracion termina naturalmente entonces la promo aplica
    if (cp)
    {
        p = this;
    }
    return p;
}

set<DTProducto> Promocion::getProductos()
{
    set<DTProducto> dtproductos;
    for (auto par : productos)
    {
        Producto *p = par.second.getProducto();
        DTProducto dtp = DTProducto(p->getCodigo(), p->getStock(), p->getPrecio(), p->getNombre(), p->getDescripcion(), p->getTipo());
        dtproductos.insert(dtp);
    }
    return dtproductos;
}

void Promocion::agregarAPromo(Producto *p, int cantidad)
{
    Minimo m(p, cantidad);
    this->productos.insert(std::pair<int, Minimo>(p->getCodigo(), m));
}

set<ParProdCant> Promocion::obtenerProductosConMinimo() {
	set<ParProdCant> resultado;
	for (auto par : productos) {
		int codigo = par.second.getProducto()->getCodigo();
		int cantidad = par.second.getCantidad();
		ParProdCant ppc = ParProdCant(codigo, cantidad);
		resultado.insert(ppc);
	}
	return resultado;
}
