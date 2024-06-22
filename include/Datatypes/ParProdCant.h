#ifndef _PARPRODCANT_H
#define _PARPRODCANT_H

#include "../producto.h"
class ParProdCant
{
public:
    // Producto producto;
	int codigo;
    int cantidad;
    ParProdCant(int codigo, int cantidad);
    ParProdCant() = default;
    ~ParProdCant();
    bool operator<(const ParProdCant &other) const;
};

#endif // _PARPRODCANT_H
