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
using string = std::string;

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
    // void setPromociones(std::set<Promocion>);
    void ingresarDatosPromocion(string, string, int, DTFecha);
    void agregarPromocion(Promocion);
    Promocion *obtenerPromocion(std::set<ParProdCant>);
    std::set<string> obtenerNicknames();
    void seleccionarNickname(string);
    void agregarProductoAPromocion(int, int);
    std::set<DTProducto> obtenerProductosAsociados(string);
    void confirmarCrearPromocion();
    int obtenerDescuento(ParProdCant);

    std::set<DTPromocion> obtenerPromocionesVigentes();
    DTProductosYVendedor seleccionarPromocionPorNombre(String);
    std::set<DTPromocion> listarPromocionesVendedor(String nickname);
};

#endif // _CONTROLADORPROMOCIONES_H
