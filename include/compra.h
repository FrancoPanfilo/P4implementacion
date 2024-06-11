#ifndef _Compra_H
#define _Compra_H
#include "./Datatypes/DTFecha.h"
class Compra
{
private:
    DTFecha fechaCompra;
    int montoFinal;

public:
    DTFecha getFechaCompra();
    int getMontoFinal();
};
#endif //_Compra_H
