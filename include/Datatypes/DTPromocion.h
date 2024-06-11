#include <string>
#include "./Datatypes/DTFecha.h"
using namespace std;

class DTPromocion 
{
private:
    string nombre;
    string descripcion;
    int descuento;
    DTFecha fechaVencimiento;
public:
    DTPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVencimiento);
    ~DTPromocion();
    string getNombre();
    string getDescripcion();
    int getDescuento();
    DTFecha getFechaVencimiento();    
};