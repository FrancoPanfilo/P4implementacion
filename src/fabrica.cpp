#include "../include/fabrica.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorProductos.h"
#include "../include/controladorPromociones.h"
#include "../include/controladorSuscripciones.h"
#include "../include/controladorCompras.h"
#include "../include/controladorComentarios.h"
Fabrica::Fabrica()
{
}
Fabrica::~Fabrica()
{
}

Fabrica *Fabrica::fabrica = NULL;

Fabrica *Fabrica::getFabrica()
{

    if (fabrica = NULL)
    {
        fabrica = new Fabrica();
    }
    return fabrica;
}
IComentario *Fabrica::getIComentarios()
{
    return ControladorComentarios::getInstance();
}
IUsuario *Fabrica::getIUsuarios()
{
    return ControladorUsuarios::getInstance();
}

ISuscripcion *Fabrica::getISuscripciones()
{
    return ControladorSuscripciones::getInstance();
}
/*
ICompra *Fabrica::getICompras()
{
    return ControladorCompras::getInstance();
}
IPromocion *Fabrica::getIPromociones()
{
    return ControladorPromociones::getInstance();
}
*/
IProducto *Fabrica::getIProductos()
{
    return ControladorProductos::getInstance();
}