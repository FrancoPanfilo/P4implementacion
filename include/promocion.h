#ifndef _PROMOCION_H
#define _PROMOCION_H
#include <string>
#include "./Datatypes/ParProdCant.h"
#include "./Datatypes/DTFecha.h"
#include <set>
using String = std::string;
class Promocion
{
private:
    int descuento;
    DTFecha vencimiento;
    String descripcion;
    String nombre;

public:
    int getDescuento();
    DTFecha getVencimiento();
    String getDescripcion();
    String getNombre();
    Promocion obtenerSiAplica(std::set<ParProdCant>);
};
#endif //_PROMOCION_H