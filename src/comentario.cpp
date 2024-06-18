// File comentario.cpp

#include "../include/comentario.h"

#include <string>

using namespace std;

// Constructor

Comentario::Comentario(int id, string contenido, DTFecha fecha, Producto *producto) 
    : id(id), contenido(contenido), fecha(fecha), producto(producto) {}

// Destructor

Comentario::Comentario() {}
Comentario::~Comentario() {}

// Getters

string Comentario::getContenido() {
    return contenido;
}

DTFecha Comentario::getfecha() {
    return fecha;
}

int Comentario::getId() {
	return id;
}

// Setters

void Comentario::setContenido(string texto) {
    contenido = texto;
}

void Comentario::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

// Metodos
void Comentario::agregarRespuesta(Comentario *respuesta) {
	this->respuestas.insert(std::pair<int, Comentario*>(respuesta->getId(), respuesta));
}

void Comentario::borrarRespuestas() {
	// TODO
}

void Comentario::destroy() {
    // TODO
}
