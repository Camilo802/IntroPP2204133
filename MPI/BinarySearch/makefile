## Nombre del ejecutable
TARGET = mpi_BinarySearch

# Compilador y flags
CC = mpicc
CFLAGS = -Wall -Wextra

# Archivos fuente
SOURCES = mpi_BinarySearch.c

# Archivos objeto
OBJECTS = $(SOURCES:.c=.o)

# Regla por defecto (construir el ejecutable)
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Regla para compilar archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para ejecutar el programa
run: $(TARGET)
	mpirun -np 4 ./$(TARGET)

# Regla para limpiar archivos objeto y ejecutable
clean:
	rm -f $(OBJECTS) $(TARGET)