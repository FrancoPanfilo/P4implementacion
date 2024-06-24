// File controladorComentarios.h

#include "../include/controladorComentarios.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorProductos.h"

#include <cstddef>
#include <ctime>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <set>
#include <map>

using namespace std;

ControladorComentarios *ControladorComentarios::instance = NULL;

// Constructor
// ControladorComentarios::ControladorComentarios()
// {
// 	// Memoria vacía
// 	this->respondiendoA = -1;
// 	this->contenido = "";
// 	this->comentador = "";
// 	this->comentarioSobre = NULL;

// 	// Inicializamos id en 0
// 	this->ultimaId = 0;
// }

ControladorComentarios::ControladorComentarios()
    : ultimaId(0), comentador(""), contenido(""), respondiendoA(-1), comentarioSobre(NULL) {}

// Destructor
ControladorComentarios::~ControladorComentarios() {}

// Getters
ControladorComentarios *ControladorComentarios::getInstance()
{
	if (instance == NULL)
		instance = new ControladorComentarios();
	return instance;
}

// Setters

// Metodos

// void ControladorComentarios::borrarComentariosRecursivo(int idComentario) {
//
// }

void ControladorComentarios::cargarComentario(DTComentario c, string n)
{
	this->ultimaId++;
	ControladorProductos *contProductos = ControladorProductos::getInstance();
	Producto *p = contProductos->obtenerProducto(c.idProducto);
	Comentario *com = new Comentario(this->ultimaId, c.contenido, c.fecha, p, n);
	this->comentarios.insert(std::pair<int, Comentario *>(com->getId(), com));
	ControladorUsuarios *cUsuarios = ControladorUsuarios::getInstance();
	cUsuarios->agregarComentario(n, com);
}
void ControladorComentarios::cargarRespuesta(DTComentario c, int id, string n)
{
	this->ultimaId++;
	ControladorProductos *contProductos = ControladorProductos::getInstance();
	Producto *p = contProductos->obtenerProducto(c.idProducto);
	Comentario *com = new Comentario(this->ultimaId, c.contenido, c.fecha, p, n);
	this->comentarios.insert(std::pair<int, Comentario *>(com->getId(), com));
	ControladorUsuarios *cUsuarios = ControladorUsuarios::getInstance();
	cUsuarios->agregarComentario(n, com);
	Comentario *padre = this->comentarios.at(id);
	padre->agregarRespuesta(com);
	com->setRespuestaA(padre);
}

void ControladorComentarios::elegirYBorrarComentario(int idComentario)
{
	Comentario *com = this->comentarios.at(idComentario);

	// 1. Si el comentario es respuesta a otro, sacarlo de la lista de ese otro
	Comentario *padre = com->getRespuestaA();
	if (padre != NULL)
	{
		padre->borrarRespuesta(com);
	}

	// 2. Sacar de la lista del usuario
	ControladorUsuarios *cUsuarios = ControladorUsuarios::getInstance();
	cUsuarios->borrarComentario(com->getComentador(), com);

	// 3. Sacar de la lista global de comentarios
	this->comentarios.erase(idComentario);

	// 4. Aplicar lo mismo a las respuestas
	// TODO: en principio el paso 1. es redundante
	// Se podría hacer una función recursiva que ejecuta los pasos 2.-4. entonces el 1. corre solo para el primer comentario
	for (auto id : com->getIdRespuestas())
	{
		elegirYBorrarComentario(id);
	}
};

void ControladorComentarios::elegirProducto(int codigo)
{
	ControladorProductos *contProductos = ControladorProductos::getInstance();
	Producto *p = contProductos->obtenerProducto(codigo);
	this->comentarioSobre = p;
}

void ControladorComentarios::seleccionarUsuarioCom(string nick)
{
	this->comentador = nick;
}

void ControladorComentarios::introducirTexto(string contenido)
{
	this->contenido = contenido;
}

set<DTComentario> ControladorComentarios::listarComentarios()
{
	set<DTComentario> resultado;
	for (auto par : comentarios)
	{
		Comentario *com = par.second;
		DTComentario dt = DTComentario(com->getId(), com->getContenido(), com->getfecha(), com->getProducto()->getCodigo());
		resultado.insert(dt);
	}
	return resultado;
}

void ControladorComentarios::ingresarRespuesta(int codigo, string contenido)
{
	this->contenido = contenido;
	this->respondiendoA = codigo;
}

void ControladorComentarios::confirmarDejarComentario()
{
	this->ultimaId++;

	time_t ahora = time(0);
	tm *local = localtime(&ahora);
	// el mes empieza en 0 así q sumamos uno, y los años se cuentan desde 1900
	DTFecha fecha = DTFecha(local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
	Comentario *com = new Comentario(this->ultimaId, this->contenido, fecha, this->comentarioSobre, this->comentador);
	this->comentarios.insert(std::pair<int, Comentario *>(com->getId(), com));

	// Si el comentario es respuesta a alguien:
	// Registramos la relación bidireccional
	if (respondiendoA != -1)
	{
		Comentario *padre = this->comentarios.at(respondiendoA);
		padre->agregarRespuesta(com);
		com->setRespuestaA(padre);
	}

	ControladorUsuarios *cUsuarios = ControladorUsuarios::getInstance();
	cUsuarios->agregarComentario(this->comentador, com);

	// Reiniciamos memoria
	this->respondiendoA = -1;
	this->contenido = "";
	this->comentador = "";
	this->comentarioSobre = NULL;
}

void ControladorComentarios::eliminarTodosLosComentarios()
{
	for (auto it = comentarios.begin(); it != comentarios.end(); ++it)
	{
		delete it->second;
	}
	comentarios.clear();
}
