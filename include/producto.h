#ifndef _PRODUCTO_H
#define _PRODUCTO_H
#include "../include/Datatypes/DTProducto.h"
#include <string>
using string = std::string;
class Producto
{
private:
    int codigo;
    int stock;
    double precio;
    string nombre;
    string descripcion;
    string tipo;

public:
    Producto(DTProducto dtp);
    Producto(int cod, int stk, double prc, string nom, string desc, string tp);
    int getCodigo() const;
    int getStock();
    double getPrecio();
    string getNombre();
    string getDescripcion();
    string getTipo();
    void setStock(int);
};

#endif // _PRODUCTO_H
