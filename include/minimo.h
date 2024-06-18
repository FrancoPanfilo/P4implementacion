#ifndef MINIMO_H
#define MINIMO_H

#include "./Datatypes/ParProdCant.h"
#include <set>
class Minimo
{
private:
    int cantidad;
    Producto producto;

public:
    Minimo(Producto, int);
    int getCantidad();
    Producto getProducto();
    bool verificarMinimo(std::set<ParProdCant> prod);
};

#endif // !MINIMO_H