#ifndef _Compra_H
#define _Compra_H
// import datatypes
class Compra
{
private:
    DTFecha fechaCompra;
    int montoFinal;

public:
    DTFecha getFechaCompra();
    int getMontoFinal();
};
#endif //_Compra_H