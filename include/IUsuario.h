// File: IUsuario.h

#ifndef _IUSUARIO_H
#define _IUSUARIO_H

#include "dtComentario.h"
#include "dtProducto.h"
#include "dtAltaCliente.h"
#include "dtAltaVendedor.h"
#include "cliente.h"
#include "vendedor.h"

#include <string>
#include <set>

using namespace std;

class IUsuario {
public:
    // Metodos
    virtual void ingresarDatosCliente(DTAltaCliente altaCliente) = 0;
    virtual void ingresarDatosVendedor(DTAltaVendedor altaVendedor) = 0;
    virtual set<string> listarClientes() = 0;
    virtual set<string> listarVendedores() = 0;
    virtual set<string> listarUsuarios() = 0;
    virtual set<string> listarNoSuscritos(string nickname) = 0;
    virtual set<DTComentario> obtenerListaComentarios(string nickname) = 0;
    virtual Cliente obtenerCliente(string nickname) = 0;
    virtual Vendedor obtenerVendedor(string nickname) = 0;
    virtual set<DTProducto> obtenerProdDeVendedor(string nickname) = 0;
};

#endif // _IUSUARIO_H