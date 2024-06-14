// File controladorUsuarios.cpp

#include "../include/controladorUsuarios.h"
#include <iostream>
#include <set>

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

/*Vendedor ControladorUsuarios::getVendedor(string nickname)
{
    return this->obtenerVendedor(nickname);
}*/

/*Cliente ControladorUsuarios::getCliente(string nickname)
{
    return this->obtenerCliente(nickname);
}*/

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
    set<string> s;
   return s; // TODO
}

set<DTComentario> ControladorUsuarios::obtenerListaComentarios(string nickname)
{
   set<DTComentario> d;
   return d; // TODO
}

Cliente* ControladorUsuarios::obtenerCliente(string nickname)
{
    Cliente *c;
    for (auto Cliente : listaClientes)
    {
        if (Cliente->getNickname() == nickname){
            c = Cliente;
        };
    }
    return c; 
}

Vendedor* ControladorUsuarios::obtenerVendedor(string nickname)
{
    Vendedor *v;
    for (auto Vendedor : listaVendedores)
    {
        if (Vendedor->getNickname() == nickname){
            v = Vendedor;
        };
    }
    return v;
}

set<DTProducto> ControladorUsuarios::obtenerProdDeVendedor(string nickname)
{
    set<DTProducto> c;
    return c;
}
