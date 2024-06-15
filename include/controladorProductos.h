#ifndef _CONTROLADORPRODUCTOS_H
#define _CONTROLADORPRODUCTOS_H

#include <string>
#include <set>
#include <map>
#include "./producto.h"
#include "./Datatypes/DTProducto.h"
#include "./Datatypes/EnviosPendientes.h"
#include "./Interface/IProducto.h"

using String = std::string;

class ControladorProductos : public IProducto
{
private:
    static ControladorProductos *instance;
    std::map<int, Producto> productos;
    // es posible que se agreguen mas atributos para facilitar algunos procesos
public:
    static ControladorProductos *getInstance();
    ControladorProductos();
    ~ControladorProductos();
    std::set<DTProducto> listarProductos();
    int seleccionarProducto(int, int);
    void agregarAPromo(String, int, int);
    Producto obtenerProducto(int);

    std::set<DTProductoId> listarProductosConId();
    void seleccionarProductoPorCodigo(int);
    DTProducto mostrarProducto();

    std::set<string> listarVendedores();
    std::set<DTProducto> seleccionarVendedor(string nickname);
    std::set<EnviosPendientes> seleccionarProductoAEnviar(int);
    void seleccionarVenta(EnviosPendientes env);
};

#endif // _CONTROLADORPRODUCTOS_H
