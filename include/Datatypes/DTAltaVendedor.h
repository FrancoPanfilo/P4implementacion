#include <string>
#include "./Datatypes/DTFecha.h"

class DTAltaVendedor
{
private:
    String nickname;
    DTFecha fechaNac;
    String contrasenia;
    int RUT;
public:
    DTAltaVendedor(String nickname, DTFecha fechaNac, String contrasenia, int RUT);
    ~DTAltaVendedor();
    String getNickname();
    DTFecha getFechaNac();
    String getContrasenia();
    int getRUT();
};