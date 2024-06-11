#include <string>

class DTProducto
{
private:
    int codigo;
    int stock;
    int precio;
    String nombre;
    String descripcion;
    String tipo;  
public:
    DTProducto(int codigo, int stock, int precio, String nombre, String descripcion, String tipo);
    ~DTProducto();
    int getCodigo();
    int getStock();
    int getPrecio();
    String getNombre();
    String getDescripcion();
    String getTipo();      
};