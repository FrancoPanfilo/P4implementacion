// File: dtAltaVendedor.h

#ifndef _DTALTAVENDEDOR_H
#define _DTALTAVENDEDOR_H

#include "dtFecha.h"

#include <string>

using namespace std;

class DTAltaVendedor {
private:
    string nickname;
    DTFecha fechaNac;
    string contrasenia;
    string rut;
public:
    // Constructor
    DTAltaVendedor(string nickname, DTFecha fechaNac, string contrasenia, string rut);

    // Destructor
    virtual ~DTAltaVendedor();

    // Getters
    string getNickname();
    DTFecha getFechaNac();
    string getContrasenia();
    string getRut();

    // Setters
    void setNickname(string nickname);
    void setFechaNac(DTFecha fechaNac);
    void setContrasenia(string contrasenia);
    void setRut(string rut);
};

#endif  // _DTALTAVENDEDOR_H