#include <string>
#include "./Datatypes/DTFecha.h"

class DTPromocion 
{
private:
    String nombre;
    String descripcion;
    int descuento;
    DTFecha fechaVencimiento;
public:
    DTPromocion(String nombre, String descripcion, int descuento, DTFecha fechaVencimiento);
    ~DTPromocion();
    String getNombre();
    String getDescripcion();
    int getDescuento();
    DTFecha getFechaVencimiento();    
};