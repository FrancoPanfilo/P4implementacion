#ifndef _DTCOMPRA_H
#define _DTCOMPRA_H

#include <set>
#include "./Datatypes/DTFecha.h"
using namespace std;

class DTCompra
{
public: 
    DTFecha fecha;
    int montoFinal;
    std::set<int> datosProductos;    
    DTCompra(DTFecha fecha, int montoFinal, set<int> datosProductos);
    ~DTCompra();  
};

#endif _DTCOMPRA_H