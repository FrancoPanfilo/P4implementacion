#include <cstdio>

#include <iostream>
#include <istream>
#include <set>
#include <string>

#include "./include/Datatypes/DTAltaCliente.h"
#include "./include/Datatypes/DTAltaVendedor.h"
#include "./include/Datatypes/EnviosPendientes.h"
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
	string respuesta;
	cout << pregunta << "\n";
	// cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
	getline(cin >> ws, respuesta);
	return respuesta;
}

DTFecha leerDTFecha(string pregunta)
{
	cout << pregunta;
	DTFecha respuesta = DTFecha();
	scanf("%d %d %d", &respuesta.dia, &respuesta.mes, &respuesta.anio);
	cout << endl;

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
	cout << endl;
	return respuesta;
}

double leerDouble(string pregunta)
{
	cout << pregunta;
	double respuesta;
	scanf("%lf", &respuesta);
	cout << endl;

	return respuesta;
}

bool pedirConfirmacion(string pregunta)
{
	string respuesta = "";
	while (respuesta != "y" && respuesta != "n")
	{
		respuesta = leerStr(pregunta);
	};
	return respuesta == "y";
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

	int indice = 1;

	while (indice != 0)
	{
		cout << "Ingresar indice caso de uso " << endl;
		cout << "1--altaDeProducto" << endl;
		cout << "2--altaDeUsuario" << endl;
		cout << "3--consultaDeNotificaciones" << endl;
		cout << "4--consultarProducto" << endl;
		cout << "5--consultarPromocion" << endl;
		cout << "6--crearPromocion" << endl;
		cout << "7--dejarComentario" << endl;
		cout << "8--eliminarComentario" << endl;
		cout << "9--eliminarSuscripciones" << endl;
		cout << "10--enviarProducto" << endl;
		cout << "11--expedienteDeUsuario" << endl;
		cout << "12--listadoDeUsuarios" << endl;
		cout << "13--realizarCompra" << endl;
		cout << "14--suscribirseANotificaciones" << endl;
		cout << "-------------" << endl
			 << endl;
		indice = leerInt("Ingrese el indice del caso de uso: ");
		string accion;

		if (indice == 0)
		{
			continue;
		}
		// else if (indice == "15")
		// {
		// 	accion = " Uso Interno ";
		// }

		else if (indice == 1)
		{
			cout << "altaDeProducto" << endl;
			DTProducto p;
			string n = leerStr("Ingrese el nickname del vendedor: ");
			// TODO: creo q el código no se debería poder elegir
			// p.codigo = leerInt("Ingrese el codigo: ");
			// cin.ignore();
			p.nombre = leerStr("Ingrese el nombre: ");
			p.descripcion = leerStr("Describa brevemente el producto: ");
			p.stock = leerInt("Ingrese la cantidad en stock: ");
			p.precio = leerDouble("Ingrese el precio: ");
			// cin.ignore();
			p.tipo = leerStr("Ingrese el tipo de producto [R , E , O]: ");
			contProductos->altaProducto(n, p);
		}
		else if (indice == 2)
		{
			cout << "altaDeUsuario" << endl;
			string t = leerStr("¿Es un cliente o un vendedor? [ c / v]");
			while (t != "v" && t != "c")
			{
				cout << "TEXTO INCORRECTO" << endl;
				t = leerStr("¿Es un cliente o un vendedor? [ c / v]");
			}
			if (t == "v")
			{
				DTAltaVendedor v;
				v.nickname = leerStr("Ingrese Nickname:  ");
				v.contrasenia = leerStr("Ingrese contraseña: ");
				v.fechaNac = leerDTFecha("Ingrese fecha de nacimiento [dia mes anio]:  ");
				// cin.ignore();
				v.RUT = leerStr("Ingrese RUT [12 digitos]:  ");
				contUsuarios->ingresarDatosVendedor(v);
				cout << "Vendedor ingresado correctamente " << endl;
			}
			else
			{
				DTAltaCliente data = DTAltaCliente();
				data.nickname = leerStr("Nickname: ");
				data.contrasenia = leerStr("Contrasenia: ");
				data.fechaNac = leerDTFecha("Fecha de nacimiento: ");
				// cin.ignore();
				data.ciudad = leerStr("Ciudad: ");
				data.direccion = leerStr("Direccion: ");
				contUsuarios->ingresarDatosCliente(data);
				cout << "Cliente ingresado correctamente " << endl;
			}
		}
		else if (indice == 3)
		{
			cout << "consultaDeNotificaciones" << endl;
			string n = leerStr("Ingrese nickname del cliente: ");
			set<DTNotificacion> nP = contSuscripciones->consultarNotificacionesRecibidas(n);
			for (auto n : nP)
			{
				cout << n.nombreVendedor << " publico la promocion " << n.nombrePromo << " con los productos identificados por los siguientes codigos: " << endl;
				for (auto p : n.productos)
				{
					cout << p << endl;
				}
				cout << endl;
			}
			contSuscripciones->eliminarNotificaciones();
		}
		else if (indice == 4)
		{
			cout << "consultarProducto" << endl;
			set<DTProducto> productos = contProductos->listarProductosConId();
			cout << endl;
			for (auto p : productos)
			{
				cout << "Nombre: " << p.nombre << "  Codigo: " << p.codigo << endl;
			}
			int id = leerInt("Ingrese el codigo del producto que desea consultar: ");
			Producto p = contProductos->obtenerProducto(id);
			cout << "El producto seleccionado es " << p.getNombre() << " su vendedor lo describe de la siguiente forma " << p.getDescripcion() << ". Tiene un valor de " << p.getPrecio() << " y en este momento hay " << p.getStock() << " unidades en stock" << endl;
		}
		else if (indice == 5)
		{
			cout << "consultarPromocion" << endl;
			set<DTPromocion> dP = contPromociones->obtenerPromocionesVigentes();
			for (auto p : dP)
			{
				cout << "Nombre: " << p.nombre << "   Vendedor: " << p.vendedor << "  Descripcion: " << p.descripcion << endl;
			}
			string n = leerStr("Ingrese el nombre de la promocion que desea consultar:  ");
			DTProductosYVendedor p = contPromociones->seleccionarPromocionPorNombre(n);
			cout << "La Promocion " << n << " tiene los siguientes productos: " << endl;
			for (auto pr : p.productos)
			{
				cout << "Nombre: " << pr.nombre << "  Codigo: " << pr.codigo << endl;
			}
			cout << "Estos productos son vendidos por " << p.vendedor.getNickname() << ".  Que tiene como RUT: " << p.vendedor.getRUT() << endl;
			cout << endl;
		}
		else if (indice == 6)
		{
			cout << "crearPromocion" << endl;
			// ingresarDatosPromocion
			// cin.ignore();
			string nombre = leerStr("Nombre: ");
			// cin.ignore();
			string descripcion = leerStr("Descripcion: ");
			int descuento = leerInt("Descuento: ");
			DTFecha fechaVenc = leerDTFecha("Vencimiento: ");
			contPromociones->ingresarDatosPromocion(nombre, descripcion, descuento, fechaVenc);

			// listarVendedores
			set<string> vendedores = contUsuarios->listarVendedores();
			for (auto nick : vendedores)
			{
				cout << nick << endl;
			}
			// seleccionarNickname
			string nick = leerStr("Nickname: ");
			contPromociones->seleccionarNickname(nick);

			// obtenerProductosAsociados
			set<DTProducto> dtproductos = contPromociones->obtenerProductosAsociados();
			for (auto p : dtproductos)
			{
				mostrarProducto(p);
			}
			// agregarProductoAPromocion
			bool seguir = true;
			while (seguir)
			{
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
			// confirmarCrearPromocion
			contPromociones->confirmarCrearPromocion();

		}
		else if (indice == 7)
		{
			cout << "dejarComentario" << endl;
			// listarProductosConId
			set<DTProducto> productos = contProductos->listarProductosConId();
			for (auto producto : productos)
			{
				mostrarProducto(producto);
			}
			// elegirProducto
			int codigo = leerInt("Elegir codigo: ");
			contCom->elegirProducto(codigo);
			// listarUsuarios
			set<string> usuarios = contUsuarios->listarUsuarios();
			for (auto nick : usuarios)
			{
				cout << nick << endl;
			}
			// seleccionarUsuarioCom
			// cin.ignore();
			string nick = leerStr("Elegir usuario: ");
			contCom->seleccionarUsuarioCom(nick);

			bool esRespuesta = pedirConfirmacion("Escribir respuesta? [y/n]");

			if (esRespuesta)
			{
				// listarComentarios
				set<DTComentario> comentarios = contCom->listarComentarios();
				cout << "Listando todos los comentarios" << endl;
				for (auto com : comentarios)
				{
					printf("%d", com.id);
					mostrarFecha(com.fecha);
					cout << com.contenido << endl;
				}
				int id = leerInt("Responder a: ");
				// cin.ignore();
				string respuesta = leerStr("Texto: ");
				contCom->ingresarRespuesta(id, respuesta);
			}
			else
			{
				string contenido = leerStr("Contenido: ");
				contCom->introducirTexto(contenido);
			}
			contCom->confirmarDejarComentario();
			cout << "Comentario creado" << endl;
		}
		else if (indice == 8)
		{
			cout << "eliminarComentario" << endl;
			// listarComentarios
			string nickname = leerStr("Usuario: ");
			set<DTComentario> comentarios = contUsuarios->listarComentarios(nickname);
			for (auto com : comentarios)
			{
				printf("%d", com.id);
				mostrarFecha(com.fecha);
				cout << com.contenido << endl;
			}
			// elegirYBorrarComentario
			int id = leerInt("Id a borrar: ");
			contCom->elegirYBorrarComentario(id);

			cout << "Comentario borrado" << endl;
		}
		else if (indice == 9)
		{
			cout << "eliminarSuscripciones" << endl;
			cout << "Clientes: " << endl;
			set<string> lc = contCompra->listarClientes();
			for (auto nick : lc)
			{
				cout << nick << endl;
			}
			string nickname = leerStr("Cliente: ");
			set<string> listaSus = contSuscripciones->listarVendedoresSuscritos(nickname);
			for (auto s : listaSus)
			{
				cout << s << endl;
			}
			bool seguir = (size(listaSus) != 0);
			if (!seguir)
			{
				cout << "El cliente no está suscrito a ningún vendedor." << endl;
			}
			while (seguir)
			{
				if (size(listaSus) != 0)
				{
					string nickV = leerStr("Ingrese la suscripcion a eliminar: ");
					if (listaSus.count(nickV) == 0)
					{
						cout << "El cliente ya no está suscrito a este vendedor." << endl;
					}
					else
					{
						contSuscripciones->eliminarSuscriptor(nickV);
						listaSus.erase(nickV);
					}
					string resp = leerStr("¿Desea seguir eliminando suscripciones? [y/n]");
					while (!(resp == "y" || resp == "n"))
					{
						resp = leerStr("Respuesta no válida. ¿Desea seguir eliminando suscripciones? [y/n]");
					}
					seguir = (resp == "y");
				}
				else
				{
					cout << "El cliente ya no tiene suscripciones." << endl;
					seguir = false;
				}
			}
		}
		else if (indice == 10)
		{
			cout << "enviarProducto" << endl;
			cout << "Vendedores:" << endl;
			set<string> lv = contUsuarios->listarVendedores();
			for (auto nick : lv)
			{
				cout << nick << endl;
			}
			string vendedor = leerStr("Vendedor: ");
			Vendedor *v = contUsuarios->obtenerVendedor(vendedor);
			set<DTProducto> prod = v->getProductosAsociados();
			set<DTDetalleCompra> c = contCompra->obtenerCompras();
			set<DTProducto> res;
			bool pendienteEnvio;
			for (auto p : prod)
			{
				for (auto co : c)
				{
					pendienteEnvio = !co.productosEnvio.at(p.codigo);
					if (pendienteEnvio)
					{
						res.insert(p);
						break;
					}
				}
			}
			for (auto pe : res)
			{
				cout << pe.codigo << " " << pe.nombre << endl;
			}
			int prodAEnviar = leerInt("Seleccione la id del producto a enviar: ");
			set<EnviosPendientes> env = contProductos->seleccionarProductoAEnviar(prodAEnviar);
			cout << "Lista de compras en las que dicho producto aún no se ha enviado: " << endl;
			for (auto ev : env)
			{
				cout << "Compra de " << ev.nickname << "realizada el día ";
				mostrarFecha(ev.fecha);
			}
			string nick = leerStr("Seleccione el cliente: ");
			DTFecha f = leerDTFecha("Seleccione la fecha de compra: ");
			Cliente *cl = contUsuarios->obtenerCliente(nick);
			map<int, Compra *> listaC = cl->getCompras();
			for (auto comp : listaC)
			{
				DTFecha fechaC = comp.second->getFechaCompra();
				map<int, bool> enviosC = comp.second->getEnvios();
				if (fechaC.anio == f.anio && fechaC.mes == f.mes && fechaC.dia == f.dia && enviosC.count(prodAEnviar) == 1 && !enviosC.at(prodAEnviar))
				{
					enviosC.at(prodAEnviar) = true;
				}
			}
		}
		else if (indice == 11)
		{
			cout << "expedienteDeUsuario" << endl;
			string t = leerStr("¿Es un cliente o un vendedor? [ c / v]");
			string nickname;

			while (t != "v" && t != "c")
			{
				cout << "TEXTO INCORRECTO" << endl;
				t = leerStr("¿Es un cliente o un vendedor? [ c / v]");
			}
			if (t == "v")
			{
				set<string> lV = contUsuarios->listarVendedores();
				for (auto v : lV)
				{
					cout << v << endl;
				}
				cout << endl;
				nickname = leerStr("Ingrese el nickname del Vendedor: ");
				contUsuarios->seleccionarNickname(nickname);
				set<DTProducto> dP = contUsuarios->listarProductosVendedor();
				set<DTPromocion> dProm = contUsuarios->listarPromocionesVendedor();
				cout << "El vendedor " << nickname << " tiene los siguientes productos en venta: " << endl;
				for (auto p : dP)
				{
					cout << "Nombre: " << p.nombre << "  Descripcion: " << p.descripcion << " . Su codigo es " << p.codigo << endl;
				}
				cout << endl
					 << "El vendedor " << nickname << " tiene las siguientes promociones creadas" << endl;
				for (auto p : dProm)
				{
					cout << "Nombre: " << p.nombre << "  Descripcion: " << p.descripcion << " vence en la fecha ";
					mostrarFecha(p.fechaVencimiento);
					cout << endl;
				}
			}
			else
			{
				nickname = leerStr("Ingrese el nickname del Cliente: ");
				contUsuarios->seleccionarNickname(nickname);
				Cliente *c = contUsuarios->obtenerCliente(nickname);
				cout << "Nombre: " << nickname << " Direccion:" << c->getDireccion() << endl;
				set<DTDetalleCompra> dC = contUsuarios->listarComprasCliente();
				for (auto c : dC)
				{
					cout << "Id: " << c.id << "  Monto final: " << c.montoFinal << "  Fecha: ";
					mostrarFecha(c.fechaCompra);
					cout << endl;
				}
			}
		}
		else if (indice == 12)
		{
			cout << "listadoDeUsuarios" << endl;
			set<string> usuarios = contUsuarios->listarUsuarios();
			for (auto nick : usuarios)
			{
				cout << nick << endl;
			}
		}
		else if (indice == 13)
		{
			cout << "realizarCompra" << endl;
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
					cout << "Codigo incorrecto o producto ya agregado" << endl;
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
		else if (indice == 14)
		{
			cout << "suscribirseANotificaciones" << endl;
			cout << "Clientes: " << endl;
			set<string> lc = contCompra->listarClientes();
			for (auto nick : lc)
			{
				cout << nick << endl;
			}
			string nickname = leerStr("Cliente: ");
			cout << "Vendedores a los que " << nickname << " no está suscrito:" << endl;
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
				if (sLista.count(vendedor) == 0)
				{
					contSuscripciones->agregarSuscripcion(vendedor);
					sLista.insert(vendedor);
					noSusc.erase(vendedor);
				}
				else
				{
					cout << "Suscripción ya agregada anteriormente. " << endl;
				}
				string resp = leerStr("¿Desea seguir agregando suscripciones? [y/n] ");
				while (!(resp == "y" || resp == "n"))
				{
					resp = leerStr("Respuesta no válida. ¿Desea seguir agregando suscripciones? [y/n] ");
				}
				seguir = (resp == "y");
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
		else if (indice == 15)
		{
			string accion = " ";
			while (accion != "salir" && accion != "")
			{
				accion = leerStr("Ingrese funcion uso interno:   ");
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
				else if (accion == "seleccionarProductoCompra")
				{
					bool seguir = true;
					while (seguir)
					{
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
					// cout << "El monto final de la compra será: $" << detalles.montoFinal << endl;
					printf("El monto final de la compra será: %lf \n", detalles.montoFinal);
					cout << "Fecha de compra: ";
					mostrarFecha(detalles.fechaCompra);
					cout << "Producto/s a comprar: " << endl;
					for (auto dp : detalles.productos)
					{
						cout << dp.producto.getNombre() << " x " << dp.cantidad << endl;
					}
				}
				else if (accion == "confirmarCompra")
				{
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
				else if (accion == "ingresarDatosPromocion")
				{
					string nombre = leerStr("Nombre: ");
					string descripcion = leerStr("Descripcion: ");
					int descuento = leerInt("Descuento: ");
					DTFecha fechaVenc = leerDTFecha("Vencimiento: ");
					contPromociones->ingresarDatosPromocion(nombre, descripcion, descuento, fechaVenc);
				}
				else if (accion == "obtenerNicknames")
				{
					set<string> vendedores = contPromociones->obtenerNicknames();
					for (auto nick : vendedores)
					{
						cout << nick << endl;
					}
				}
				else if (accion == "seleccionarNickname")
				{
					string nick = leerStr("Nickname: ");
					contPromociones->seleccionarNickname(nick);
				}
				else if (accion == "obtenerProductosAsociados")
				{
					set<DTProducto> dtproductos = contPromociones->obtenerProductosAsociados();
					for (auto p : dtproductos)
					{
						mostrarProducto(p);
					}
				}
				else if (accion == "agregarProductoAPromocion")
				{
					bool seguir = true;
					while (seguir)
					{
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
				}
				else if (accion == "confirmarCrearPromocion")
				{
					contPromociones->confirmarCrearPromocion();
				}
				else if (accion == "obtenerPromocionesVigentes")
				{
					set<DTPromocion> promosVigentes = contPromociones->obtenerPromocionesVigentes();
					for (auto promo : promosVigentes)
					{
						cout << promo.nombre << " (-" << promo.descuento << "%): " << promo.descripcion << endl;
						cout << "Vendida por: " << promo.vendedor << endl;
						cout << "Hasta ";
						mostrarFecha(promo.fechaVencimiento);
					}
				}
				else if (accion == "seleccionarPromocionPorNombre")
				{
					string nombre = leerStr("Nombre de la promocion: ");
					DTProductosYVendedor pyv = contPromociones->seleccionarPromocionPorNombre(nombre);
					cout << "Vendedor: " << pyv.vendedor.getNickname() << endl;
					for (auto producto : pyv.productos)
					{
						mostrarProducto(producto);
					}
				}
				// ---- ControladorProductos ----

				else if (accion == "listarProductosConId")
				{
					set<DTProducto> productos = contProductos->listarProductosConId();
					for (auto producto : productos)
					{
						mostrarProducto(producto);
					}
				}
				else if (accion == "seleccionarProductoPorCodigo")
				{
				}
				else if (accion == "mostrarProducto")
				{
				}
				else if (accion == "seleccionarProducto")
				{
				}
				else if (accion == "obtenerProducto")
				{
				}
				else if (accion == "altaProducto")
				{
				}
				else if (accion == "seleccionarVendedor")
				{
				}
				else if (accion == "seleccionarProductoAEnviar")
				{
				}
				else if (accion == "seleccionarVenta")
				{
				}

				// ---- ControladorComentarios ----
				else if (accion == "elegirYBorrarComentario")
				{
					int id = leerInt("Id: ");
					contCom->elegirYBorrarComentario(id);
				}
				else if (accion == "elegirProducto")
				{
					int codigo = leerInt("Codigo: ");
					contCom->elegirProducto(codigo);
				}
				else if (accion == "seleccionarUsuarioCom")
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
				else
				{
					cout << "Accion incorrecta " << accion << endl;
				}
			}
		}
		else
		{
			cout << "Indice incorrecto " << indice << endl;
		}
	}
	return 0;
}
