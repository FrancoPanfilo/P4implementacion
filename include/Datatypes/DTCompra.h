#ifndef _DTCOMPRA_H
#define _DTCOMPRA_H

#include <set>
#include <iostream>
#include "./DTFecha.h"
using namespace std;

class DTCompra
{
public:
    DTFecha fecha;
    double montoFinal;
    std::set<int> datosProductos;
    DTCompra(DTFecha fecha, double montoFinal, set<int> datosProductos);
    DTCompra() = default;
    ~DTCompra();
};

#endif //_DTCOMPRA_H