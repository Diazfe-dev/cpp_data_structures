CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = priority-queue
SRCDIR = src
INCDIR = include
OUTDIR = output

# Buscar todos los archivos .cpp en src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal
all: $(OUTDIR)/$(TARGET)

# Crear ejecutable
$(OUTDIR)/$(TARGET): main.cpp $(OBJECTS) | $(OUTDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear directorio output si no existe
$(OUTDIR):
	mkdir -p $(OUTDIR)

# Limpiar archivos compilados
clean:
	rm -f $(SRCDIR)/*.o
	rm -rf $(OUTDIR)

# Compilar y ejecutar
run: $(OUTDIR)/$(TARGET)
	./$(OUTDIR)/$(TARGET)

.PHONY: all clean run
