// File: dtNotificacion.h

#ifndef _DTNOTIFICACION_H
#define _DTNOTIFICACION_H

#include <string>
#include <set>

using namespace std;

class DTNotificacion {
private:
    string nombreVendedor;
    set<int> productos;
    string nombrePromo;
public:
    // Constructor
    DTNotificacion(string nombreVendedor, set<int> productos, string nombrePromo);

    // Destructor
    virtual ~DTNotificacion();

    // Getters
    string getNombreVendedor();
    set<int> getProductos();
    string getNombrePromo();

    // Setters
    void setNombreVendedor(string nombreVendedor);
    void setProductos(set<int> productos);
    void setNombrePromo(string nombrePromo);
};

#endif  // _DTNOTIFICACION_H