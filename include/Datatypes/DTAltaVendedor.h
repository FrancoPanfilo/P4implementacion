#ifndef _DTALTAVENDEDOR_H
#define _DTALTAVENDEDOR_H

#include <string>
#include "./Datatypes/DTFecha.h"
using namespace std;
 
class DTAltaVendedor
{
private:
    string nickname;
    DTFecha fechaNac;
    string contrasenia;
    int RUT;
public:
    DTAltaVendedor(string nickname, DTFecha fechaNac, string contrasenia, int RUT);
    ~DTAltaVendedor();
    string getNickname();
    DTFecha getFechaNac();
    string getContrasenia();
    int getRUT();
};

#endif _DTALTAVENDEDOR_H