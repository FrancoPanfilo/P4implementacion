// File controladorUsuarios.cpp

#include "../include/controladorUsuarios.h"

ControladorUsuarios* ControladorUsuarios::instance = NULL;

// Constructor

ControladorUsuarios::ControladorUsuarios() {}

// Destructor

ControladorUsuarios::~ControladorUsuarios() {}

// Getters

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instance == NULL) {
        instance = new ControladorUsuarios();
    }
    return instance;
}

Vendedor ControladorUsuarios::getVendedor(string nickname) {
    return this->obtenerVendedor(nickname);
}

Cliente ControladorUsuarios::getCliente(string nickname) {
    return this->obtenerCliente(nickname);
}

set<string> ControladorUsuarios::getListaComentarios(string nickname) {
    return this->obtenerListaComentarios(nickname);
}

// Setters

// Metodos

void ControladorUsuarios::ingresarDatosCliente(DTAltaCliente altaCliente) {
    // TODO
}

void ControladorUsuarios::ingresarDatosVendedor(DTAltaVendedor altaVendedor) {
    // TODO
}

set<string> ControladorUsuarios::listarClientes() {
    // TODO
}

set<string> ControladorUsuarios::listarVendedores() {
    // TODO
}

set<string> ControladorUsuarios::listarUsuarios() {
    // TODO
}

set<string> ControladorUsuarios::listarNoSuscritos(string nickname) {
    // TODO
}

set<DTComentario> ControladorUsuarios::obtenerListaComentarios(string nickname) {
    // TODO
}

Cliente ControladorUsuarios::obtenerCliente(string nickname) {
    // TODO
}

Vendedor ControladorUsuarios::obtenerVendedor(string nickname) {
    // TODO
}

set<DTProducto> ControladorUsuarios::obtenerProdDeVendedor(string nickname) {
    // TODO
}
