// File comentario.cpp

#include "../include/comentario.h"

#include <string>

using namespace std;

// Constructor

Comentario::Comentario(string contenido, DTFecha fecha) 
    : contenido(contenido), fecha(fecha) {}

// Destructor

Comentario::~Comentario() {}

// Getters

string Comentario::getContenido() {
    return contenido;
}

DTFecha Comentario::getfecha() {
    return fecha;
}

// Setters

void Comentario::setContenido(string texto) {
    contenido = texto;
}

void Comentario::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

// Metodos

void Comentario::borrarRespuestas() {
    // TODO
}

void Comentario::destroy() {
    // TODO
}
