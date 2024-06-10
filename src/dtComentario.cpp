// File: dtComentario.cpp

#include "../include/dtComentario.h"

// Constructor

DTComentario::DTComentario(int id, string contenido, DTFecha fecha)
    : id(id), contenido(contenido), fecha(fecha) {}

// Destructor

DTComentario::~DTComentario() {}

// Getters

int DTComentario::getId() {
    return this->id;
}

string DTComentario::getContenido() {
    return this->contenido;
}

DTFecha DTComentario::getFecha() {
    return this->fecha;
}

// Setters

void DTComentario::setId(int id) {
    this->id = id;
}

void DTComentario::setContenido(string contenido) {
    this->contenido = contenido;
}

void DTComentario::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}
