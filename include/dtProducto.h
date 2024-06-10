// File: dtProducto.h

#ifndef _DTPRODUCTO_H
#define _DTPRODUCTO_H

#include <string>

using namespace std;

class DTProducto {
private:
    int codigo;
    int stock;
    int precio;
    string nombre;
    string descripcion;
    string tipo;
public:
    // Constructor
    DTProducto(int codigo, int stock, int precio, string nombre, string descripcion, string tipo);

    // Destructor
    virtual ~DTProducto();

    // Getters
    int getCodigo();
    int getStock();
    int getPrecio();
    string getNombre();
    string getDescripcion();
    string getTipo();

    // Setters
    void setCodigo(int codigo);
    void setStock(int stock);
    void setPrecio(int precio);
    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setTipo(string tipo);
};

#endif  // _DTPRODUCTO_H