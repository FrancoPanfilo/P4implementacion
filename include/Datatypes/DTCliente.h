#ifndef DT_CLIENTE
#define DT_CLIENTE
#include "./DTFecha.h"

#include <string>
class DTCliente {
public:
	std::string nickname;
	DTFecha fechaNac;
	std::string ciudad;
	std::string direccion;
	DTCliente(string nickname, DTFecha fechaNac, string ciudad, string direccion);
	~DTCliente();
};

#endif // !DT_CLIENTE
