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
#include "Datatypes/DTCliente.h"
#include "Datatypes/DTPromocion.h"
#include "Datatypes/DTVendedor.h"
#include "Datatypes/DTProductoId.h"
#include "producto.h"
using namespace std;

class ControladorUsuarios : public IUsuario
{
private:
    static ControladorUsuarios *instance;
    ControladorUsuarios();
    //~ControladorUsuarios();
    map<string, Cliente *> listaClientes;
    map<string, Vendedor *> listaVendedores;
    map<string, Usuario *> listaUsuarios;
    string nickGuardado;
    // atributo privado para lo que quiero guardar en las operaciones que guardan algo en la memoria

public:
    static ControladorUsuarios *getInstance();
    // ControladorUsuarios();
    //~ControladorUsuarios();

    // Getters
    // Vendedor getVendedor(string nickname);
    // Cliente getCliente(string nickname);
    set<string> getListaComentarios(string nickname);

    // Setters

    // Metodos
    void ingresarDatosCliente(DTAltaCliente altaCliente);
    void ingresarDatosVendedor(DTAltaVendedor altaVendedor);
    set<string> listarClientes();
    set<string> listarVendedores();
    set<string> listarUsuarios();
    set<string> listarNoSuscritos(string nickname);
    set<DTComentario> listarComentarios(string nickname);
    Cliente *obtenerCliente(string nickname);
    Vendedor *obtenerVendedor(string nickname);
    set<DTProducto> prodDeVendedor(string nickname);

    void seleccionarNickname(string nickname);
    set<DTProducto> listarProductosVendedor();
    set<DTPromocion> listarPromocionesVendedor();
    DTVendedor listarInfoVendedor();
    set<DTDetalleCompra> listarComprasCliente();
    DTCliente listarInfoCliente();
    void finalizarExpediente();
    void agregarCompra(Compra*);



    void agregarComentario(string nickname, Comentario *com);
    void borrarComentario(string nickname, Comentario *com);
    void eliminarTodosLosUsuarios();
    void eliminarProductosAsociados();
};

#endif // _CONTROLADORUSUARIOS_H
