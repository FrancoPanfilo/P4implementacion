#ifndef _DTALTACLIENTE_H
#define _DTALTACLIENTE_H

#include <string>
#include "./Datatypes/DTFecha.h"
using namespace std;

class DTAltaCliente
{
private:
    string nickname;
    DTFecha fechaNac;
    string contrasenia;
    string ciudad;
    string direccion;
public:
    DTAltaCliente(string nickname, DTFecha fechaNac, string contrasenia, string ciudad, string direccion);
    ~DTAltaCliente(); 
    string getNickname();
    DTFecha getFechaNac();
    string getContrasenia();
    string getCiudad();
    string getDireccion();   
};

#endif _DTALTACLIENTE_H
