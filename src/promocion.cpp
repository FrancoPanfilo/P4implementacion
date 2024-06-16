#include "../include/promocion.h" 


int Promocion::getDescuento(){
    return descuento;
}

DTFecha Promocion::getVencimiento(){
    return vencimiento;
}

String Promocion::getDescripcion(){
    return descripcion;
}


String Promocion::getNombre(){
    return nombre;
}


std::map<Producto, Minimo> Promocion::getMinimos(){
    return minimos;
}
Promocion Promocion::obtenerSiAplica(std::set<ParProdCant>){

}