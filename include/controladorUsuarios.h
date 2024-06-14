// File: controladorUsuarios.h

#ifndef _CONTROLADORUSUARIOS_H
#define _CONTROLADORUSUARIOS_H

#include <string>
#include <set>

#include "dtComentario.h"
#include "dtProducto.h"
#include "dtAltaCliente.h"
#include "dtAltaVendedor.h"
#include "IUsuario.h"

using namespace std;

class ControladorUsuarios : public IUsuario {
private:
<<<<<<< Updated upstream
    static ControladorUsuarios * instance;
    ControladorUsuarios();
    ~ControladorUsuarios();
public:
    static ControladorUsuarios * getInstance();
=======
    static ControladorUsuarios *instance;
    //ControladorUsuarios();
    //~ControladorUsuarios();
    set<Cliente *> listaClientes;
    set<Vendedor *> listaVendedores;
    set<Usuario *> listaUsuarios;

public:
    ControladorUsuarios *getInstance();
    ~ControladorUsuarios();
    ControladorUsuarios();
>>>>>>> Stashed changes

    // Getters
    Vendedor getVendedor(string nickname);
    Cliente getCliente(string nickname);
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
    Cliente obtenerCliente(string nickname);
    Vendedor obtenerVendedor(string nickname);
    set<DTProducto> obtenerProdDeVendedor(string nickname);
};

#endif // _CONTROLADORUSUARIOS_H
