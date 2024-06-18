// File usuario.cpp

#include "../include/Datatypes/DTFecha.h"
#include "../include/usuario.h"

#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

// Constructor

Usuario::Usuario(string nickname, string contrasenia, DTFecha fechaNac)
    : nickname(nickname), contrasenia(contrasenia), fechaNac(fechaNac) {}

// Destructor

Usuario::~Usuario() {}

// Getters

string Usuario::getNickname()
{
    return nickname;
}

string Usuario::getContrasenia()
{
    return contrasenia;
}

DTFecha Usuario::getFechaNac()
{
    return fechaNac;
}

map<int, Comentario*> Usuario::getComentarios()
{
    return comentarios;
}

// Setters

void Usuario::setNickname(string nickname)
{
    this->nickname = nickname;
}

void Usuario::setContrasenia(string contrasenia)
{
    this->contrasenia = contrasenia;
}

void Usuario::agregarComentario(Comentario *com) {
	this->comentarios.insert(std::pair<int, Comentario*>(com->getId(), com));
}

void Usuario::borrarComentario(Comentario *com) {
	this->comentarios.erase(com->getId());
}
