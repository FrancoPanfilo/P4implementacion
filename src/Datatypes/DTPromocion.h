#ifndef _DTPROMOCION_H
#define _DTPROMOCION_H

#include <string>
#include "./Datatypes/DTFecha.h"
using namespace std;

class DTPromocion 
{
public:
    string nombre;
    string descripcion;
    int descuento;
    DTFecha fechaVencimiento;
    DTPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVencimiento);
    DTPromocion();
    ~DTPromocion();  
};

#endif // _DTPROMOCION_H