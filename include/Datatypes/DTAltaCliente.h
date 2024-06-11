#include <string>
#include "./Datatypes/DTFecha.h"

class DTAltaCliente
{
private:
    String nickname;
    DTFecha fechaNac;
    String contrasenia;
    String ciudad;
    String direccion;
public:
    DTAltaCliente(String nickname, DTFecha fechaNac, String contrasenia, String ciudad, String direccion);
    ~DTAltaCliente(); 
    String getNickname();
    DTFecha getFechaNac();
    String getContrasenia();
    String getCiudad();
    String getDireccion();   
};
