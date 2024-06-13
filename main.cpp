#include <iostream>
#include "./include/Datatypes/DTAltaCliente.h"

using namespace std;

int main(int argc, char *argv[]) {
  string accion = "";

  while (accion != "salir") {
    cout << "Ingresar acción: ";
    cin >> accion;

	// ---- ControladorUsuarios ----
    if (accion == "ingresarDatosCliente") {
		
    } else if (accion == "ingresarDatosVendedor") {
    } else if (accion == "listarClientes") {
    } else if (accion == "listarVendedores") {
    } else if (accion == "listarUsuarios") {
    } else if (accion == "listarNoSuscritos") {
    } else if (accion == "obtenerListaComentarios") {
    } else if (accion == "obtenerCliente") {
    } else if (accion == "obtenerVendedor") {
    } else if (accion == "obtenerProdDeVendedor") {
    } else {
      cout << "Acción no reconocida" << endl;
    }
  }
  return 0;
}
