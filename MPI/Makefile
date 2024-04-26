CC=mpicc
CCFLAGS= -Ofast -Wall

EXE=mpi_postman

all: $(EXE)



$(EXE): mpi_postman.c
	$(CC) $(CCFLAGS) -o $@ $^

clean:
	-/bin/rm -f $(EXE)
