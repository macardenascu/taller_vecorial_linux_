CC = gcc
CFLAGS = -Wall -Iinclude
LIBS = -lm

SRC = src/main.c src/densidades.c src/integracion.c
OBJ = $(SRC:.c=.o)
EXEC = programa_vectorial

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)

run: all
	./$(EXEC)
