#ifndef _PROMOCION_H
#define _PROMOCION_H
#include <string>
#include "./Datatypes/ParProdCant.h"
#include "./Datatypes/DTFecha.h"
#include "./Datatypes/Minimo.h"
#include <set>
#include <map>
using String = std::string;
class Promocion
{
private:
    int descuento;
    DTFecha vencimiento;
    String descripcion;
    String nombre;
    std::map<Producto, Minimo> minimos;

public:
    int getDescuento();
    DTFecha getVencimiento();
    String getDescripcion();
    String getNombre();
    std::map<Producto, Minimo> getMinimos();
    Promocion obtenerSiAplica(std::set<ParProdCant>);
};
#endif //_PROMOCION_H
