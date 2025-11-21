# Compiler
CC = gcc

# Source files (located in src/)
SRC = src/game.c src/init.c src/main.c

# Object files (They will be created in the build/ folder)
# We use 'patsubst' to transform 'src/file.c' into 'build/file.o'
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

# Header flags
GAME_LIBS = -Iinclude

# SDL flags
SDL3_INCLUDE = -I/usr/local/include/SDL3
SDL3_LIB_PATH = -L/usr/local/lib
SDL3_LIBS = -lSDL3

# Compilation Flags
CFLAGS = -std=c11 -Wall -Wextra -DENABLE_DEBUG $(SDL3_INCLUDE) $(GAME_LIBS)

# Linker Flags
LDFLAGS = $(SDL3_LIB_PATH) $(SDL3_LIBS)

# Compiled Target Name (will be build/myApp)
TARGET = myApp.out

# --- Build Rules ---

# Default target: all
all: build/$(TARGET)

# Rule to link the object files to final executable
build/$(TARGET): $(OBJ)
    # The build directory is created before linking
	@mkdir -p build
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Rule to compile source file to object file
# This is a pattern rule that matches a target like 'build/file.o'
# and uses the prerequisite 'src/file.c'.
build/%.o: src/%.c
	@mkdir -p build # Ensure the build directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up rules
.PHONY: clean
clean:
    # Remove the entire build directory and everything in it
	 rm -rf build