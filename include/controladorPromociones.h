#include <string>
using namespace std;


class controladorPromociones : public IPromociones{
public:
    void ingresarDatosPromocion(String, String, int, DTFecha);
    Promocion obtenerPromocion(Set(ParProdCant));
    Set(String) obtenerNicknames():
    void seleccionarNickname(String);
    void agregarProductoAPromocion(int, int);
    Set(DTProducto) obtenerProductosAsociados(String);
    void confirmarCrearPromocion();
    int obtenerDescuento(ParProdCantidad);
}    