// File: controladorComentarios.h

#ifndef _CONTROLADORCOMENTARIOS_H
#define _CONTROLADORCOMENTARIOS_H

#include "dtComentario.h"
#include "dtProducto.h"
#include "IComentario.h"

#include <string>
#include <set>

using namespace std;

class ControladorComentarios : public IComentario {
private:
    static ControladorComentarios * instance;
    ControladorComentarios();
    ~ControladorComentarios();
public:
    static ControladorComentarios* getInstance();

    // Getters

    // Setters

    // Metodos
    void elegirComentario(int idComentario);
};

#endif // _CONTROLADORCOMENTARIOS_H