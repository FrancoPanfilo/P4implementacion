// File controladorComentarios.h

#include "../include/controladorComentarios.h"

#include <string>

using namespace std;

controladorComentarios * controladorComentarios::instance = NULL;

// Constructor

controladorComentarios::controladorComentarios() {}

// Destructor

ControladorComentarios::~ControladorComentarios() {}

// Getters

controladorComentarios * controladorComentarios::getInstance() {
    if (instance == NULL)
        instance = new controladorComentarios();
    return instance;
}


// Setters

// Metodos

void ControladorComentarios::elegirComentario(int idComentario) {
    // TODO
}
