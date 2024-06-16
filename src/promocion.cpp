#include "../include/promocion.h"
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
set<DTProducto> Promocion::getProductos()
{
    set<DTProducto> p;
    return p;
}
/* Promocion Promocion::obtenerSiAplica(std::set<ParProdCant>){
    Promocion p;
    return p;
} */