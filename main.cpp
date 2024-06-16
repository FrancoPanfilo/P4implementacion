#include <cstdio>
#include <iostream>
#include <set>
#include <string>

#include "./include/Datatypes/DTAltaCliente.h"
#include "./include/Datatypes/DTAltaVendedor.h"
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
	scanf("%d %d %d", &respuesta.anio, &respuesta.mes, &respuesta.dia);
	return respuesta;
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
		data.RUT = leerStr("RUT: ");

		contUsuarios->ingresarDatosVendedor(data);

	} else if (accion == "listarClientes") {
		set<string> clientes = contUsuarios->listarClientes();
		for (auto nick : clientes) {
			cout << nick << endl;
		}
	} else if (accion == "listarVendedores") {
	} else if (accion == "listarUsuarios") {
	} else if (accion == "listarNoSuscritos") {
	} else if (accion == "obtenerListaComentarios") {
	} else if (accion == "obtenerCliente") {
	} else if (accion == "obtenerVendedor") {
	} else if (accion == "obtenerProdDeVendedor") {
	} else if (accion == "salir" || accion == "") {
		continue;
	} else {
	  cout << "Acción no reconocida: " << accion << endl;
	}
}
return 0;
}

