#include <string>
using namespace std;


class controladorProductos : public IProductos {
public:
    Set(DTProducto) listarProductos();
    int seleccionarProducto(int,int);
    void agregarAPromo(String,int,int);
    Producto obtenerProducto(int);
}