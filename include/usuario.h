// File: usuario.h

#ifndef _USUARIO_H
#define _USUARIO_H

#include "./Datatypes/DTFecha.h"
#include "./Datatypes/DTComentario.h"

#include <string>
#include <set>

using namespace std;

class Usuario
{
private:
    string nickname;
    string contrasenia;
    DTFecha fechaNac;
    set<DTComentario> comentarios;

public:
    // Constructor
    Usuario(string nickname, string contrasenia, DTFecha fecha);

    // Destructor
    virtual ~Usuario();

    // Getters
    string getNickname();
    string getContrasenia();
    DTFecha getFechaNac();
    set<DTComentario> getComentarios();

    // Setters
    void setNickname(string nickname);
    void setContrasenia(string contrasenia);

    // Metodos
    void eliminarNotificacionesPendientes();
    bool estaSuscrito(string nickname);
};

#endif // _USUARIO_H
