#include <string>
#include "./Datatypes/DTFecha.h"


class DTComentario
{
private:
    int id;
    String contenido;
    DTFecha fecha;   
public:
    DTComentario(int id, String contenido, DTFecha fecha);
    ~DTComentario();
    int getId();
    String getContenido();
    DTFecha getFecha(); 
};