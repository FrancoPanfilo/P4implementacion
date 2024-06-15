// File: controladorComentarios.h

#ifndef _CONTROLADORCOMENTARIOS_H
#define _CONTROLADORCOMENTARIOS_H

#include "./Interface/IComentario.h"
#include "Datatypes/DTComentario.h"

#include <string>
#include <set>

using namespace std;

class ControladorComentarios : public IComentario
{
private:
    static ControladorComentarios *instance;
    ControladorComentarios();
    ~ControladorComentarios();

public:
    static ControladorComentarios *getInstance();

    // Getters

    // Setters

    // Metodos
    // Eliminar Comentario
    void elegirComentario(int idComentario);

    // Dejar Comentario
    void seleccionarUsuarioCom(string nick);
    void introducirTexto(string contenido);
    set<DTComentario> listarComentarios();
    void ingresarRespuesta(int codigo, string contenido);
    void confirmarDejarComentario();
};

#endif // _CONTROLADORCOMENTARIOS_H
