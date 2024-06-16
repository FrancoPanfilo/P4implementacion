#ifndef _CONTROLADORPROMOCIONES_H
#define _CONTROLADORPROMOCIONES_H

#include <string>
#include <set>
#include <map>
#include "./promocion.h"
#include "./compra.h"
#include "./Datatypes/ParProdCant.h"
#include "./Datatypes/DTFecha.h"
#include "./Datatypes/DTProductosYVendedor.h"
#include "./Datatypes/DTPromocion.h"
#include "Interface/IPromocion.h"
using String = std::string;

class ControladorPromociones : public IPromocion
{
private:
    static ControladorPromociones *instance;
    std::map<string, Promocion> promociones;
    DTPromocion promocionTmp;
    String nickname;
    std::set<ParProdCant> productosTmp;

public:
    static ControladorPromociones *getInstance();

    ControladorPromociones();
    ~ControladorPromociones();

     std::map<string, Promocion> listarPromociones();
    //void setPromociones(std::set<Promocion>);
    void ingresarDatosPromocion(String, String, int, DTFecha);
    Promocion *obtenerPromocion(std::set<ParProdCant>);
    std::set<String> obtenerNicknames();
    void seleccionarNickname(String);
    void agregarProductoAPromocion(int, int);
    std::set<DTProducto> obtenerProductosAsociados(String);
    void confirmarCrearPromocion();
    int obtenerDescuento(ParProdCant);

    std::set<DTPromocion> obtenerPromocionesVigentes();
    DTProductosYVendedor seleccionarPromocionPorNombre(String);
};

#endif // _CONTROLADORPROMOCIONES_H
