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
    string RUT;
    DTAltaVendedor(string nickname, DTFecha fechaNac, string contrasenia, string RUT);
    DTAltaVendedor() = default;
    ~DTAltaVendedor();
};

#endif //_DTALTAVENDEDOR_H
