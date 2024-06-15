// File: IUsuario.h

#ifndef _IUSUARIO_H
#define _IUSUARIO_H

#include "../Datatypes/DTComentario.h"
#include "../Datatypes/DTProducto.h"
#include "../Datatypes/DTAltaCliente.h"
#include "../Datatypes/DTAltaVendedor.h"
#include "../cliente.h"
#include "../vendedor.h"

#include <string>
#include <set>

using namespace std;

class IUsuario
{
public:
    // Metodos
    virtual IUsuario *getInstance() = 0;
    virtual void ingresarDatosCliente(DTAltaCliente altaCliente) = 0;
    virtual void ingresarDatosVendedor(DTAltaVendedor altaVendedor) = 0;
    virtual set<string> listarClientes() = 0;
    virtual set<string> listarVendedores() = 0;
    virtual set<string> listarUsuarios() = 0;
    virtual set<string> listarNoSuscritos(string nickname) = 0;
    virtual set<DTComentario> listarComentarios(string nickname) = 0;
    //virtual Cliente* obtenerCliente(string nickname) = 0;
    //virtual Vendedor* obtenerVendedor(string nickname) = 0;
    virtual set<DTProducto> prodDeVendedor(string nickname) = 0;
    virtual ~IUsuario(){};
};

#endif // _IUSUARIO_H
