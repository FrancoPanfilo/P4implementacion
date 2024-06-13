#ifndef _DTPRODUCTO_H
#define _DTPRODUCTO_H

#include <string>
using namespace std;

class DTProducto
{
private:
    int codigo;
    int stock;
    int precio;
    string nombre;
    string descripcion;
    string tipo;  
public:
    DTProducto(int codigo, int stock, int precio, string nombre, string descripcion, string tipo);
    ~DTProducto();
    int getCodigo();
    int getStock();
    int getPrecio();
    string getNombre();
    string getDescripcion();
    string getTipo();      
};

#endif // _DTPRODUCTO_H