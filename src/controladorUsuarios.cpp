// File controladorUsuarios.cpp

#include "../include/controladorUsuarios.h"
#include "../include/controladorPromociones.h"
#include "../include/controladorProductos.h"
#include "../include/fabrica.h"
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

Vendedor *ControladorUsuarios::obtenerVendedor(string nickname)
{
    // if (listaVendedores.count(nickname) == 0)
    // {
    //     return NULL;
    // }
    auto entry = listaVendedores.find(nickname);
    if (entry == listaVendedores.end())
        return NULL;
    return entry->second;

    // return &(this->listaVendedores.at(nickname));
}

Cliente *ControladorUsuarios::obtenerCliente(string nickname)
{
    if (listaClientes.count(nickname) == 0)
    {
        return NULL;
    }
	Cliente* c =this->listaClientes.at(nickname); 
    return c;
}

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
        listaClientes.insert(std::pair<string, Cliente *>(c->getNickname(), c));
        listaUsuarios.insert(std::pair<string, Cliente *>(c->getNickname(), c)); // tal vez habría que guardar los datos acá y confirmar por separado, lo mismo con vendedor
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
		cout << "RUT: " << altaVendedor.RUT << endl;
        throw std::runtime_error("La RUT no está formada por 12 caracteres ");
    }
    else if (listaUsuarios.count(altaVendedor.nickname) > 0)
    {
        throw std::runtime_error("Ya existe un usuario con el nickname ingresado");
    }
    else
    {

        Vendedor *v = v->create(altaVendedor);
        listaVendedores.insert(std::pair<string, Vendedor *>(v->getNickname(), v));
        listaUsuarios.insert(std::pair<string, Vendedor *>(v->getNickname(), v));
    }
}

set<string> ControladorUsuarios::listarClientes()
{
    set<string> nicknames;
    for (auto cliente : listaClientes)
    {
        Cliente *cl = cliente.second;
        nicknames.insert(cl->getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarVendedores()
{
    set<string> nicknames;
    for (auto vendedor : listaVendedores)
    {
        Vendedor *v = vendedor.second;
        nicknames.insert(v->getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarUsuarios()
{
    set<string> nicknames;
    for (auto usuario : listaUsuarios)
    {
        Usuario *u = usuario.second;
        nicknames.insert(u->getNickname());
    }
    return nicknames;
}

set<string> ControladorUsuarios::listarNoSuscritos(string nickname)
{
    set<string> ns;
    Cliente *c = listaClientes.at(nickname);
    set<string> s = c->getSuscripciones();
    for (auto vendedor : listaVendedores)
    {
        Vendedor *v = vendedor.second;
        if (s.count(v->getNickname()) == 0)
        {
            ns.insert(v->getNickname());
        }
    }
    return ns;
}

set<DTComentario> ControladorUsuarios::listarComentarios(string nickname)
{
    set<DTComentario> d;
    Usuario *u = listaUsuarios.at(nickname);
    for (auto par : u->getComentarios())
    {
        Comentario *com = par.second;
        DTComentario dtc = DTComentario(com->getId(), com->getContenido(), com->getfecha());
        d.insert(dtc);
    }
    return d;
}

set<DTProducto> ControladorUsuarios::prodDeVendedor(string nickname)
{
    set<DTProducto> c;
    Vendedor *v = listaVendedores.at(nickname);
    c = v->getProductosAsociados();
    set<DTProducto> d;
    for (auto p : c)
    {
        d.insert(DTProducto(p.codigo, 0, 0, p.nombre, "", "")); // se podria hacer un creador con solo esos datos
    }
    return d;
}

void ControladorUsuarios::seleccionarNickname(string nickname)
{
    nickGuardado = nickname;
};

set<DTProducto> ControladorUsuarios::listarProductosVendedor()
{
    set<DTProducto> resultado;
    Vendedor *v = listaVendedores.at(nickGuardado);
    resultado = v->getProductosAsociados();
    return resultado;
}

set<DTPromocion> ControladorUsuarios::listarPromocionesVendedor()
{
    // Fabrica *f = Fabrica::getFabrica();
    ControladorPromociones *cp = ControladorPromociones::getInstance();
    set<DTPromocion> resultado = cp->listarPromocionesVendedor(nickGuardado);
    // Vendedor v = listaVendedores.at(nickGuardado);
    // ControladorPromociones cp = f->getIPromociones();
    //    map<string, Promocion> promos = cp.listarPromociones();
    //    for (auto p : promos){
    //        map<Producto, Minimo> min = p.second.getMinimos();
    //        pair<Producto, Minimo> primero = *min.begin();
    //        Producto pr = primero.first;
    //        DTProducto buscar = DTProducto(pr.getCodigo(),pr.getStock(),pr.getPrecio(),pr.getNombre(),pr.getDescripcion(),pr.getTipo());
    //        if (v.getProductosAsociados().count(buscar) == 1){
    //           resultado.insert(DTPromocion(p.second.getNombre(),p.second.getDescripcion(),p.second.getDescuento(),p.second.getVencimiento()));
    //        }
    //    }
    return resultado;
}

DTVendedor ControladorUsuarios::listarInfoVendedor()
{
    Vendedor *v = listaVendedores.at(nickGuardado);
    DTVendedor vendedor = DTVendedor(v->getNickname(), v->getFechaNac(), v->getRUT());
    return vendedor;
}

set<DTDetalleCompra> ControladorUsuarios::listarComprasCliente()
{
    set<DTDetalleCompra> resultado;
    Cliente *c = listaClientes.at(nickGuardado);
    map<int, Compra *> comp = c->getCompras();
    for (auto co : comp)
    {
        Compra *ca = co.second;
        resultado.insert(DTDetalleCompra(co.first, ca->getMontoFinal(), ca->getFechaCompra(), ca->getEnvios(), ca->getProductos(), ca->getCliente()->getNickname()));
    }
    return resultado;
}

DTCliente ControladorUsuarios::listarInfoCliente()
{
    Cliente *c = listaClientes.at(nickGuardado);
    DTCliente cliente = DTCliente(c->getNickname(), c->getFechaNac(), c->getCiudad(), c->getDireccion());
    return cliente;
}

void ControladorUsuarios::finalizarExpediente()
{
    nickGuardado = "";
}

void ControladorUsuarios::agregarComentario(string nickname, Comentario *com)
{
    Usuario *u = this->listaUsuarios.at(nickname);
    u->agregarComentario(com);
}

void ControladorUsuarios::borrarComentario(string nickname, Comentario *com)
{
    Usuario *u = this->listaUsuarios.at(nickname);
    u->borrarComentario(com);
}
