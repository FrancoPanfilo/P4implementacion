principal:
	g++ -Wall -g -lstdc++ -o main main.cpp ./src/datatypes.cpp ./src/controladorUsuarios.cpp ./src/vendedor.cpp ./src/usuario.cpp ./src/fabrica.cpp ./src/Interface/IUsuario.cpp
	./main