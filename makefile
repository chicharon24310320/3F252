# Nombre del ejecutable
TARGET = cohete_animacion

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Librerías ftxui (usando pkg-config)
LIBS = $(shell pkg-config --libs ftxui)
CXXFLAGS += $(shell pkg-config --cflags ftxui)

# Fuente principal
SRCS = src/animacion.cpp

# Objetos
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Regla para compilar .cpp a .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ejecutar el programa
run: all
	./$(TARGET)

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)