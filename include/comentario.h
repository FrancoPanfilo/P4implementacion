// File: comentario.h

#ifndef _COMENTARIO_H
#define _COMENTARIO_H

#include "./Datatypes/DTFecha.h"
#include "producto.h"

#include <map>
#include <string>

using namespace std;

class Comentario
{
private:
	int id;
    string contenido;
    DTFecha fecha;
	map<int, Comentario*> respuestas;
	Producto *producto; 

public:
    // Constructor
    Comentario(int id, string contenido, DTFecha fecha, Producto* producto);
    Comentario();

    // Destructor
    virtual ~Comentario();

    // Getters
    int getId();
    string getContenido();
    DTFecha getfecha();

    // Setters
    void setContenido(string texto);
    void setFecha(DTFecha fecha);

    // Metodos
	void agregarRespuesta(Comentario *respuesta);
    void borrarRespuestas();
    void destroy();
};

#endif // _COMENTARIO_H
