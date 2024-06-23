// File: IComentario.h

#ifndef _ICOMENTARIO_H
#define _ICOMENTARIO_H
#include <string>
#include <set>
#include "../Datatypes/DTComentario.h"

using namespace std;

class IComentario
{
public:
	// Metodos
	virtual void cargarComentario(DTComentario, string) = 0;
	virtual void cargarRespuesta(DTComentario, int, string) = 0;
	virtual void elegirYBorrarComentario(int idComentario) = 0;
	virtual void elegirProducto(int codigo) = 0;
	virtual void seleccionarUsuarioCom(string nick) = 0;
	virtual void introducirTexto(string contenido) = 0;
	virtual set<DTComentario> listarComentarios() = 0;
	virtual void ingresarRespuesta(int codigo, string contenido) = 0;
	virtual void confirmarDejarComentario() = 0;
	virtual void eliminarTodosLosComentarios() = 0;
};

#endif // _ICOMENTARIO_H