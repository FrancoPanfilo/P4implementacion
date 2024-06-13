#ifndef _DTCOMPRA_H
#define _DTCOMPRA_H

#include <set>
#include "./Datatypes/DTFecha.h"
using namespace std;

class DTCompra
{
private:
    DTFecha fecha;
    int montoFinal;
    std::set<int> datosProductos;    
public:
    DTCompra(DTFecha fecha, int montoFinal, set<int> datosProductos);
    ~DTCompra();
    DTFecha getFecha();
    int getMontoFinal();
    set<int> getDatosProductos();   
};

#endif _DTCOMPRA_H