// File: IUsuario.h

#ifndef _IUSUARIO_H
#define _IUSUARIO_H

#include "../Datatypes/DTComentario.h"
#include "../Datatypes/DTProducto.h"
#include "../Datatypes/DTAltaCliente.h"
#include "../Datatypes/DTAltaVendedor.h"
#include "../Datatypes/DTPromocion.h"
#include "../Datatypes/DTDetalleCompra.h"
#include "../Datatypes/DTCliente.h"
#include "../Datatypes/DTVendedor.h"
#include "../cliente.h"
#include "../vendedor.h"

#include <string>
#include <set>

using namespace std;

class IUsuario
{
public:
    // Metodos
    virtual void ingresarDatosCliente(DTAltaCliente altaCliente) = 0;
    virtual void ingresarDatosVendedor(DTAltaVendedor altaVendedor) = 0;
    virtual set<string> listarClientes() = 0;
    virtual set<string> listarVendedores() = 0;
    // Creo q esto debería devolver todo, no solo nicknames
    virtual set<string> listarUsuarios() = 0;
    virtual set<string> listarNoSuscritos(string nickname) = 0;
    virtual set<DTComentario> listarComentarios(string nickname) = 0;
    virtual Cliente *obtenerCliente(string nickname) = 0;
    virtual Vendedor *obtenerVendedor(string nickname) = 0;
    virtual set<DTProducto> prodDeVendedor(string nickname) = 0;

    virtual void seleccionarNickname(string nickname) = 0;
    virtual set<DTProducto> listarProductosVendedor() = 0;
    virtual set<DTPromocion> listarPromocionesVendedor() = 0;
    virtual DTVendedor listarInfoVendedor() = 0;
    virtual set<DTDetalleCompra> listarComprasCliente() = 0;
    virtual DTCliente listarInfoCliente() = 0;
    virtual void finalizarExpediente() = 0;

    virtual ~IUsuario(){};

    virtual void eliminarTodosLosUsuarios() = 0;
    virtual void eliminarProductosAsociados() = 0;
};

#endif // _IUSUARIO_H
