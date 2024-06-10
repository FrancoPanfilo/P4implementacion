// File: comentario.h

#ifndef _COMENTARIO_H
#define _COMENTARIO_H

#include "dtFecha.h"

#include <string>

using namespace std;

class Comentario {
private:
    string contenido;
    DTFecha fecha;
public:
    // Constructor
    Comentario(string contenido, DTFecha fecha);

    // Destructor
    virtual ~Comentario();

    // Getters
    string getContenido();
    DTFecha getfecha();

    // Setters
    void setContenido(string texto);
    void setFecha(DTFecha fecha);

    // Metodos
    void borrarRespuestas();
    void destroy();
};

#endif  // _COMENTARIO_H