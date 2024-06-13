#ifndef _DTNOTIFICACION_H
#define _DTNOTIFICACION_H

#include <string>
#include <set> 
using namespace std;

class DTNotificacion
{
public:
    string nombreVendedor;
    set<int> productos;
    string nombrePromo;   
    DTNotificacion(string nombreVendedor, set<int> productos, string nombrePromo);
    ~DTNotificacion();     
};

#endif // _DTNOTIFICACION_H