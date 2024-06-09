#include <string>
using namespace std;

class Promocion{
public:
    Promocion() = default;
    Promocion(int, DTFecha, String, String);
    ~Promocion() = default;
    Promocion obtenerSiAplica(Set(ParProdCant));
private:
    int descuento;
    DTFecha vencimiento;
    String descripcion;
    String nombre;    
    //producto o minimo?
};