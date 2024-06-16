// File controladorComentarios.h

#include "../include/controladorComentarios.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorProductos.h"

#include <cstddef>
#include <ctime>
#include <stdexcept>
#include <string>
#include <set>

using namespace std;

ControladorComentarios *ControladorComentarios::instance = NULL;

// Constructor
ControladorComentarios::ControladorComentarios() {
	// Memoria vacía
	this->respondiendoA = -1;
	this->contenido = "";
	this->comentador = "";

	// Inicializamos id en 0
	this->ultimaId = 0;
}

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
void ControladorComentarios::elegirYBorrarComentario(int idComentario) {
	Comentario com = this->comentarios.at(idComentario);
	this->comentarios.erase(idComentario);
	com.borrarRespuestas();
};

void ControladorComentarios::elegirProducto(int codigo) {
	ControladorProductos *contProductos = ControladorProductos::getInstance();
	Producto p = contProductos->obtenerProducto(codigo);
	this->comentarioSobre = &p;
}

void ControladorComentarios::seleccionarUsuarioCom(string nick){
	this->comentador = nick;
}

void ControladorComentarios::introducirTexto(string contenido){
	this->contenido = contenido;	
}

set<DTComentario> ControladorComentarios::listarComentarios(){
	set<DTComentario> resultado;
	for (auto par: comentarios) {
		Comentario com = par.second;
		DTComentario dt = DTComentario(com.getId(), com.getContenido(), com.getfecha());
		resultado.insert(dt);
	}
	return resultado;
}

void ControladorComentarios::ingresarRespuesta(int codigo, string contenido){
	this->contenido = contenido;
	this->respondiendoA = codigo;
}

void ControladorComentarios::confirmarDejarComentario(){
	this->ultimaId++;

	time_t ahora = time(0);
	tm *local = localtime(&ahora);
	DTFecha fecha = DTFecha(local->tm_mday, local->tm_mon, local->tm_year);
	Comentario com = Comentario(this->ultimaId, this->contenido, fecha, this->comentarioSobre);

	// Buscamos al vendedor o cliente que está comentando
	// Fabrica *f = Fabrica::getFabrica();
	// IUsuario iusuario = f->getIUsuarios();
	ControladorUsuarios *cUsuarios = ControladorUsuarios::getInstance();

	Cliente *c = cUsuarios->obtenerCliente(this->comentador);
	if (c == NULL) {
		Vendedor *v = cUsuarios->obtenerVendedor(this->comentador);
		if (v == NULL) {
			throw std::runtime_error("No existe el usuario ingresado");
		}
		v->agregarComentario(com);
	} else {
		c->agregarComentario(com);
	}

	// Reiniciamos memoria
	this->respondiendoA = -1;
	this->contenido = "";
	this->comentador = "";
}

