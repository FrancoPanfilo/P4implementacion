#include <cstdio>

#include <iostream>
#include <set>
#include <string>

#include "./include/Datatypes/DTAltaCliente.h"
#include "./include/Datatypes/DTAltaVendedor.h"
#include "include/Datatypes/DTProductosYVendedor.h"
#include "include/Interface/IComentario.h"
#include "include/Interface/IUsuario.h"
#include "include/Interface/ISuscripcion.h"
#include "include/Interface/IPromocion.h"
#include "include/Interface/ICompra.h"
#include "include/fabrica.h"
#include "datos.cpp"
using namespace std;

// Controladores
// ControladorUsuarios *contUsuarios = ControladorUsuarios(); fabrica

string leerStr(string pregunta)
{
	cout << pregunta;
	string respuesta;
	cin >> respuesta;
	return respuesta;
}

DTFecha leerDTFecha(string pregunta)
{
	cout << pregunta;
	DTFecha respuesta = DTFecha();
	scanf("%d %d %d", &respuesta.dia, &respuesta.mes, &respuesta.anio);
	return respuesta;
}

void mostrarFecha(DTFecha fecha)
{
	printf("%d/%d/%d", fecha.dia, fecha.mes, fecha.anio);
	std::cout << "" << std::endl;
}

void mostrarProducto(DTProducto p)
{
	std::cout << "Producto: " << p.nombre << " (" << p.codigo << ") . Descripcion: " << p.descripcion << "." << std::endl;
}
int leerInt(string pregunta)
{
	cout << pregunta;
	int respuesta;
	scanf("%d", &respuesta);
	return respuesta;
}

int leerDouble(string pregunta)
{
	cout << pregunta;
	int respuesta;
	scanf("%lf", &respuesta);
	return respuesta;
}

