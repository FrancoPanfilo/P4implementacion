// File: comentario.h

#ifndef _COMENTARIO_H
#define _COMENTARIO_H

#include "./Datatypes/DTFecha.h"
#include "producto.h"

#include <map>
#include <set>
#include <string>

using namespace std;

class Comentario
{
private:
	int id;
    string contenido;
    DTFecha fecha;
	map<int, Comentario*> respuestas;
	Comentario* respuestaA;
	Producto *producto; 
	string comentador; // nickname del Usuario que hizo el comentario

public:
    // Constructor
    Comentario(int id, string contenido, DTFecha fecha, Producto* producto, string comentador);
    Comentario();

    // Destructor
    virtual ~Comentario();

    // Getters
    int getId();
    string getContenido();
    DTFecha getfecha();
	Comentario* getRespuestaA();
	string getComentador();
	set<int> getIdRespuestas();
    Producto* getProducto();

    // Setters
    void setContenido(string texto);
    void setFecha(DTFecha fecha);
	void setRespuestaA(Comentario *com);

    // Metodos
	void agregarRespuesta(Comentario *respuesta);
    void borrarRespuesta(Comentario *respuesta);
    void destroy();
};

#endif // _COMENTARIO_H
