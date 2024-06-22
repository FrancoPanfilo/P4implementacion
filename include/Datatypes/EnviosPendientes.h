#ifndef ENVIOS_PENDIENTES_H
#define ENVIOS_PENDIENTES_H

#include <string>
#include "DTFecha.h"

class EnviosPendientes {
	public:
		std::string nickname;
		DTFecha fecha;
		EnviosPendientes(string, DTFecha);
		~EnviosPendientes();
};

#endif // !ENVIOS_PENDIENTES_H
