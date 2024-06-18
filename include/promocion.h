#ifndef _PROMOCION_H
#define _PROMOCION_H
#include <string>
#include "./Datatypes/ParProdCant.h"
#include "./Datatypes/DTFecha.h"
#include "./minimo.h"
#include "./vendedor.h"
#include <set>
#include <map>
using String = std::string;
using namespace std;

class Promocion
{
private:
    Vendedor vendedor;
    int descuento;
    DTFecha vencimiento;
    String descripcion;
    String nombre;
    map<Producto, Minimo> productos;

public:
    Vendedor getVendedor();
    int getDescuento();
    DTFecha getVencimiento();
    String getDescripcion();
    String getNombre();

    //std::map<Producto, Minimo> getMinimos();
    Promocion obtenerSiAplica(std::set<ParProdCant>);
    set<DTProducto> getProductos();
    // Promocion obtenerSiAplica(std::set<ParProdCant>);
};
#endif //_PROMOCION_H
