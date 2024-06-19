#include "../include/controladorCompras.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorProductos.h"
#include "../include/controladorPromociones.h"

#include <ctime>
//#include <cstddef>

using namespace std;

ControladorCompras *ControladorCompras::instance = NULL;

ControladorCompras::ControladorCompras(){
	int idC = 0;
}
ControladorCompras::~ControladorCompras(){};

ControladorCompras *ControladorCompras::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorCompras();
    }
    return instance;
}

set<string> ControladorCompras::listarClientes(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	set<string> resultado = cu->listarClientes();
	return resultado;
}

void ControladorCompras::seleccionarUsuario(String nickname){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	cliente = cu->obtenerCliente(nickname);
	time_t ahora = time(0);
	tm *local = localtime(&ahora);
	fechaActual = DTFecha(local->tm_mday, local->tm_mon+1, local->tm_year+1900);
}

void ControladorCompras::seleccionarProducto(int cantidad, int id){
	ControladorProductos* cpro = ControladorProductos::getInstance();
	Producto p = cpro->obtenerProducto(id);
	ParProdCant par = ParProdCant(p, cantidad);
	datosProductos.insert(par);
	envios.insert(std::pair<int, bool>(id, false));
	//bajar y controlar el stock
}

double ControladorCompras::calcularPrecio(){	
	double total = 0;
	ControladorPromociones* cprom = ControladorPromociones::getInstance();
	Promocion* promo = cprom->obtenerPromocion(datosProductos);
	if (promo != NULL){
		int desc = promo->getDescuento();
		set<DTProducto> pd = promo->getProductos();
		for (auto p : datosProductos){
			Producto pr = p.producto;
			if (pd.count(DTProducto(pr.getCodigo(), pr.getStock(), pr.getPrecio(), pr.getNombre(), pr.getDescripcion(), pr.getTipo())) == 1){
				total += (p.cantidad * pr.getPrecio()) / desc;
			} else {
				total += p.cantidad * pr.getPrecio();
			}
		}
	} else {
		for (auto p : datosProductos){
			Producto pr = p.producto;
			total += p.cantidad * pr.getPrecio();
		}
	};		
	precioTotal = total;
	return total;
}

void ControladorCompras::registrarCompra(){
	idC++;
	Compra compra = Compra(fechaActual, precioTotal, idC, datosProductos, envios);
	cliente->getCompras().insert(std::pair <int, Compra>(idC, compra));
	compras.insert((std::pair <int, Compra>(idC, compra)));
}

void ControladorCompras::finalizarCompra(){
	precioTotal = 0;
	datosProductos.clear();
	nickname = "";

}





