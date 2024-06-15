#ifndef _FABRICA_H
#define _FABRICA_H

#include <string>
#include <set>
#include "./Interface/IComentario.h"
#include "./Interface/IUsuario.h"
#include "./Interface/ISuscripcion.h"
#include "./Interface/IProducto.h"
#include "./Interface/ICompra.h"
#include "./Interface/IPromocion.h"
using String = std::string;
class Fabrica : public IUsuario
{
private:
    Fabrica *fabrica;

public:
    Fabrica();
    ~Fabrica();

    Fabrica *getFabrica();
    IComentario *getIComentarios();
    IUsuario *getIUsuarios();
    ISuscripcion *getISuscripciones();
    IProducto *getIProductos();
    ICompra *getICompras();
    IPromocion *getIPromociones();
};
#endif // _FABRICA_H
