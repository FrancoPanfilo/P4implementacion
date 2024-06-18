// File: usuario.h

#ifndef _USUARIO_H
#define _USUARIO_H

#include "./Datatypes/DTFecha.h"
#include "./Datatypes/DTComentario.h"
#include "./comentario.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Usuario
{
private:
    string nickname;
    string contrasenia;
    DTFecha fechaNac;
    map<int, Comentario*> comentarios;

public:
    // Constructor
    Usuario(string nickname, string contrasenia, DTFecha fecha);
    Usuario() = default;
    // Destructor
    virtual ~Usuario();

    // Getters
    string getNickname();
    string getContrasenia();
    DTFecha getFechaNac();
    map<int, Comentario*> getComentarios();

    // Setters
    void setNickname(string nickname);
    void setContrasenia(string contrasenia);

    // Metodos
    void eliminarNotificacionesPendientes();
    bool estaSuscrito(string nickname);
	void agregarComentario(Comentario *com);
	void borrarComentario(Comentario *com);
};

#endif // _USUARIO_H
