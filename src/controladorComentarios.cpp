// File controladorComentarios.h

#include "../include/controladorComentarios.h"
#include "../include/controladorUsuarios.h"

#include <string>

using namespace std;

ControladorComentarios *ControladorComentarios::instance = NULL;

// Constructor
ControladorComentarios::ControladorComentarios() {}

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
void ControladorComentarios::elegirComentario(int idComentario) {
    // TODO
};


void ControladorComentarios::seleccionarUsuarioCom(string nick){

}
void ControladorComentarios::introducirTexto(string contenido){

}
set<DTComentario> ControladorComentarios::listarComentarios(){
	set<DTComentario> resultado;
	return resultado;
}

void ControladorComentarios::ingresarRespuesta(int codigo, string contenido){

}

void ControladorComentarios::confirmarDejarComentario(){

}
