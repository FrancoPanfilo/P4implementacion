#ifndef _DTPROMOCION_H
#define _DTPROMOCION_H

#include <string>
#include "./DTFecha.h"
using namespace std;

class DTPromocion 
{
public:
    string nombre;
    string descripcion;
    int descuento;
    DTFecha fechaVencimiento;
    DTPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVencimiento);
    DTPromocion() = default;
    ~DTPromocion();  
};

#endif // _DTPROMOCION_H