#Makefile Lab0

#objetivo predeterminado
all: main

#objetivos que no son archivos
.PHONY: all clean_bin clean

# directorios de los archivos según extensión
HDIR    = include
CPPDIR  = src
ODIR    = obj

#Módulos a compilar
MODULOS = chatgpt fecha infoestudiante estudiante informacion libro paginaweb

# lista de archivos, con directorio y extensión
HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

# Archivo principal y el que lleva int main
MAIN = main
EJECUTABLE = main

#Compilador
CC = g++

# opciones de compilación
CCFLAGS = -g -Wall -Werror -I$(HDIR)

# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
$(ODIR)/$(main).o:$(main).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(main).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@

# borra binarios
clean_bin:
	rm -f $(EJECUTABLE) $(ODIR)/$(main).o $(OS)

clean:clean_bin
	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~ 