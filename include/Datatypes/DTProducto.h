#ifndef _DTPRODUCTO_H
#define _DTPRODUCTO_H

#include <string>
using namespace std;

class DTProducto
{
public:
    int codigo;
    int stock;
    double precio;
    string nombre;
    string descripcion;
    string tipo;
    DTProducto(int codigo, int stock, double precio, string nombre, string descripcion, string tipo);
    DTProducto() = default;
    ~DTProducto();
    bool operator<(const DTProducto &other) const;
};

#endif // _DTPRODUCTO_H