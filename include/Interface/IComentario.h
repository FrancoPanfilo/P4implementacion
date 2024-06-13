// File: IComentario.h

#ifndef _ICOMENTARIO_H
#define _ICOMENTARIO_H

#include <string>


using namespace std;

class IComentario {
public:
    // Metodos
    virtual void elegirComentario(int idComentario) = 0;
};

#endif // _ICOMENTARIO_H
