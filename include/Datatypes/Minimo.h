#ifndef MINIMO_H
#define MINIMO_H

#include "./ParProdCant.h"
#include <set>
class Minimo{
    public:
    int cantidad;
    Producto producto;
    bool verificarMinimo(std::set<ParProdCant> prod);

};


#endif // !MINIMO_H