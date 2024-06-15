principal:
	# TODO: cambiar -w por -Wall
	# g++ -w -g -lstdc++ -o main main.cpp ./src/datatypes.cpp ./src/controladorUsuarios.cpp ./src/vendedor.cpp ./src/usuario.cpp ./src/fabrica.cpp ./src/Interface/IUsuario.cpp ./src/cliente.cpp ./src/observer.cpp
	g++ -w -g -lstdc++ -o main main.cpp ./src/*.cpp ./src/Interface/*.cpp
	./main
