#include <string>
#include <set> 

class DTNotificacion
{
private:
    string nombreVendedor;
    set<int> productos;
    string nombrePromo;   
public:
    DTNotificacion(string nombreVendedor, set<int> productos, string nombrePromo);
    ~DTNotificacion();
    string getNombreVendedor();
    set<int> getProductos();
    string getNombrePromo();      
};
