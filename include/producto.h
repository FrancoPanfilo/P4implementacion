
#include <string>
using namespace std;


class Producto{
public:
    Producto() = default;
    Producto(int, int, int, String, String, String);
    ~Producto() = default;
    void agregarAPromo(String, int);
private:
    int codigo;
    int stock;
    int precio;
    String nombre;
    String descripcion;
    String tipo;
}