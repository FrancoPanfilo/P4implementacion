#ifndef _DTFECHA_H
#define _DTFECHA_H

class DTFecha
{
private:
    int anio;
    int mes;
    int dia;
public:
    DTFecha(int dia, int mes, int anio); 
    ~DTFecha();   
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

#endif _DTFECHA_H
