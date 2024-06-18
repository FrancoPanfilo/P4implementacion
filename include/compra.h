#ifndef _Compra_H
#define _Compra_H
#include "./Datatypes/DTProducto.h"
#include "./Datatypes/DTFecha.h"
#include "./Datatypes/ParProdCant.h"

#include <map> 
#include <set> 

class Compra
{
private:
    DTFecha fechaCompra;
    int montoFinal;
    int id;
    set<ParProdCant> productos;
    map<int, bool> envios;

public:
    DTFecha getFechaCompra();
    int getMontoFinal();
    int getId();
    set<ParProdCant> getProductos();
    map<int, bool> getEnvios();
    Compra(DTFecha fechaCompra, int montoFinal, int id, set<ParProdCant> productos, map<int, bool> envios);
    Compra();
    ~Compra();
};
#endif //_Compra_H
