#ifndef _CONTROLADORPROMOCIONES_H
#define _CONTROLADORPROMOCIONES_H

#include <string>
#include <set>
#include "./promocion.h"
#include "./compra.h"
#include "./datatypes.h"

using String = std::string;

class ControladorPromociones
{
private:
    std::set<Promocion> promociones;
    Promocion promocionTmp;
    String nickname;
    std::set<ParProdCant> productosTmp;

public:
    ControladorPromociones(/* args */);
    ~ControladorPromociones();

    void setPromociones(std::set<Promocion>);
    std::set<Promocion> getPromociones();
    void setPromocionTmp(Promocion);
    Promocion getPromocionTmp();
    void setNickname(String);
    String getNickname();
    void setProductosTmp(std::set<ParProdCant>);
    std::set<ParProdCant> getProductosTmp();

    void ingresarDatosPromocion(String, String, int, DTFecha);
    Promocion obtenerPromocion(std::set<ParProdCant>);
    std::set<String> obtenerNicknames();
    void seleccionarNickname(String);
    void agregarProductosAPromocion(int, int);
    std::set<DTProducto> obtenerProductosAsociados(String);
    void confirmarCrearPromocion();
    int obtenerDescuento(ParProdCant);
};

#endif // _CONTROLADORPROMOCIONES_H
