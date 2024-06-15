// File: IComentario.h

#ifndef _ICOMENTARIO_H
#define _ICOMENTARIO_H
#include "../fabrica.h"
#include <string>
#include <set>
#include "../Datatypes/DTComentario.h"

using namespace std;

class IComentario
{
public:
	// Metodos
	virtual void elegirComentario(int idComentario) = 0;
	virtual void seleccionarUsuarioCom(string nick) = 0;
	virtual void introducirTexto(string contenido) = 0;
	virtual set<DTComentario> listarComentarios() = 0;
	virtual void ingresarRespuesta(int codigo, string contenido) = 0;
	virtual void confirmarDejarComentario() = 0;
};

#endif // _ICOMENTARIO_H
