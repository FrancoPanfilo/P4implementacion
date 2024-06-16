#include <cstdio>

#include <iostream>
#include <set>
#include <string>

#include "./include/Datatypes/DTAltaCliente.h"
#include "./include/Datatypes/DTAltaVendedor.h"
#include "include/Interface/IComentario.h"
#include "include/Interface/IUsuario.h"
#include "include/fabrica.h"
#include "datos.cpp"
using namespace std;

// Controladores
//ControladorUsuarios *contUsuarios = ControladorUsuarios(); fabrica

string leerStr(string pregunta) {
	cout << pregunta;
	string respuesta;
	cin >> respuesta;
	return respuesta;
}

DTFecha leerDTFecha(string pregunta) {
	cout << pregunta;
	DTFecha respuesta = DTFecha();
	scanf("%d %d %d", &respuesta.dia, &respuesta.mes, &respuesta.anio);
	return respuesta;
}

void mostrarFecha(DTFecha fecha) {
	printf("%d/%d/%d", fecha.dia, fecha.mes, fecha.anio);
}

int leerInt(string pregunta) {
	cout << pregunta;
	int respuesta;
	scanf("%d", &respuesta);
	return respuesta;
}

int main(int argc, char *argv[]) {

	Fabrica *f = Fabrica::getFabrica();
	IUsuario *contUsuarios = f->getIUsuarios();
	IComentario *contCom = f->getIComentarios();	

	string accion = "";

	while (accion != "salir") {
		cout << "Ingresar acción: ";
		cin >> accion;

		// ---- ControladorUsuarios ----
		if (accion == "ingresarDatosCliente") {
			DTAltaCliente data = DTAltaCliente();
			data.nickname = leerStr("Nickname: ");
			data.contrasenia = leerStr("Contrasenia: ");
			data.fechaNac = leerDTFecha("Fecha de nacimiento: ");
			data.ciudad = leerStr("Ciudad: ");
			data.direccion = leerStr("Direccion: ");

			contUsuarios->ingresarDatosCliente(data);

		} else if (accion == "ingresarDatosVendedor") {
			DTAltaVendedor data = DTAltaVendedor();
			data.nickname = leerStr("Nickname: ");
			data.contrasenia = leerStr("Contrasenia: ");
			data.fechaNac = leerDTFecha("Fecha de nacimiento: ");
			data.RUT = leerInt("RUT: ");

			contUsuarios->ingresarDatosVendedor(data);

		} else if (accion == "listarClientes") {
			set<string> clientes = contUsuarios->listarClientes();
			for (auto nick : clientes) {
				cout << nick << endl;
			}
		} else if (accion == "listarVendedores") {
			set<string> vendedores = contUsuarios->listarVendedores();
			for (auto nick : vendedores) {
				cout << nick << endl;
			}
		} else if (accion == "listarUsuarios") {
			set<string> usuarios = contUsuarios->listarUsuarios();
			for (auto nick : usuarios) {
				cout << nick << endl;
			}
		} else if (accion == "listarNoSuscritos") {
			string nickname = leerStr("Vendedor: ");
			set<string> noSusc = contUsuarios->listarNoSuscritos(nickname);
			for (auto nick : noSusc) {
				cout << nick << endl;
			}
		} else if (accion == "obtenerListaComentarios") {
			string nickname = leerStr("Usuario: ");
			set<DTComentario> comentarios = contUsuarios->listarComentarios(nickname);
			for (auto com : comentarios) {
				printf("%d", com.id);
				mostrarFecha(com.fecha);
				cout << com.contenido << endl;	
			}

		// } else if (accion == "obtenerCliente") {
		// } else if (accion == "obtenerVendedor") {
		} else if (accion == "prodDeVendedor") {

		} else if (accion == "seleccionarNickname") {

		}
		else if (accion == "listarProductosVendedor") {

		}
		else if (accion == "listarPromocionesVendedor") {

		}
		else if (accion == "listarInfoVendedor") {

		}
		else if (accion == "listarComprasCliente") {

		}
		else if (accion == "listarInfoCliente") {

		}
		else if (accion == "finalizarExpediente") {
				
		} 
		// ---- ControladorComentarios ----
		else if (accion == "elegirYBorrarComentario") {
			int id = leerInt("Id: ");
			contCom->elegirYBorrarComentario(id);
		}
		else if (accion == "seleccionarUsuarioCom") {
			string nick = leerStr("Nickname: ");
			contCom->seleccionarUsuarioCom(nick);		
		}
		else if (accion == "introducirTexto") {
			string contenido = leerStr("Contenido: ");
			contCom->introducirTexto(contenido);		
		}
		else if (accion == "listarComentarios") {
			set<DTComentario> comentarios = contCom->listarComentarios();
			for (auto com : comentarios) {
				printf("%d", com.id);
				mostrarFecha(com.fecha);
				cout << com.contenido << endl;	
			}
		}
		else if (accion == "ingresarRespuesta") {
			int id = leerInt("Id: ");
			string respuesta = leerStr("Respuesta: ");
			contCom->ingresarRespuesta(id, respuesta);		
		}
		else if (accion == "confirmarDejarComentario") {
			contCom->confirmarDejarComentario();

		} else if (accion == "salir" || accion == "") {
			continue;
		} else {
		  cout << "Acción no reconocida: " << accion << endl;
		}
	}
	return 0;
}

