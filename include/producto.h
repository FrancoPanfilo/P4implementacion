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
    int precio;
    string nombre;
    string descripcion;
    string tipo;

public:
    Producto(DTProducto dtp);
    Producto(int cod, int stk, int prc, string nom, string desc, string tp);
    int getCodigo();
    int getStock();
    int getPrecio();
    string getNombre();
    string getDescripcion();
    string getTipo();
    void agregarAPromo(string, int);
};

#endif // _PRODUCTO_H
