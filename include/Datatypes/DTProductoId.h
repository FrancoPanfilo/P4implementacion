#ifndef DT_PRODUCTO_ID
#define DT_PRODUCTO_ID

#include <string>
using namespace std;

class DTProductoId {
	public:
	int codigo;
	string nombre;
	DTProductoId(int codigo, string nombre);
	~DTProductoId();
	//bool operator<(const DTProductoId& otro) const;
};

#endif // !DT_PRODUCTO_ID
