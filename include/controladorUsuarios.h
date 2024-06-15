// File: controladorUsuarios.h

#ifndef _CONTROLADORUSUARIOS_H
#define _CONTROLADORUSUARIOS_H

#include <string>
#include <set>
#include <map>

#include "./Datatypes/DTComentario.h"
#include "./Datatypes/DTProducto.h"
#include "./Datatypes/DTAltaCliente.h"
#include "./Datatypes/DTAltaVendedor.h"
#include "./Interface/IUsuario.h"
using namespace std;

class ControladorUsuarios : public IUsuario
{
private:
    static ControladorUsuarios *instance;
    ControladorUsuarios();
    //~ControladorUsuarios();
    map<string, Cliente > listaClientes;
    map<string, Vendedor > listaVendedores;
    map<string, Usuario > listaUsuarios;

public:
    static ControladorUsuarios *getInstance();
    //ControladorUsuarios();
    //~ControladorUsuarios();

    // Getters
    //Vendedor getVendedor(string nickname);
    //Cliente getCliente(string nickname);
    set<string> getListaComentarios(string nickname);

    // Setters

    // Metodos
    void ingresarDatosCliente(DTAltaCliente altaCliente);
    void ingresarDatosVendedor(DTAltaVendedor altaVendedor);
    set<string> listarClientes();
    set<string> listarVendedores();
    set<string> listarUsuarios();
    set<string> listarNoSuscritos(string nickname);
    set<DTComentario> obtenerListaComentarios(string nickname);
    Cliente* obtenerCliente(string nickname);
    Vendedor* obtenerVendedor(string nickname);
    set<DTProducto> obtenerProdDeVendedor(string nickname);
};

#endif // _CONTROLADORUSUARIOS_H
