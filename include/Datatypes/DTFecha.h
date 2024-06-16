#ifndef _DTFECHA_H
#define _DTFECHA_H

class DTFecha
{
public:
    int anio;
    int mes;
    int dia;
    DTFecha(int dia, int mes, int anio);
    DTFecha() = default;
    ~DTFecha();
    bool operator>(const DTFecha &otra) const;
};

#endif // _DTFECHA_H
