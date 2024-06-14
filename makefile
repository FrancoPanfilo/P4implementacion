
principal:
<<<<<<< Updated upstream
	gcc -Wall -g -lstdc++ -o main main.cpp
	./main
=======
	#g++ -Wall -g -lstdc++ -o main main.cpp ./src/Datatypes/DTFecha.cpp ./src/Datatypes/DTAltaCliente.cpp ./src/controladorUsuarios.cpp
	g++ -Wall -g -lstdc++ -o main main.cpp ./src/* ./src/Datatypes/* ./src/Interface/*
>>>>>>> Stashed changes
