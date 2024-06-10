// File: dtComentario.h

#ifndef _DTCOMENTARIO_H
#define _DTCOMENTARIO_H

#include "dtFecha.h"

#include <string>

using namespace std;

class DTComentario {
private:
    int id;
    string contenido;
    DTFecha fecha;
public:
    // Constructor
    DTComentario(int id, string contenido, DTFecha fecha);

    // Destructor
    virtual ~DTComentario();

    // Getters
    int getId();
    string getContenido();
    DTFecha getFecha();

    // Setters
    void setId(int id);
    void setContenido(string contenido);
    void setFecha(DTFecha fecha);
};

#endif  // _DTCOMENTARIO_H