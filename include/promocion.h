#ifndef _PROMOCION_H
#define _PROMOCION_H
#include <string>
#include "./Datatypes/ParProdCant.h"
#include "./Datatypes/DTFecha.h"
#include "./Datatypes/DTPromocion.h"
#include "./minimo.h"
#include <set>
#include <map>
using String = std::string;
using namespace std;

class Promocion
{
private:
    string nickVendedor;
    int descuento;
    DTFecha vencimiento;
    String descripcion;
    String nombre;
    map<int, Minimo> productos;

public:
    string getVendedor();
    int getDescuento();
    DTFecha getVencimiento();
    String getDescripcion();
    String getNombre();
    Promocion(DTPromocion, string);
    map<Producto, Minimo> getMinimos();
    Promocion *obtenerSiAplica(std::set<ParProdCant>);
    set<DTProducto> getProductos();
    set<ParProdCant> obtenerProductosConMinimo();
    void agregarAPromo(Producto *prod, int cantidad);
    // Promocion obtenerSiAplica(std::set<ParProdCant>);
};
#endif //_PROMOCION_H
