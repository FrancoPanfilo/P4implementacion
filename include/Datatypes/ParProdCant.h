#ifndef _PARPRODCANT_H
#define _PARPRODCANT_H

#include "../producto.h" 
class ParProdCant
{
private:
    Producto producto;
    int cantidad;    
public:
    ParProdCant(Producto producto, int cantidad);
    ~ParProdCant();
    Producto getProducto();
    int getCantidad();
};

#endif // _PARPRODCANT_H