#ifndef _DTALTAVENDEDOR_H
#define _DTALTAVENDEDOR_H

#include <string>
#include "./DTFecha.h"
using namespace std;
 
class DTAltaVendedor
{
public:
    string nickname;
    DTFecha fechaNac;
    string contrasenia;
    int RUT;
    DTAltaVendedor(string nickname, DTFecha fechaNac, string contrasenia, int RUT);
    DTAltaVendedor();
    ~DTAltaVendedor();
};

#endif _DTALTAVENDEDOR_H
