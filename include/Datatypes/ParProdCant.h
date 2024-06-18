#ifndef _PARPRODCANT_H
#define _PARPRODCANT_H

#include "../producto.h" 
class ParProdCant
{
public:
    Producto producto;
    int cantidad;    
    ParProdCant(Producto producto, int cantidad);
    ParProdCant() = default;
    ~ParProdCant();
    bool operator<(const ParProdCant& other) const;
};

#endif // _PARPRODCANT_H