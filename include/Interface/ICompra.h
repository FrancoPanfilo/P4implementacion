#ifndef _ICOMPRA_H
#define _ICOMPRA_H

#include <string>
#include <set>
#include "./promocion.h"
#include "./Datatypes/ParProdCant.h"
using String = std::string;
class ICompra
{
public:
    virtual void registrarCompra() = 0;
    virtual void finalizarCompra() = 0;
    virtual std::set<String> listarClientes() = 0;
    virtual void seleccionarUsuario(String) = 0;
    virtual void calcularPrecio(Promocion, std::set<ParProdCant>) = 0;
    virtual ~ICompra(){};
};
#endif // _ICOMPRA_H