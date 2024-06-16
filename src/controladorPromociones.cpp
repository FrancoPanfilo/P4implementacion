#include "../include/controladorPromociones.h"
#include <cstddef>
#include <set>
#include <string>

using namespace std;

ControladorPromociones *ControladorPromociones::instance = NULL;

ControladorPromociones::ControladorPromociones() {}
ControladorPromociones::~ControladorPromociones() {}

ControladorPromociones *ControladorPromociones::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorPromociones();
    }
    return instance;
}


set<DTPromocion> ControladorPromociones::obtenerPromocionesVigentes(){
	// TODO
	set<DTPromocion> promocionesVigentes;
	return promocionesVigentes;
}

DTProductosYVendedor ControladorPromociones::seleccionarPromocionPorNombre(string nombre){
	// TODO
	DTProductosYVendedor pyv;
	return pyv;
}

map<string, Promocion> ControladorPromociones::listarPromociones(){
	return promociones;
}


void ControladorPromociones::ingresarDatosPromocion(string nombre, string descripcion, int descuento, DTFecha fechaVenc){
	// TODO

}

/*
 * Devuelve una promoción si el conjunto de productos y cantidades aplica para la promoción
 * Si no, devuelve NULL
 * */
Promocion* ControladorPromociones::obtenerPromocion(set<ParProdCant>){
	// TODO
	Promocion *promo = NULL;
	return promo;

}
set<string> ControladorPromociones::obtenerNicknames(){
	set<string> nicknames;
	return nicknames;

}

void ControladorPromociones::seleccionarNickname(String){
	// TODO

}
void ControladorPromociones::agregarProductoAPromocion(int, int){
	// TODO

}
set<DTProducto> ControladorPromociones::obtenerProductosAsociados(String){
	// TODO

}
void ControladorPromociones::confirmarCrearPromocion(){
	// TODO

}
int ControladorPromociones::obtenerDescuento(ParProdCant){
	// TODO
	return 0;
}
