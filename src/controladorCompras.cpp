#include "../include/controladorCompras.h"
ControladorCompras *ControladorCompras::instance = NULL;

ControladorCompras *ControladorCompras::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorCompras();
    }
    return instance;
}