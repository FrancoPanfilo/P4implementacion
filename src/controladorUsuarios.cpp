// File controladorUsuarios.cpp

#include "../include/controladorUsuarios.h"

ControladorUsuarios *ControladorUsuarios::instance = NULL;

// Constructor

ControladorUsuarios::ControladorUsuarios() {}

// Destructor

ControladorUsuarios::~ControladorUsuarios() {}

// Getters

ControladorUsuarios *ControladorUsuarios::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorUsuarios();
    }
    return instance;
}

Vendedor ControladorUsuarios::getVendedor(string nickname)
{
    return this->obtenerVendedor(nickname);
}

Cliente ControladorUsuarios::getCliente(string nickname)
{
    return this->obtenerCliente(nickname);
}

/* set<string> ControladorUsuarios::getListaComentarios(string nickname)
{
    return;
}
 */
// Setters

// Metodos

void ControladorUsuarios::ingresarDatosCliente(DTAltaCliente altaCliente)
{
    Cliente *c = c->create(altaCliente);
    listaClientes.insert(c);
    listaUsuarios.insert(c);
}

void ControladorUsuarios::ingresarDatosVendedor(DTAltaVendedor altaVendedor)
{
    Vendedor *v = v->create(altaVendedor);
    listaVendedores.insert(v);
    listaUsuarios.insert(v);
}

set<string> ControladorUsuarios::listarClientes()
{
    set<string> nicknames;
    for (auto cliente : listaClientes)
    {
        nicknames.insert(cliente->getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarVendedores()
{
    set<string> nicknames;
    for (auto vendedor : listaVendedores)
    {
        nicknames.insert(vendedor->getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarUsuarios()
{
    set<string> nicknames;
    for (auto usuario : listaUsuarios)
    {
        nicknames.insert(usuario->getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarNoSuscritos(string nickname)
{
    // TODO
}

set<DTComentario> ControladorUsuarios::obtenerListaComentarios(string nickname)
{
    // TODO
}

Cliente ControladorUsuarios::obtenerCliente(string nickname)
{
    // TODO
}

Vendedor ControladorUsuarios::obtenerVendedor(string nickname)
{
    // TODO
}

set<DTProducto> ControladorUsuarios::obtenerProdDeVendedor(string nickname)
{
    // TODO
}
