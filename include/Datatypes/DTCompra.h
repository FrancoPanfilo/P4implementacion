#include <set>
#include "./Datatypes/DTFecha.h"

class DTCompra
{
private:
    DTFecha fecha;
    int montoFinal;
    Set<int> datosProductos;    
public:
    DTCompra(DTFecha fecha, int montoFinal, Set<int> datosProductos);
    ~DTCompra();
    DTFecha getFecha();
    int getMontoFinal();
    Set<int> getDatosProductos();   
};