// File controladorUsuarios.cpp

#include "../include/controladorUsuarios.h"
#include <iostream>
#include <set>
#include <map>
#include <stdexcept>

ControladorUsuarios *ControladorUsuarios::instance = NULL;

// Constructor
ControladorUsuarios::ControladorUsuarios() {}

// Destructor

// ControladorUsuarios::~ControladorUsuarios() {}

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
    if (size(altaCliente.contrasenia) < 6)
    {
        throw std::runtime_error("Contraseña no es lo suficientemente larga");
    }
    else if (listaUsuarios.count(altaCliente.nickname) > 0)
    {
        throw std::runtime_error("Ya existe un usuario con el nickname ingresado");
    }
    else
    {
        Cliente *c = c->create(altaCliente);
        listaClientes.insert(std::pair<string, Cliente>(c->getNickname(), *c));
        listaUsuarios.insert(std::pair<string, Cliente>(c->getNickname(), *c));
    }
}

void ControladorUsuarios::ingresarDatosVendedor(DTAltaVendedor altaVendedor)
{
    if (size(altaVendedor.contrasenia) < 6)
    {
        throw std::runtime_error("Contraseña es demasiado corta");
    }
    else if (altaVendedor.RUT < 000000000000 || altaVendedor.RUT > 999999999999)
    {
        throw std::runtime_error("La RUT no está formada por 12 caracteres ");
    }
    else if (listaUsuarios.count(altaVendedor.nickname) > 0)
    {
        throw std::runtime_error("Ya existe un usuario con el nickname ingresado");
    }
    else
    {

        Vendedor *v = v->create(altaVendedor);
        listaVendedores.insert(std::pair<string, Vendedor>(v->getNickname(), *v));
        listaUsuarios.insert(std::pair<string, Vendedor>(v->getNickname(), *v));
    }
}

set<string> ControladorUsuarios::listarClientes()
{
    set<string> nicknames;
    for (auto cliente : listaClientes)
    {
        nicknames.insert(cliente.second.getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarVendedores()
{
    set<string> nicknames;
    for (auto vendedor : listaVendedores)
    {
        nicknames.insert(vendedor.second.getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarUsuarios()
{
    set<string> nicknames;
    for (auto usuario : listaUsuarios)
    {
        nicknames.insert(usuario.second.getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarNoSuscritos(string nickname)
{
    set<string> ns; 
    Cliente c = listaClientes.at(nickname);
    set<string> s = c.getSuscripciones();
    for (auto vendedor : listaVendedores){
        if (s.count(vendedor.second.getNickname()) == 0){
            ns.insert(vendedor.second.getNickname());
        }
    }    
    return ns;
}

set<DTComentario> ControladorUsuarios::listarComentarios(string nickname)
{
    set<DTComentario> d;
    Usuario u = listaUsuarios.at(nickname);
    d = u.getComentarios();
    return d;
}

/* Cliente* ControladorUsuarios::obtenerCliente(string nickname)
{
    Cliente *c;
    *c = listaClientes[nickname];
    return c;
}

Vendedor* ControladorUsuarios::obtenerVendedor(string nickname)
{
   Vendedor *v;
   *v = listaVendedores[nickname];
    return v;
} */

set<DTProductoId> ControladorUsuarios::prodDeVendedor(string nickname)
{
    set<DTProductoId> c;
    Vendedor *v;
    *v = listaVendedores.at(nickname);
    c = v->getProductosAsociados();
    return c;
}


void ControladorUsuarios::seleccionarNickname(string nickname){
	//TODO
}

set<DTProducto> ControladorUsuarios::listarProductosVendedor(){
	// TODO
	set<DTProducto> resultado;
	return resultado;
}

set<DTPromocion> ControladorUsuarios::listarPromocionesVendedor(){
	// TODO
	set<DTPromocion> resultado;
	return resultado;
}

DTVendedor ControladorUsuarios::listarInfoVendedor(){
	// TODO
	DTVendedor vendedor;
	return vendedor;
}

set<DTDetalleCompra> ControladorUsuarios::listarComprasCliente(){
	// TODO
	set<DTDetalleCompra> resultado;
	return resultado;
}

DTCliente ControladorUsuarios::listarInfoCliente(){
	// TODO
	DTCliente cliente;
	return cliente;
}

void ControladorUsuarios::finalizarExpediente(){
}
