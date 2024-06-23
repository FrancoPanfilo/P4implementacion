#ifndef DT_VENDEDOR
#define DT_VENDEDOR
#include "./DTFecha.h"

#include <string>
using namespace std;

class DTVendedor {
public:
	string nickname;
	DTFecha fechaNac;
	string RUT;
	DTVendedor(string nickname, DTFecha fechaNac, string RUT);
	~DTVendedor();
};

#endif // !DT_VENDEDOR
