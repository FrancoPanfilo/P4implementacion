#ifndef MINIMO_H
#define MINIMO_H

#include "./ParProdCant.h"

class Minimo{
    public:
    int cantidad;
    Producto producto;
    bool verificarMinimo(ParProdCant prod);

};


#endif // !MINIMO_H