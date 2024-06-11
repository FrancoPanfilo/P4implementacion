#include <string>
#include <set> 

class DTNotificacion
{
private:
    String nombreVendedor;
    Set<int> productos;
    String nombrePromo;   
public:
    DTNotificacion(String nombreVendedor, Set<int> productos, String nombrePromo);
    ~DTNotificacion();
    String getNombreVendedor();
    Set<int> getProductos();
    String getNombrePromo();      
};