int main(int argc, char *argv[])
{

	Fabrica *f = Fabrica::getFabrica();
	IUsuario *contUsuarios = f->getIUsuarios();
	IComentario *contCom = f->getIComentarios();
	IProducto *contProductos = f->getIProductos();
	ISuscripcion *contSuscripciones = f->getISuscripciones();
	IPromocion *contPromociones = f->getIPromociones();
	ICompra *contCompra = f->getICompras();
	cargarDatos();

	string accion = "";

	while (accion != "salir")
	{
		cout << "Ingresar acción: ";
		cin >> accion;

		// ---- ControladorUsuarios ----
		if (accion == "ingresarDatosCliente")
		{
			DTAltaCliente data = DTAltaCliente();
			data.nickname = leerStr("Nickname: ");
			data.contrasenia = leerStr("Contrasenia: ");
			data.fechaNac = leerDTFecha("Fecha de nacimiento: ");
			data.ciudad = leerStr("Ciudad: ");
			data.direccion = leerStr("Direccion: ");

			contUsuarios->ingresarDatosCliente(data);
		}
		else if (accion == "ingresarDatosVendedor")
		{
			DTAltaVendedor data = DTAltaVendedor();
			data.nickname = leerStr("Nickname: ");
			data.contrasenia = leerStr("Contrasenia: ");
			data.fechaNac = leerDTFecha("Fecha de nacimiento: ");
			data.RUT = leerInt("RUT: ");

			contUsuarios->ingresarDatosVendedor(data);
		}
		else if (accion == "listarClientes")
		{
			set<string> clientes = contUsuarios->listarClientes();
			for (auto nick : clientes)
			{
				cout << nick << endl;
			}
		}
		else if (accion == "listarVendedores")
		{
			set<string> vendedores = contUsuarios->listarVendedores();
			for (auto nick : vendedores)
			{
				cout << nick << endl;
			}
		}
		else if (accion == "listarUsuarios")
		{
			set<string> usuarios = contUsuarios->listarUsuarios();
			for (auto nick : usuarios)
			{
				cout << nick << endl;
			}
		}
		else if (accion == "listarNoSuscritos")
		{
			string nickname = leerStr("Cliente: ");
			set<string> noSusc = contUsuarios->listarNoSuscritos(nickname);
			for (auto nick : noSusc)
			{
				cout << nick << endl;
			}
		}
		else if (accion == "agregarSuscripcion")
		{
			string nickname = leerStr("Cliente: ");
			set<string> noSusc = contSuscripciones->listarNoSuscritos(nickname);
			for (auto nick : noSusc)
			{
				cout << nick << endl;
			}
			bool seguir = true;
			set<string> sLista;
			while (seguir && size(noSusc) != 0)
			{
				string vendedor = leerStr("Vendedor: ");
				contSuscripciones->agregarSuscripcion(vendedor);
				string resp = leerStr("¿Desea seguir agregando suscripciones? [y/n] ");
				while (!(resp == "y" || resp == "n"))
				{
					resp = leerStr("Respuesta no válida. ¿Desea seguir agregando suscripciones? [y/n] ");
				}
				seguir = (resp == "y");
				sLista.insert(vendedor);
				noSusc.erase(vendedor);
			}
			cout << "Suscripciones:" << endl;
			for (auto s : sLista)
			{
				cout << s << endl;
			}
			string resp2 = leerStr("¿Desea confirmar las suscripciones? [y/n] ");
			while (!(resp2 == "y" || resp2 == "n"))
			{
				resp2 = leerStr("Respuesta no válida. ¿Desea confirmar las suscripciones? [y/n] ");
			}
			if (resp2 == "y")
			{
				contSuscripciones->confirmarSuscripcion();
			}
		}
		else if (accion == "obtenerListaComentarios")
		{
			string nickname = leerStr("Usuario: ");
			set<DTComentario> comentarios = contUsuarios->listarComentarios(nickname);
			for (auto com : comentarios)
			{
				printf("%d", com.id);
				mostrarFecha(com.fecha);
				cout << com.contenido << endl;
			}
		}
		else if (accion == "obtenerCliente")
		{
			string nickname = leerStr("Cliente: ");
			Cliente *c = contUsuarios->obtenerCliente(nickname);
			std::cout << "El cliente de nickname " << c->getNickname() << " vive en la ciudad "
					  << c->getCiudad() << " y tiene como direccion " << c->getDireccion() << ". Nacio el dia: ";
			mostrarFecha(c->getFechaNac());
			std::cout << std::endl;
		}
		else if (accion == "obtenerVendedor")
		{
			string nickname = leerStr("Vendedor: ");
			Vendedor *v = contUsuarios->obtenerVendedor(nickname);
			std::cout << "El vendedor de nickname " << v->getNickname() << " lo identifica el RUT "
					  << v->getRUT() << ". Nacio el dia: ";
			mostrarFecha(v->getFechaNac());
			std::cout << v->getNickname() << "Tiene asociados los siguientes productos: ";
			std::cout << std::endl;
			set<DTProducto> pa = v->getProductosAsociados();
			for (auto p : pa)
			{
				mostrarProducto(p);
			}
		}
		else if (accion == "prodDeVendedor")
		{
		}
		else if (accion == "seleccionarUsuarioCompra")
		{
			string nick = leerStr("Nickname: ");
			contCompra->seleccionarUsuario(nick);
		}
		else if(accion == "seleccionarProductoCompra")
		{	
			bool seguir = true;
			while (seguir){
				int idProd = leerInt("Ingrese id del producto: ");
				int cantidad = leerInt("Ingrese cantidad a comprar: ");
				contCompra->seleccionarProducto(cantidad, idProd);
				string resp = leerStr("¿Desea comprar otro producto? [y/n] ");
				while (!(resp == "y" || resp == "n"))
				{
					resp = leerStr("Respuesta no válida. ¿Desea comprar otro producto? [y/n] ");
				}
				seguir = (resp == "y");
			}
			DTDetalleCompra detalles = contCompra->devolverDetalles();
			//cout << "El monto final de la compra será: $" << detalles.montoFinal << endl;
			printf("El monto final de la compra será: %lf \n", detalles.montoFinal);
			cout << "Fecha de compra: ";
			mostrarFecha(detalles.fechaCompra);
			cout << "Producto/s a comprar: " << endl;
			for (auto dp : detalles.productos){
				cout << dp.producto.getNombre() << " x " << dp.cantidad << endl;
			}
		}
		else if (accion == "confirmarCompra"){
			contCompra->registrarCompra();
			contCompra->finalizarCompra();
		}
		else if (accion == "seleccionarNicknameExp")
		{
		}
		else if (accion == "listarProductosVendedor")
		{
		}
		else if (accion == "listarPromocionesVendedor")
		{
			string nickname = leerStr("Vendedor: ");
			set<DTPromocion> dp = contPromociones->listarPromocionesVendedor(nickname);
			cout << "EL vendedor " << nickname << " tiene las siguientes promociones." << std::endl;
			for (auto p : dp)
			{
				cout << "Nombre: " << p.nombre << std::endl
					 << "Descripción: " << p.descripcion << std::endl
					 << "Descuento: " << p.descuento << "%" << std::endl
					 << "Fecha de Vencimiento: " << std::endl;
				mostrarFecha(p.fechaVencimiento);
				std::cout << "" << std::endl;
			}
		}
		else if (accion == "listarInfoVendedor")
		{
		}
		else if (accion == "listarComprasCliente")
		{
		}
		else if (accion == "listarInfoCliente")
		{
		}
		else if (accion == "finalizarExpediente")
		{
		}
		// ---- ControladorPromociones ----
		else if (accion == "ingresarDatosPromocion") {
			string nombre = leerStr("Nombre: ");
			string descripcion = leerStr("Descripcion: ");
			int descuento = leerInt("Descuento: ");
			DTFecha fechaVenc = leerDTFecha("Vencimiento: ");
			contPromociones->ingresarDatosPromocion(nombre, descripcion, descuento, fechaVenc);
		} else if (accion == "obtenerNicknames") {
			set<string> vendedores = contPromociones->obtenerNicknames();
			for (auto nick : vendedores)
			{
				cout << nick << endl;
			}
		} else if (accion == "seleccionarNickname") {
			string nick = leerStr("Nickname: ");
			contPromociones->seleccionarNickname(nick);

		} else if (accion == "obtenerProductosAsociados") {
			set<DTProducto> dtproductos = contPromociones->obtenerProductosAsociados();
			for (auto p : dtproductos)
			{
				mostrarProducto(p);
			}
		} else if (accion == "agregarProductoAPromocion") {
			bool seguir = true;
			while (seguir) {
				int codigo = leerInt("Codigo: ");
				int cantidad = leerInt("Cantidad: ");
				contPromociones->agregarProductoAPromocion(codigo, cantidad);
				string resp = leerStr("¿Desea seguir agregando productos? [y/n]");
				while (!(resp == "y" || resp == "n"))
				{
					resp = leerStr("Respuesta no válida. ¿Desea seguir agregando productos? [y/n]");
				}
				seguir = resp == "y";
			}

		} else if (accion == "confirmarCrearPromocion") {
			contPromociones->confirmarCrearPromocion();
		} else if (accion == "obtenerPromocionesVigentes") {
			set<DTPromocion> promosVigentes = contPromociones->obtenerPromocionesVigentes();
			for (auto promo : promosVigentes) {
				cout << promo.nombre << " (-" << promo.descuento << "%): " << promo.descripcion << endl;
				cout << "Vendida por: " << promo.vendedor << endl;
				cout << "Hasta ";
				mostrarFecha(promo.fechaVencimiento);
			}

		} else if (accion == "seleccionarPromocionPorNombre") {
			string nombre = leerStr("Nombre de la promocion: ");
			DTProductosYVendedor pyv = contPromociones->seleccionarPromocionPorNombre(nombre);
			cout << "Vendedor: " << pyv.vendedor.getNickname() << endl;
			for (auto producto : pyv.productos) {
				mostrarProducto(producto);
			}
		}
		// ---- ControladorProductos ----

		else if (accion == "listarProductosConId") {
			set<DTProducto> productos = contProductos->listarProductosConId();
			for (auto producto : productos) {
				mostrarProducto(producto);
			}
		}
		else if (accion == "seleccionarProductoPorCodigo") {}
		else if (accion == "mostrarProducto") {}
		else if (accion == "seleccionarProducto") {}
		else if (accion == "obtenerProducto") {}
		else if (accion == "altaProducto") {}
		else if (accion == "seleccionarVendedor") {}
		else if (accion == "seleccionarProductoAEnviar") {}
		else if (accion == "seleccionarVenta") {}

		// ---- ControladorComentarios ----
		else if (accion == "elegirYBorrarComentario")
		{
			int id = leerInt("Id: ");
			contCom->elegirYBorrarComentario(id);
		}
		else if (accion == "elegirProducto") {
			int codigo = leerInt("Codigo: ");
			contCom->elegirProducto(codigo);
		} else if (accion == "seleccionarUsuarioCom")
		{
			string nick = leerStr("Nickname: ");
			contCom->seleccionarUsuarioCom(nick);
		}
		else if (accion == "introducirTexto")
		{
			string contenido = leerStr("Contenido: ");
			contCom->introducirTexto(contenido);
		}
		else if (accion == "listarComentarios")
		{
			set<DTComentario> comentarios = contCom->listarComentarios();
			cout << "Listando todos los comentarios" << endl;
			for (auto com : comentarios)
			{
				printf("%d", com.id);
				mostrarFecha(com.fecha);
				cout << com.contenido << endl;
			}
		}
		else if (accion == "ingresarRespuesta")
		{
			int id = leerInt("Id: ");
			string respuesta = leerStr("Respuesta: ");
			contCom->ingresarRespuesta(id, respuesta);
		}
		else if (accion == "confirmarDejarComentario")
		{
			contCom->confirmarDejarComentario();
		}

		// casos de uso
		else if (accion == "realizarCompra")
		{
			set<string> lc = contCompra->listarClientes();
			for (auto nick : lc)
			{
				cout << nick << endl;
			}
			string nickname = leerStr("Nickname del cliente: ");
			contCompra->seleccionarUsuario(nickname);
			set<DTProducto> dp = contProductos->listarProductosConId();
			// con este set verifico que los productos se agreguen solo una vez y que si se agregar ya todos ,no permita intentar agregar mas
			bool seguir = true;
			while (seguir)
			{
				cout << "Productos disponibles: " << endl;
				for (auto p : dp)
				{
					cout << "Nombre: " << p.nombre << "   Codigo: " << p.codigo << endl;
				}
				int idProd = leerInt("Ingrese id del producto: ");
				DTProducto prod(idProd, 0, 0, "", "", "");
				auto it = dp.find(prod);
				if (dp.count(prod) != 0)
				{
					int cantidad = leerInt("Ingrese cantidad a comprar: ");
					contCompra->seleccionarProducto(cantidad, idProd);
					dp.erase(prod);
				}
				else
				{
					cout << "Codigo incorrecto o ya producto ya agregado" << endl;
				}

				string resp = leerStr("¿Desea comprar otro producto? [y/n] ");
				while (!(resp == "y" || resp == "n"))
				{
					resp = leerStr("Respuesta no válida. ¿Desea comprar otro producto? [y/n] ");
				}
				seguir = (resp == "y");
			}
			DTDetalleCompra detalles = contCompra->devolverDetalles();
			// cout << "El monto final de la compra será: $" << detalles.montoFinal << endl;
			printf("El monto final de la compra será: %lf \n", detalles.montoFinal);
			cout << "Fecha de compra: ";
			mostrarFecha(detalles.fechaCompra);
			cout << "Producto/s a comprar: " << endl;
			for (auto dp : detalles.productos)
			{
				cout << dp.producto.getNombre() << " x " << dp.cantidad << endl;
			}
			string conf = leerStr("¿Desea confirmar la compra? [y/n] ");
			if (conf == "y")
			{
				contCompra->registrarCompra();
			}
			contCompra->finalizarCompra();
		}
		else if (accion == "")
		{
		}
		else if (accion == "")
		{
		}
		else if (accion == "salir" || accion == "")
		{
			continue;
		}
		else
		{
			cout << "Acción no reconocida: " << accion << endl;
		}
	}
	return 0;
}
