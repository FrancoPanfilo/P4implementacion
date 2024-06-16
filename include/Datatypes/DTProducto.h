#ifndef _DTPRODUCTO_H
#define _DTPRODUCTO_H

#include <string>
using namespace std;

class DTProducto
{
public:
    int codigo;
    int stock;
    int precio;
    string nombre;
    string descripcion;
    string tipo;  
    DTProducto(int codigo, int stock, int precio, string nombre, string descripcion, string tipo);
    DTProducto() = default;
    ~DTProducto();
    bool operator<(const DTProducto& otro) const;
};

#endif // _DTPRODUCTO_H