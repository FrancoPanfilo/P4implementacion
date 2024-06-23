#ifndef _DTCOMENTARIO_H
#define _DTCOMENTARIO_H

#include <string>
#include "./DTFecha.h"
using namespace std;

class DTComentario
{
public:
    int id;
    string contenido;
    DTFecha fecha;
    int idProducto;
    DTComentario(int id, string contenido, DTFecha fecha, int idProducto);
    DTComentario() = default;
    ~DTComentario();

	bool operator<(const DTComentario& other) const;
};

#endif //_DTCOMENTARIO_H
