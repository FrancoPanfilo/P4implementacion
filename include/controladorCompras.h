#ifndef _CONTROLADORCOMPRAS_H
#define _CONTROLADORCOMPRAS_H

#include <string>
#include <iostream>
#include <set>
#include <map>
#include "./promocion.h"
#include "./compra.h"
#include "./Interface/ICompra.h"
#include "./Datatypes/DTFecha.h"
#include "./Datatypes/ParProdCant.h"
#include "./cliente.h"

using String = std::string;
class ControladorCompras : public ICompra
{
private:
    static ControladorCompras *instance;
    ControladorCompras();
    std::map<int, Compra> compras;
    String nickname;
    DTFecha fechaActual;
    std::set<ParProdCant> datosProductos;
    int precioTotal; // no se si se usa
    Cliente* cliente;
    int idC;
    map<int, bool> envios;

public:
    static ControladorCompras *getInstance();
    ~ControladorCompras();

    /* void setCompras(std::map<int, Compra>);
    std::map<int, Compra> getCompras();
    void setNickname(String);
    String getNickname();
    void setFechaActual(DTFecha);
    DTFecha getFechaActual();
    void setDatosProductos(std::set<ParProdCant>);
    std::set<ParProdCant> getDatosProductos();
    int getPrecioTotal();
    void setPrecioTotal(int); */

    std::set<String> listarClientes();
    void seleccionarUsuario(String);
    void seleccionarProducto(int, int);
    void calcularPrecio();
    void registrarCompra();
    void finalizarCompra();
    
    
    
    
};
#endif // _CONTROLADORCOMPRAS_H
