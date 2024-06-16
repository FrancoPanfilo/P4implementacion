#include "./include/Datatypes/DTAltaCliente.h"
#include "./include/Datatypes/DTAltaVendedor.h"
#include "include/Interface/IUsuario.h"
#include "include/fabrica.h"
void cargarDatos()
{
    Fabrica *f = Fabrica::getFabrica();
    IUsuario *contUsuarios = f->getIUsuarios();
    DTAltaVendedor dataUS1 = DTAltaVendedor("ana23", DTFecha(13, 5, 1988), "qwer1234", "212345678001");
    DTAltaVendedor dataUS2 = DTAltaVendedor("carlos78", DTFecha(18, 6, 1986), "asdfghj", "356789012345");
    DTAltaVendedor dataUS3 = DTAltaVendedor("diegom", DTFecha(28, 7, 1993), "zxcvbn", "190123456789");
    DTAltaVendedor dataUS6 = DTAltaVendedor("maria01", DTFecha(25, 3, 1985), "5tgb6yhn", "321098765432");
    DTAltaVendedor dataUS10 = DTAltaVendedor("sofia25", DTFecha(7, 12, 1983), "1234asdf", "445678901234");
    DTAltaCliente dataUS4 = DTAltaCliente("juan87", DTFecha(20, 10, 1992), "1qaz2wsx", "Melo", "Av. 18 de Julio 456");
    DTAltaCliente dataUS5 = DTAltaCliente("laura", DTFecha(22, 9, 1979), "3edc4rfv", "Montevideo", "Rondeau 1617");
    DTAltaCliente dataUS7 = DTAltaCliente("natalia", DTFecha(14, 4, 1982), "poiuyt", "Salto", "Paysandu 2021");
    DTAltaCliente dataUS8 = DTAltaCliente("pablo10", DTFecha(30, 11, 1995), "lkjhgv", "Mercedes", "Av. Rivera 1819");
    DTAltaCliente dataUS9 = DTAltaCliente("roberto", DTFecha(12, 8, 1990), "mnbvcx", "Montevideo", "Av. Brasil 1011");

    contUsuarios->ingresarDatosVendedor(dataUS1);
    contUsuarios->ingresarDatosVendedor(dataUS2);
    contUsuarios->ingresarDatosVendedor(dataUS3);
    contUsuarios->ingresarDatosVendedor(dataUS6);
    contUsuarios->ingresarDatosVendedor(dataUS10);
    contUsuarios->ingresarDatosCliente(dataUS4);
    contUsuarios->ingresarDatosCliente(dataUS5);
    contUsuarios->ingresarDatosCliente(dataUS7);
    contUsuarios->ingresarDatosCliente(dataUS8);
    contUsuarios->ingresarDatosCliente(dataUS9);
}