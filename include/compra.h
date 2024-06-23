#ifndef _Compra_H
#define _Compra_H
#include "./Datatypes/DTDetalleCompra.h"
#include "./Datatypes/DTProducto.h"
#include "./Datatypes/DTFecha.h"
#include "./Datatypes/ParProdCant.h"
#include "./promocion.h"

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
    //Promocion* promocionCumplida;
    string promocionCumplida;

public:
    DTFecha getFechaCompra();
    double getMontoFinal();
    int getId();
	Cliente* getCliente();
    set<ParProdCant> getProductos();
    map<int, bool> getEnvios();
    Compra(DTFecha fechaCompra, double montoFinal, int id, set<ParProdCant> productos, map<int, bool> envios, Cliente *cliente, string promo);
    Compra(DTFecha fechaCompra, double montoFinal, int id, Cliente *cliente);
    Compra();
    ~Compra();
    void enviarEnCompra(int cp);
    void agregarProductosYEnvios(int codigo, int cantidad, bool enviado);
    void agregarPromocion(string nombrePromo);
};

#include "cliente.h"
#endif //_Compra_H


