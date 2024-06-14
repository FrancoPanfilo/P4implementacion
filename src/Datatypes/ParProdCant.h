#ifndef _PARPRODCANT_H
#define _PARPRODCANT_H

#include "../producto.h" 
class ParProdCant
{
public:
    Producto producto;
    int cantidad;    
    ParProdCant(Producto producto, int cantidad);
    ParProdCant();
    ~ParProdCant();
};

#endif // _PARPRODCANT_H