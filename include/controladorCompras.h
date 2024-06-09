#include <string>
using namespace std;


class controladorCompras : public ICompras{
public:
    void registrarCompra();
    void finalizarCompra();
    Set(String) listarClientes();
    void seleccionarUsuario(String);
    DTCompra solicitarDetallesCompra();
    void calcularPrecio(Promocion, Set(ParProdCant));
}