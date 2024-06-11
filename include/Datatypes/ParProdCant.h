#include "Producto.h" //no supe como incluir producto acá

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