#ifndef _Compra_H
#define _Compra_H
#include "./Datatypes/DTProducto.h"
#include "./Datatypes/DTFecha.h"

#include <map> 

class Compra
{
private:
    DTFecha fechaCompra;
    int montoFinal;
    int id;
    map<DTProducto, int> productos;

public:
    DTFecha getFechaCompra();
    int getMontoFinal();
    map<DTProducto, int> getProductos();
    Compra(DTFecha fechaCompra, int montoFinal, int id, map<DTProducto, int> productos);
    Compra();
    ~Compra();
};
#endif //_Compra_H
