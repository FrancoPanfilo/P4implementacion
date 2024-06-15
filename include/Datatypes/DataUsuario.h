#ifndef DATA_USUARIO_H
#define DATA_USUARIO_H

#include <string>
#include "./DTFecha.h"

class DataUsuario {
public:
	DTFecha fechaNac;
	std::string nickname;
};

#endif // !DATA_USUARIO_H
