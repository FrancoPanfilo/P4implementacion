#ifndef _DTNOTIFICACION_H
#define _DTNOTIFICACION_H

#include <string>
#include <set> 
using namespace std;

class DTNotificacion
{
private:
    string nombreVendedor;
    set<int> productos;
    string nombrePromo;   
public:
    DTNotificacion(string nombreVendedor, set<int> productos, string nombrePromo);
    ~DTNotificacion();
    string getNombreVendedor();
    set<int> getProductos();
    string getNombrePromo();      
};

#endif // _DTNOTIFICACION_H