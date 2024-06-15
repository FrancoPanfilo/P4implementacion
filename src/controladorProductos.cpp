// // File: controladorProductos.cpp

// #include "../include/controladorProductos.h"

// ControladorProductos *ControladorProductos::instance = nullptr;

// ControladorProductos::ControladorProductos() {}

// ControladorProductos::~ControladorProductos() {}

// ControladorProductos *ControladorProductos::getInstance()
// {
//     if (instance == nullptr)
//     {
//         instance = new ControladorProductos();
//     }
//     return instance;
// }

// std::set<DTProducto> ControladorProductos::listarProductos()
// {
//     std::set<DTProducto> dtProductos;
//     for (auto producto : productos)
//     {
//         dtProductos.insert(DTProducto(
//             producto.second.getCodigo(),
//             producto.second.getStock(),
//             producto.second.getPrecio(),
//             producto.second.getNombre(),
//             producto.second.getDescripcion(),
//             producto.second.getTipo()
//         ));
//     }
//     return dtProductos;
// }

// int ControladorProductos::seleccionarProducto(int codigo, int cantidad)
// {
//     for (auto producto : productos)
//     {
//         if (producto.second.getCodigo() == codigo)
//         {
//             if (producto.second.getStock() >= cantidad)
//             {
//                 // TODO
//                 return 0; // Operación exitosa
//             }
//             else
//             {
//                 return -2; // No hay suficiente stock
//             }
//         }
//     }
//     return -1; // Producto no encontrado
// }


// void ControladorProductos::agregarAPromo(String nombrePromo, int codigo, int cantidad)
// {
//     for (auto producto : productos)
//     {
//         if (producto.second.getCodigo() == codigo)
//         {
//             if (producto.second.getStock() >= cantidad)
//             {
//                 producto.second.agregarAPromo(nombrePromo, cantidad);
//                 return;
//             }
//         }
//     }
// }

// Producto ControladorProductos::obtenerProducto(int codigo)
// {
//     for (auto producto : productos)
//     {
//         if (producto.second.getCodigo() == codigo)
//         {
//             return producto.second;
//         }
//     }
// }