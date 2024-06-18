#ifndef DT_VENDEDOR
#define DT_VENDEDOR
#include "./DTFecha.h"

#include <string>
class DTVendedor {
public:
	std::string nickname;
	DTFecha fechaNac;
	std::string RUT;
	DTVendedor(string nickname, DTFecha fechaNac, string RUT);
	~DTVendedor();
};

#endif // !DT_VENDEDOR
