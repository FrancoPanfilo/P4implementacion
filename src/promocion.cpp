#include "../include/promocion.h"
#include "../include/Datatypes/DTProducto.h"
#include <set>
Vendedor Promocion::getVendedor()
{
    return vendedor;
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
// std::map<Producto, Minimo> Promocion::getMinimos()
// {
//     return productos;
// }  
/* Promocion Promocion
::obtenerSiAplica(std::set<ParProdCant>){
    Promocion p;
    return p;
} */

set<DTProducto> Promocion::getProductos() {
	set<DTProducto> dtproductos;
	for (auto par : productos) {
		Producto p = par.first;
		DTProducto dtp = DTProducto(p.getCodigo(), p.getStock(), p.getPrecio(), p.getNombre(), p.getDescripcion(), p.getTipo());
		dtproductos.insert(dtp);
	}
	return dtproductos;
}
