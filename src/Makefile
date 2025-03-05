# Compilador y flags
CXX := g++
CXXFLAGS := -std=c++98 -Wall -Wextra -Wshadow -Wconversion -Wfatal-errors -pedantic
CXXFLAGS2 := -std=c++98 -Wall -Wextra -Wfatal-errors	# para compilar rápido
OPTFLAGS := -O2 -march=native	# optimizaciones
DBGFLAGS := -g -fsanitize=address,undefined -DDEBUG
FASTFLAGS := -O0 -DFAST_MODE

# Si se usa DEBUG=1, cambia los flags de optimizacion por los de debug/sanitizers
# ej DEBUG=1 make run file.cpp
# para flags de optimizacion es solamente make run file.cpp
ifeq ($(DEBUG), 1)
    CXXFLAGS += $(DBGFLAGS)
else
    CXXFLAGS += $(OPTFLAGS)
endif

.PHONY: run fast debug clean

# Obtener el nombre del archivo sin la extensión cpp
FILE := $(basename $(word 2, $(MAKECMDGOALS)))

# Regla para compilar y ejecutar
run: $(FILE)
	@echo "Ejecutando $(FILE)..."
	@./$(FILE)

# compilar rapido (sin optimizaciones)
fast: $(FILE)-fast
	@echo "Ejecutando $(FILE)..."
	@./$(FILE)-fast

# Regla para compilar y ejecutar con input
inp: $(FILE)
	@echo "Ejecutando $(FILE) con input..."
	@./$(FILE) < input

# Regla de compilación
%: %.cpp
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -o $@ $<

# compilacion mas rapida
%-fast: %.cpp
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS2) $(FASTFLAGS) -o $@ $<

# Evita errores cuando `make` intenta interpretar `file.o/cpp` como un objetivo
%.cpp:
	@:
%:
	@:

# Limpia archivos compilados
clean:
	rm -f *.o *.out *.exe $(FILE)