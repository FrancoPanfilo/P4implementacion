#ifndef MINIMO_H
#define MINIMO_H

#include "./Datatypes/ParProdCant.h"
#include <set>
class Minimo
{
public:
    int cantidad;
    Producto producto;
    bool verificarMinimo(std::set<ParProdCant> prod);
};

#endif // !MINIMO_H