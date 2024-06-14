#include <iostream>
#include "./include/Datatypes/DTFecha.h"
#include "./include/Datatypes/DTAltaCliente.h"
#include "./include/controladorUsuarios.h"

using namespace std;

int main(int argc, char *argv[])
{
  ControladorUsuarios *controladorUsuarios = NULL;
  *controladorUsuarios = *controladorUsuarios->getInstance();
  string accion = "";

  while (accion != "salir")
  {
    cout << "Ingresar acción: ";
    cin >> accion;
    
    // ---- ControladorUsuarios ----
    if (accion == "ingresarDatosCliente")
    {
      // Solicitar datos al usuario
      string nickname, contrasenia, direccion, ciudad;
      int dia, mes, anio;

      cout << "Ingrese nickname: ";
      cin >> nickname;
      cout << "Ingrese contraseña: ";
      cin >> contrasenia;
      cout << "Ingrese fecha de nacimiento (dia mes anio): ";
      cin >> dia >> mes >> anio;
      cout << "Ingrese direccion: ";
      cin.ignore(); // Ignorar el salto de línea anterior
      getline(cin, direccion);
      cout << "Ingrese ciudad: ";
      getline(cin, ciudad);

      // Crear instancia de DTFecha
      //DTFecha fechaNac = DTFecha(dia, mes, anio);
      
      //DTAltaCliente datosCliente(nickname, DTFecha(dia, mes, anio), contrasenia, ciudad, direccion);
      controladorUsuarios->ingresarDatosCliente(DTAltaCliente(nickname, DTFecha(1, 1, 1), contrasenia, ciudad, direccion));
    }
    else if (accion == "ingresarDatosVendedor")
    {
    }
    else if (accion == "listarClientes")
    {
    }
    else if (accion == "listarVendedores")
    {
    }
    else if (accion == "listarUsuarios")
    {
    }
    else if (accion == "listarNoSuscritos")
    {
    }
    else if (accion == "obtenerListaComentarios")
    {
    }
    else if (accion == "obtenerCliente")
    {
    }
    else if (accion == "obtenerVendedor")
    {
    }
    else if (accion == "obtenerProdDeVendedor")
    {
    }
    else
    {
      cout << "Acción no reconocida" << endl;
    }
  }
  return 0;
}
