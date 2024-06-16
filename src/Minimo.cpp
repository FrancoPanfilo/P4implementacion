#include "../include/Datatypes/Minimo.h"

bool Minimo::verificarMinimo(ParProdCant prod){
    return cantidad <= prod.cantidad;
}