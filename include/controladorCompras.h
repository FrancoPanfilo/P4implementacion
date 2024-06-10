#ifndef _CONTROLADORCOMPRAS_H
#define _CONTROLADORCOMPRAS_H

#include <string>
#include <set>
#include "./promocion.h"
#include "./compra.h"
// import datatypes
using String = std::string;
class ControladorCompras
{
private:
    std::set<Compra> compras;
    String nickname;
    DTFecha fechaActual;
    std::set<ParProdCant> datosProductos;
    int precioTotal; // no se si se usa

public:
    ControladorCompras(/* args */);
    ~ControladorCompras();

    void setCompras(std::set<Compra>);
    std::set<Compra> getCompras();
    void setNickname(String);
    String getNickname();
    void setFechaActual(DTFecha);
    DTFecha getFechaActual();
    void setDatosProductos(std::set<ParProdCant>);
    std::set<ParProdCant> getDatosProductos();
    int getPrecioTotal();
    void setPrecioTotal(int);

    void registrarCompra();
    void finalizarCompra();
    std::set<String> listarClientes();
    void seleccionarUsuario(String);
    void calcularPrecio(Promocion, std::set<ParProdCant>)
};
#endif // _CONTROLADORCOMPRAS_H