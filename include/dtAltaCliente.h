// File: dtAltaCliente.h

#ifndef _DTALTACLIENTE_H
#define _DTALTACLIENTE_H

#include "dtFecha.h"

#include <string>

using namespace std;

class DTAltaCliente {
private:
    string nickname;
    DTFecha fechaNac;
    string contrasenia;
    string ciudad;
    string direccion;
public:
    // Constructor
    DTAltaCliente(string nickname, DTFecha fechaNac, string contrasenia, string ciudad, string direccion);

    // Destructor
    virtual ~DTAltaCliente();

    // Getters
    string getNickname();
    DTFecha getFechaNac();
    string getContrasenia();
    string getCiudad();
    string getDireccion();

    // Setters
    void setNickname(string nickname);
    void setFechaNac(DTFecha fechaNac);
    void setContrasenia(string contrasenia);
    void setCiudad(string ciudad);
    void setDireccion(string direccion);
};

#endif  // _DTALTACLIENTE_H