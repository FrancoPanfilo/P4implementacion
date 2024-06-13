#ifndef _DTPROMOCION_H
#define _DTPROMOCION_H

#include <string>
#include "./Datatypes/DTFecha.h"
using namespace std;

class DTPromocion 
{
private:
    string nombre;
    string descripcion;
    int descuento;
    DTFecha fechaVencimiento;
public:
    DTPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVencimiento);
    ~DTPromocion();
    string getNombre();
    string getDescripcion();
    int getDescuento();
    DTFecha getFechaVencimiento();    
};

#endif // _DTPROMOCION_H