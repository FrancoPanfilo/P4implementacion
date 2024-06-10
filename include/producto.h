#ifndef _PRODUCTO_H
#define _PRODUCTO_H

#include <string>
using String = std::string;
class Producto
{
private:
    int codigo;
    int stock;
    int precio;
    String nombre;
    String descripcion;
    String tipo;

public:
    int getCodigo();
    int getStock();
    int getPrecio();
    String getNombre();
    String getDescripcion();
    String getTipo();
    void agregarAPromo(String, int);
};

#endif // _PRODUCTO_H
