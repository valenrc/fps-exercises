# Compilador y flags
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wshadow -Wconversion -Wfatal-errors -pedantic -lstdc++exp
CXXFLAGS2 := -std=c++23 -Wall -Wextra -Wfatal-errors -lstdc++exp
OPTFLAGS := -O2 -march=native	# optimizaciones
DBGFLAGS := -g -fsanitize=address,undefined -DDEBUG
LDFLAGS := -lstdc++exp	# para windows https://stackoverflow.com/questions/78452682/stdprintln-print-not-working-in-winlibs-mingw-gcc-14-1
FASTFLAGS := -O0 -DFAST_MODE

# Si se usa DEBUG=1, cambia los flags de optimizacion por los de debug
# ej DEBUG=1 make run file.cpp
# para flags de optimizacion es solamente make run file.cpp
ifeq ($(DEBUG), 1)
    CXXFLAGS += $(DBGFLAGS)
else
    CXXFLAGS += $(OPTFLAGS)
endif

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

# Regla de compilación
%: %.cpp
	@echo "🔨 Compilando $<..."
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

# compilacion fast!!
%-fast: %.cpp
	@echo "⚡ Compilando rápido $<..."
	$(CXX) $(CXXFLAGS2) $(FASTFLAGS) -o $@ $< $(LDFLAGS)

# Evita errores cuando `make` intenta interpretar `file.cpp` como un objetivo
%:
	@:

# Limpia archivos compilados
clean:
	rm -f *.o *.out *.exe $(FILE)
