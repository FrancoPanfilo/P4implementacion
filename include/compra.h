#ifndef _Compra_H
#define _Compra_H
#include "./Datatypes/DTProducto.h"
#include "./Datatypes/DTFecha.h"
#include "./Datatypes/ParProdCant.h"

#include <map> 
#include <set> 

class Cliente;

class Compra
{
private:
    DTFecha fechaCompra;
    double montoFinal;
    int id;
    set<ParProdCant> productos;
    map<int, bool> envios;
	Cliente* cliente;

public:
    DTFecha getFechaCompra();
    double getMontoFinal();
    int getId();
	Cliente* getCliente();

    set<ParProdCant> getProductos();
    map<int, bool> getEnvios();
    Compra(DTFecha fechaCompra, double montoFinal, int id, set<ParProdCant> productos, map<int, bool> envios, Cliente *cliente);
    Compra();
    ~Compra();
};

#include "cliente.h"
#endif //_Compra_H


