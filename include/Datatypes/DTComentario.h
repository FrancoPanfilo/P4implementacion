#include <string>
#include "./Datatypes/DTFecha.h"
using namespace std;

class DTComentario
{
private:
    int id;
    string contenido;
    DTFecha fecha;   
public:
    DTComentario(int id, string contenido, DTFecha fecha);
    ~DTComentario();
    int getId();
    string getContenido();
    DTFecha getFecha(); 
};