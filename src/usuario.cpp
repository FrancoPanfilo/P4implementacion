// File usuario.cpp

#include "../include/dtFecha.h"
#include "../include/usuario.h"

#include <string>

using namespace std;

// Constructor

Usuario::Usuario(string nickname, string contrasenia, DTFecha fechaNac)
    : nickname(nickname), contrasenia(contrasenia), fechaNac(fechaNac) {}

// Destructor

Usuario::~Usuario() {}

// Getters

Usuario::getNickname() {
    return nickname;
}

Usuario::getContrasenia() {
    return contrasenia;
}

Usuario::getFechaNac() {
    return fechaNac;
}

Usuario::getComentarios() {
    return comentarios;
}

// Setters

void Usuario::setNickname(string nickname) {
    this->nickname = nickname;
}

void Usuario::setContrasena(string contrasenia) {
    this->contrasenia = contrasenia;
}

// Metodos

void Usuario::eliminarNotificacionesPendientes() {
    // TODO
}

bool Usuario::estaSuscrito(string nickname) {
    // TODO
}
