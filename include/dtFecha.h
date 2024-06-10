// File: dtFecha.h

#ifndef _DTFECHA_H
#define _DTFECHA_H

#include <string>

class DTFecha {
private:
    int dia;
    int mes;
    int anio;
public:
    // Constructor
    DTFecha(int dia, int mes, int anio);

    // Destructor
    ~DTFecha();

    // Getters
    int getDia();
    int getMes();
    int getAnio();

    // Setters
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
};

#endif  // _DTFECHA_H