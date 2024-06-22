#ifndef ENVIOS_PENDIENTES_H
#define ENVIOS_PENDIENTES_H

#include <string>
#include "DTFecha.h"

using namespace std;

class EnviosPendientes {
	public:
		int id;
		string nickname;
		DTFecha fecha;
		EnviosPendientes(int, string, DTFecha);
		~EnviosPendientes();
		bool operator<(const EnviosPendientes& otro) const;
};

#endif // !ENVIOS_PENDIENTES_H
