// File controladorUsuarios.cpp

#include "../include/controladorUsuarios.h"
#include "../include/controladorPromociones.h"
#include "../include/controladorProductos.h"
#include "../include/fabrica.h"
#include <iostream>
#include <sstream>
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
    else if (altaVendedor.RUT.length() != 12)
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
    for (auto vendedor : listaVendedores)
    {
        if (s.count(vendedor.second.getNickname()) == 0)
        {
            ns.insert(vendedor.second.getNickname());
        }
    }
    return ns;
}

set<DTComentario> ControladorUsuarios::listarComentarios(string nickname)
{
    set<DTComentario> d;
    //Usuario u = listaUsuarios.at(nickname);
    //d = u.getComentarios();
    return d;
}

 Cliente* ControladorUsuarios::obtenerCliente(string nickname)
{   
    Cliente *c;
    *c = listaClientes.at(nickname);
    return c;
}

Vendedor* ControladorUsuarios::obtenerVendedor(string nickname)
{
   Vendedor *v;
   *v = listaVendedores.at(nickname);
    return v;
} 

set<DTProducto> ControladorUsuarios::prodDeVendedor(string nickname)
{
    set<DTProducto> c;
    Vendedor v = listaVendedores.at(nickname);
    c = v.getProductosAsociados();
    set<DTProducto> d;
    for (auto p : c){
        d.insert(DTProducto(p.codigo, 0, 0, p.nombre, "", "")); //se podria hacer un creador con solo esos datos
    }   
    return d;
}


void ControladorUsuarios::seleccionarNickname(string nickname){
	nickGuardado = nickname;
};

set<DTProducto> ControladorUsuarios::listarProductosVendedor(){
	set<DTProducto> resultado;
    Vendedor v = listaVendedores.at(nickGuardado);
    resultado = v.getProductosAsociados();
	return resultado;
}

set<DTPromocion> ControladorUsuarios::listarPromocionesVendedor(){
    //Fabrica *f = Fabrica::getFabrica();
    set<DTPromocion> resultado;
    Vendedor v = listaVendedores.at(nickGuardado);
    //ControladorPromociones cp = f->getIPromociones();
    ControladorPromociones cp ;
    map<string, Promocion> promos = cp.listarPromociones();
    for (auto p : promos){
        map<Producto, Minimo> min = p.second.getMinimos();
        pair<Producto, Minimo> primero = *min.begin();
        Producto pr = primero.first;
        DTProducto buscar = DTProducto(pr.getCodigo(),pr.getStock(),pr.getPrecio(),pr.getNombre(),pr.getDescripcion(),pr.getTipo());
        if (v.getProductosAsociados().count(buscar) == 1){
           resultado.insert(DTPromocion(p.second.getNombre(),p.second.getDescripcion(),p.second.getDescuento(),p.second.getVencimiento()));
        }           
    }   
	return resultado;
}

DTVendedor ControladorUsuarios::listarInfoVendedor(){
	DTVendedor vendedor;
    Vendedor v = listaVendedores.at(nickGuardado);
    //DTVendedor no tendría que tener nickname y fechaNac tambien? lo mismo con DTCliente
	return vendedor;
}

set<DTDetalleCompra> ControladorUsuarios::listarComprasCliente()
{
    // TODO
    set<DTDetalleCompra> resultado;
    return resultado;
}

DTCliente ControladorUsuarios::listarInfoCliente()
{
    // TODO
    DTCliente cliente;
    return cliente;
}

void ControladorUsuarios::finalizarExpediente()
{
}
