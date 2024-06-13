#ifndef _DTCOMENTARIO_H
#define _DTCOMENTARIO_H

#include <string>
#include "./Datatypes/DTFecha.h"
using namespace std;

class DTComentario
{
public:
    int id;
    string contenido;
    DTFecha fecha;   
    DTComentario(int id, string contenido, DTFecha fecha);
    DTComentario();
    ~DTComentario();
};

#endif _DTCOMENTARIO_H
