CXX = gcc
CXXFLAGS = -std=c++23 -Wall -Wextra -O2 -DLOCAL -I.
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = $(SOURCES:.cpp=.exe)

.PHONY: all clean run compiler-info

all: $(EXECUTABLES)

%.exe: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@echo "Cleaning up..."
	@rm -f $(OBJECTS) $(EXECUTABLES)

run:
	@if [ -z "$(file)" ]; then \
		echo "Usage: make run file=<filename>"; \
	else \
		$(MAKE) -s $(basename $(file)).exe; \
		./$(basename $(file)).exe; \
	fi

compiler-info:
	@echo "Compiler version:"
	@$(CXX) --version
	@echo "\nCompiler location:"
	@which $(CXX)