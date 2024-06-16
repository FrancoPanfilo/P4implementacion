#include "../include/controladorCompras.h"

using namespace std;

ControladorCompras *ControladorCompras::instance = NULL;

ControladorCompras::ControladorCompras(){}
ControladorCompras::~ControladorCompras(){};

ControladorCompras *ControladorCompras::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorCompras();
    }
    return instance;
}


void ControladorCompras::registrarCompra(){
	// TODO

}

void ControladorCompras::finalizarCompra(){
	// TODO

}

set<string> ControladorCompras::listarClientes(){
	// TODO
	set<string> resultado;
	return resultado;
}

void ControladorCompras::seleccionarUsuario(String){
	// TODO

}

void ControladorCompras::calcularPrecio(Promocion, std::set<ParProdCant>){
	// TODO

}
