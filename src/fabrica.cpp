#include "../include/fabrica.h"

Fabrica::Fabrica()
{
}

IUsuario *Fabrica::getIUsuarios()
{
    return IUsuario::getInstance();
}
/*
IComentario *Fabrica::getIComentarios()
{
    return IComentario::getInstance();
}
ISuscripcion *Fabrica::getISuscripciones()
{
    return ISuscripcion::getInstance();
}
IProducto *Fabrica::getIProductos()
{
    return IProducto::getInstance();
}
ICompra *Fabrica::getICompras()
{
    return ICompra::getInstance();
}
IPromocion *Fabrica::getIPromociones()
{
    return IPromocion::getInstance();
} */