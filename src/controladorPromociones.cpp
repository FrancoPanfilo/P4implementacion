#include "../include/controladorPromociones.h"
ControladorPromociones *ControladorPromociones::instance = NULL;

ControladorPromociones *ControladorPromociones::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorPromociones();
    }
    return instance;
}
