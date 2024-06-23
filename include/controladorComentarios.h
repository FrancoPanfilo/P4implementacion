// File: controladorComentarios.h

#ifndef _CONTROLADORCOMENTARIOS_H
#define _CONTROLADORCOMENTARIOS_H

#include "./Interface/IComentario.h"
#include "Datatypes/DTComentario.h"
#include "comentario.h"
#include "producto.h"

#include <map>
#include <string>
#include <set>

using namespace std;

class ControladorComentarios : public IComentario
{
private:
    static ControladorComentarios *instance;
    ControladorComentarios();
    ~ControladorComentarios();

    map<int, Comentario *> comentarios;

    // Registro de ids
    int ultimaId;

    // Memoria
    string comentador;         // Nickname del usuario ingresando un Comentario
    string contenido;          // Contenido del comentario
    int respondiendoA;         // Id del comentario al que estamos respondiendo
    Producto *comentarioSobre; // Referencia al producto correspondiente al comentario

    // void borrarComentarioRecursivo(int idComentario);

public:
    static ControladorComentarios *getInstance();

    // Getters

    // Setters

    // Metodos
    // Eliminar Comentario
    void elegirYBorrarComentario(int idComentario);

    // Dejar Comentario
    void cargarComentario(DTComentario, string);
    void cargarRespuesta(DTComentario, int, string);
    void elegirProducto(int codigo);
    void seleccionarUsuarioCom(string nick);
    void introducirTexto(string contenido);
    set<DTComentario> listarComentarios();
    void ingresarRespuesta(int codigo, string contenido);
    void confirmarDejarComentario();
    void eliminarTodosLosComentarios();
};

#endif // _CONTROLADORCOMENTARIOS_H
