// File comentario.cpp

#include "../include/comentario.h"

#include <set>
#include <string>

using namespace std;

// Constructor

Comentario::Comentario(int id, string contenido, DTFecha fecha, Producto *producto, string comentador) 
    : id(id), contenido(contenido), fecha(fecha), producto(producto), comentador(comentador) {
	this->respuestaA = NULL;
}

// Destructor

//Comentario::Comentario() {}
Comentario::Comentario()
    : respuestaA(NULL), producto(NULL) {}
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

Comentario* Comentario::getRespuestaA() {
	return respuestaA;
}

string Comentario::getComentador() {
	return comentador;
}

set<int> Comentario::getIdRespuestas() {
	set<int> ids;
	for (auto par : respuestas) {
		ids.insert(par.first);
	}
	return ids;
}

Producto* Comentario::getProducto(){
	return producto;
}
// Setters

void Comentario::setContenido(string texto) {
    contenido = texto;
}

void Comentario::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

void Comentario::setRespuestaA(Comentario *com) {
	this->respuestaA = com;
}

// Metodos
void Comentario::agregarRespuesta(Comentario *respuesta) {
	this->respuestas.insert(std::pair<int, Comentario*>(respuesta->getId(), respuesta));
}

void Comentario::borrarRespuesta(Comentario *respuesta) {
	this->respuestas.erase(respuesta->getId());
}

void Comentario::destroy() {
    // TODO
}
