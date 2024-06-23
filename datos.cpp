#include "./include/Datatypes/DTAltaCliente.h"
#include "./include/Datatypes/DTAltaVendedor.h"
#include "./include/Datatypes/DTCompra.h"
#include "./include/Datatypes/DTDetalleCompra.h"
#include "include/Interface/IUsuario.h"
#include "include/Interface/IProducto.h"
#include "include/Interface/ISuscripcion.h"
#include "include/fabrica.h"
void cargarDatos()
{
    Fabrica *f = Fabrica::getFabrica();
    IUsuario *contUsuarios = f->getIUsuarios();
    IProducto *contProductos = f->getIProductos();
    IComentario *contComentarios = f->getIComentarios();

    DTAltaVendedor dataUS1 = DTAltaVendedor("ana23", DTFecha(15, 5, 1988), "qwer1234", "212345678001");
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

    // Productos
    // IProducto *contProductos = f->getIProductos();
    DTProducto dataPR1 = DTProducto(1, 50, 1400, "Camiseta Azul", "Camiseta de poliester, color azul", "R");
    DTProducto dataPR2 = DTProducto(2, 30, 40500, "Televisor LED", "Televisor LED 55 pulgadas", "E");
    DTProducto dataPR3 = DTProducto(3, 20, 699.99, "Chaqueta de Cuero", "Chaqueta de cuero, color negro", "R");
    DTProducto dataPR4 = DTProducto(4, 15, 1199.99, "Microondas Digital", "Microondas digital, 30L", "E");
    DTProducto dataPR5 = DTProducto(5, 40, 599.99, "Luz LED", "Luz Bluetooth LED", "O");
    DTProducto dataPR6 = DTProducto(6, 25, 60, "Pantalones Vaqueros", "Pantalones vaqueros, talla 32", "R");
    DTProducto dataPR7 = DTProducto(7, 35, 199.99, "Auriculares Bluetooth", "Auriculares bluetooth para celular", "O");
    DTProducto dataPR8 = DTProducto(8, 10, 15499, "Refrigerador", "Refrigerador de doble puerta", "E");
    DTProducto dataPR9 = DTProducto(9, 50, 23000, "Cafetera", "Cafetera de goteo programable", "E");
    DTProducto dataPR10 = DTProducto(10, 20, 5500, "Zapatillas Deportivas", "Zapatillas para correr, talla 42", "R");
    DTProducto dataPR11 = DTProducto(11, 30, 9000, "Mochila", "Mochila de viaje, 40L", "O");
    DTProducto dataPR12 = DTProducto(12, 25, 2534, "Plancha de Ropa", "Plancha a vapor, 1500W", "E");
    DTProducto dataPR13 = DTProducto(13, 50, 200, "Gorra", "Gorra para deportes, color rojo", "R");
    DTProducto dataPR14 = DTProducto(14, 15, 15000, "Tablet", "Tablet Android de 10 pulgadas", "E");
    DTProducto dataPR15 = DTProducto(15, 20, 150.50, "Reloj de Pared", "Reloj de pared vintage", "O");

    contProductos->altaProducto("carlos78", dataPR1);
    contProductos->altaProducto("ana23", dataPR2);
    contProductos->altaProducto("carlos78", dataPR3);
    contProductos->altaProducto("ana23", dataPR4);
    contProductos->altaProducto("diegom", dataPR5);
    contProductos->altaProducto("carlos78", dataPR6);
    contProductos->altaProducto("diegom", dataPR7);
    contProductos->altaProducto("ana23", dataPR8);
    contProductos->altaProducto("ana23", dataPR9);
    contProductos->altaProducto("carlos78", dataPR10);
    contProductos->altaProducto("carlos78", dataPR11);
    contProductos->altaProducto("diegom", dataPR12);
    contProductos->altaProducto("sofia25", dataPR13);
    contProductos->altaProducto("diegom", dataPR14);
    contProductos->altaProducto("sofia25", dataPR15);

    // Promociones
    IPromocion *contPromociones = f->getIPromociones();
    DTPromocion dataPM1 = DTPromocion("Casa nueva", "ana23", "Para que puedas ahorrar en la casa nueva", 30, DTFecha(25, 10, 2024));
    DTPromocion dataPM2 = DTPromocion("Fiesta", "carlos78", "Para que no te quedes sin ropa para las fiestas", 20, DTFecha(26, 10, 2024));
    DTPromocion dataPM3 = DTPromocion("Domotica", "diegom", "Para modernizar tu casa", 10, DTFecha(26, 10, 2024));
    DTPromocion dataPM4 = DTPromocion("Liquidacion", "diegom", "Hasta agotar stock", 10, DTFecha(26, 3, 2024));

    Promocion p1(dataPM1, "ana23");
    p1.agregarAPromo(contProductos->obtenerProducto(2), 1);
    p1.agregarAPromo(contProductos->obtenerProducto(4), 1);
    p1.agregarAPromo(contProductos->obtenerProducto(8), 1);
    Promocion p2(dataPM2, "carlos78");
    p2.agregarAPromo(contProductos->obtenerProducto(3), 2);
    p2.agregarAPromo(contProductos->obtenerProducto(6), 3);
    Promocion p3(dataPM3, "diegom");
    p3.agregarAPromo(contProductos->obtenerProducto(5), 2);
    Promocion p4(dataPM4, "diegom");
    p4.agregarAPromo(contProductos->obtenerProducto(14), 1);
    contPromociones->agregarPromocion(p1);
    contPromociones->agregarPromocion(p2);
    contPromociones->agregarPromocion(p3);
    contPromociones->agregarPromocion(p4);

    // Compras
    ICompra *contCompras = f->getICompras();
    DTDetalleCompra dataCO1 = DTDetalleCompra(1, 68389.293, DTFecha(1, 5, 2024), dataUS4.nickname);
    DTDetalleCompra dataCO2 = DTDetalleCompra(2, 599.99, DTFecha(1, 5, 2024), dataUS4.nickname);
    DTDetalleCompra dataCO3 = DTDetalleCompra(3, 150000, DTFecha(15, 4, 2024), dataUS5.nickname);
    DTDetalleCompra dataCO4 = DTDetalleCompra(4, 11734, DTFecha(25, 5, 2024), dataUS7.nickname);
    DTDetalleCompra dataCO5 = DTDetalleCompra(5, 1263.984, DTFecha(20, 5, 2024), dataUS4.nickname);
    DTDetalleCompra dataCO6 = DTDetalleCompra(6, 2800, DTFecha(12, 5, 2024), dataUS5.nickname);
    DTDetalleCompra dataCO7 = DTDetalleCompra(7, 4200, DTFecha(13, 5, 2024), dataUS7.nickname);
    DTDetalleCompra dataCO8 = DTDetalleCompra(8, 5600, DTFecha(14, 5, 2024), dataUS8.nickname);
    DTDetalleCompra dataCO9 = DTDetalleCompra(9, 7000, DTFecha(15, 5, 2024), dataUS9.nickname);

    Compra c1(dataCO1.fechaCompra, dataCO1.montoFinal, dataCO1.id, contUsuarios->obtenerCliente(dataCO1.cliente));
    c1.agregarProductosYEnvios(dataPR2.codigo, 2, true);
    c1.agregarProductosYEnvios(dataPR4.codigo, 1, false);
    c1.agregarProductosYEnvios(dataPR8.codigo, 1, false);
    c1.agregarPromocion(dataPM1.nombre);
    //contUsuarios->obtenerCliente(dataCO1.cliente)->agregarCompra(&c1);
    contCompras->cargarCompra(c1);
    Compra c2(dataCO2.fechaCompra, dataCO2.montoFinal, dataCO2.id, contUsuarios->obtenerCliente(dataCO2.cliente));
    c2.agregarProductosYEnvios(dataPR5.codigo, 1, true);
    //contUsuarios->obtenerCliente(dataCO2.cliente)->agregarCompra(&c2);
    contCompras->cargarCompra(c2);
    Compra c3(dataCO3.fechaCompra, dataCO3.montoFinal, dataCO3.id, contUsuarios->obtenerCliente(dataCO3.cliente));
    c3.agregarProductosYEnvios(dataPR14.codigo, 10, true);
    //contUsuarios->obtenerCliente(dataCO3.cliente)->agregarCompra(&c3);
    contCompras->cargarCompra(c3);
    Compra c4(dataCO4.fechaCompra, dataCO4.montoFinal, dataCO4.id, contUsuarios->obtenerCliente(dataCO4.cliente));
    c4.agregarProductosYEnvios(dataPR11.codigo, 1, true);
    c4.agregarProductosYEnvios(dataPR12.codigo, 1, true);
    c4.agregarProductosYEnvios(dataPR13.codigo, 1, true);
    //contUsuarios->obtenerCliente(dataCO4.cliente)->agregarCompra(&c4);
    contCompras->cargarCompra(c4);
    Compra c5(dataCO5.fechaCompra, dataCO5.montoFinal, dataCO5.id, contUsuarios->obtenerCliente(dataCO5.cliente));
    c5.agregarProductosYEnvios(dataPR3.codigo, 2, false);
    c5.agregarProductosYEnvios(dataPR6.codigo, 3, true);
    c5.agregarPromocion(dataPM2.nombre);
    //contUsuarios->obtenerCliente(dataCO5.cliente)->agregarCompra(&c5);
    contCompras->cargarCompra(c5);
    Compra c6(dataCO6.fechaCompra, dataCO6.montoFinal, dataCO6.id, contUsuarios->obtenerCliente(dataCO6.cliente));
    c6.agregarProductosYEnvios(dataPR1.codigo, 2, false);
    //contUsuarios->obtenerCliente(dataCO6.cliente)->agregarCompra(&c6);
    contCompras->cargarCompra(c6);
    Compra c7(dataCO7.fechaCompra, dataCO7.montoFinal, dataCO7.id, contUsuarios->obtenerCliente(dataCO7.cliente));
    c7.agregarProductosYEnvios(dataPR1.codigo, 3, true);
    //contUsuarios->obtenerCliente(dataCO7.cliente)->agregarCompra(&c7);
    contCompras->cargarCompra(c7);
    Compra c8(dataCO8.fechaCompra, dataCO8.montoFinal, dataCO8.id, contUsuarios->obtenerCliente(dataCO8.cliente));
    c8.agregarProductosYEnvios(dataPR1.codigo, 4, false);
    //contUsuarios->obtenerCliente(dataCO8.cliente)->agregarCompra(&c8);
    contCompras->cargarCompra(c8);
    Compra c9(dataCO9.fechaCompra, dataCO9.montoFinal, dataCO9.id, contUsuarios->obtenerCliente(dataCO9.cliente));
    c9.agregarProductosYEnvios(dataPR1.codigo, 5, false);
    //contUsuarios->obtenerCliente(dataCO9.cliente)->agregarCompra(&c9);
    contCompras->cargarCompra(c9);

    // Comentarios
    // IComentario *contComentarios = f->getIComentarios();
    DTComentario dataCM1 = DTComentario(1, "¿La camiseta azul esta disponible en talla M?", DTFecha(1, 6, 2024), 1);
    DTComentario dataCM2 = DTComentario(2, "Si, tenemos la camiseta azul en talla M.", DTFecha(1, 6, 2024), 1);
    DTComentario dataCM3 = DTComentario(3, "¿Es de buen material? Me preocupa la durabilidad.", DTFecha(1, 6, 2024), 1);
    DTComentario dataCM4 = DTComentario(4, "He comprado antes y la calidad es buena.", DTFecha(2, 6, 2024), 1);
    DTComentario dataCM5 = DTComentario(5, "¿Como es el ajuste? ¿Es ajustada o holgada?", DTFecha(2, 6, 2024), 1);
    DTComentario dataCM6 = DTComentario(6, "¿Cual es la resolucion del Televisor LED?", DTFecha(2, 6, 2024), 2);
    DTComentario dataCM7 = DTComentario(7, "El televisor LED tiene una resolucion de 4K UHD.", DTFecha(2, 6, 2024), 2);
    DTComentario dataCM8 = DTComentario(8, "¿Tiene soporte para HDR10?", DTFecha(3, 6, 2024), 2);
    DTComentario dataCM9 = DTComentario(9, "Si, soporta HDR10.", DTFecha(3, 6, 2024), 2);
    DTComentario dataCM10 = DTComentario(10, "¿La chaqueta de cuero es resistente al agua?", DTFecha(3, 6, 2024), 3);
    DTComentario dataCM11 = DTComentario(11, "No, la chaqueta de cuero no es resistente al agua.", DTFecha(3, 6, 2024), 3);
    DTComentario dataCM12 = DTComentario(12, "¿Viene en otros colores?", DTFecha(4, 6, 2024), 3);
    DTComentario dataCM13 = DTComentario(13, "Si, tambien esta disponible en marron.", DTFecha(4, 6, 2024), 3);
    DTComentario dataCM14 = DTComentario(14, "¿Es adecuada para climas frios?", DTFecha(4, 6, 2024), 3);
    DTComentario dataCM15 = DTComentario(15, "¿El microondas digital tiene funcion de descongelacion rapida?", DTFecha(4, 6, 2024), 4);
    DTComentario dataCM16 = DTComentario(16, "Si, el microondas digital incluye una funcion de descongelacion rapida.", DTFecha(4, 6, 2024), 4);
    DTComentario dataCM17 = DTComentario(17, "¿Cuantos niveles de potencia tiene?", DTFecha(5, 6, 2024), 4);
    DTComentario dataCM18 = DTComentario(18, "Tiene 10 niveles de potencia.", DTFecha(5, 6, 2024), 4);
    DTComentario dataCM19 = DTComentario(19, "¿Es facil de limpiar?", DTFecha(5, 6, 2024), 4);
    DTComentario dataCM20 = DTComentario(20, "¿La luz LED se puede controlar con una aplicacion movil?", DTFecha(6, 6, 2024), 5);
    DTComentario dataCM21 = DTComentario(21, "Si, la luz LED se puede controlar a traves de una aplicacion movil.", DTFecha(6, 6, 2024), 5);
    DTComentario dataCM22 = DTComentario(22, "¿Es compatible con Alexa o Google Home?", DTFecha(6, 6, 2024), 5);
    DTComentario dataCM23 = DTComentario(23, "Si, es compatible con ambos.", DTFecha(6, 6, 2024), 5);
    DTComentario dataCM24 = DTComentario(24, "¿Cuanto dura la bateria?", DTFecha(7, 6, 2024), 5);
    DTComentario dataCM25 = DTComentario(25, "¿La aplicacion movil es facil de usar?", DTFecha(7, 6, 2024), 5);
    contComentarios->cargarComentario(dataCM1, "juan87");
    contComentarios->cargarRespuesta(dataCM2, 1, "carlos78");
    contComentarios->cargarRespuesta(dataCM3, 2, "laura");
    contComentarios->cargarRespuesta(dataCM4, 3, "juan87");
    contComentarios->cargarComentario(dataCM5, "natalia");
    contComentarios->cargarComentario(dataCM6, "laura");
    contComentarios->cargarRespuesta(dataCM7, 6, "ana23");
    contComentarios->cargarComentario(dataCM8, "pablo10");
    contComentarios->cargarRespuesta(dataCM9, 8, "ana23");
    contComentarios->cargarComentario(dataCM10, "natalia");
    contComentarios->cargarRespuesta(dataCM11, 10, "carlos78");
    contComentarios->cargarRespuesta(dataCM12, 10, "laura");
    contComentarios->cargarRespuesta(dataCM13, 12, "carlos78");
    contComentarios->cargarRespuesta(dataCM14, 10, "roberto");
    contComentarios->cargarComentario(dataCM15, "pablo10");
    contComentarios->cargarRespuesta(dataCM16, 15, "ana23");
    contComentarios->cargarRespuesta(dataCM17, 15, "natalia");
    contComentarios->cargarRespuesta(dataCM18, 17, "ana23");
    contComentarios->cargarRespuesta(dataCM19, 15, "roberto");
    contComentarios->cargarComentario(dataCM20, "roberto");
    contComentarios->cargarRespuesta(dataCM21, 20, "diegom");
    contComentarios->cargarRespuesta(dataCM22, 20, "pablo10");
    contComentarios->cargarRespuesta(dataCM23, 22, "diegom");
    contComentarios->cargarRespuesta(dataCM24, 20, "natalia");
    contComentarios->cargarRespuesta(dataCM25, 20, "pablo10");
    // nuestros datos
}
