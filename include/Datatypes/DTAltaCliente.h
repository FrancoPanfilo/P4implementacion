#ifndef _DTALTACLIENTE_H
#define _DTALTACLIENTE_H

#include <string>
#include "./DTFecha.h"
using namespace std;

class DTAltaCliente
{
public:
    string nickname;
    DTFecha fechaNac;
    string contrasenia;
    string ciudad;
    string direccion;
    DTAltaCliente(string nickname, DTFecha fechaNac, string contrasenia, string ciudad, string direccion);
    //DTAltaCliente();
    //~DTAltaCliente();
};

#endif //_DTALTACLIENTE_H
