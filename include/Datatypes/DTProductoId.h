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
};

#endif // !DT_PRODUCTO_ID
