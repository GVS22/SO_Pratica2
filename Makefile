CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
OBJ = src/main.o src/pcb.o src/queue.o src/core.o src/resource.o
EXEC = simulador

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) -lpthread

src/main.o: src/main.c include/pcb.h include/queue.h include/core.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/pcb.o: src/pcb.c include/pcb.h
	$(CC) $(CFLAGS) -c src/pcb.c -o src/pcb.o

src/queue.o: src/queue.c include/queue.h include/pcb.h
	$(CC) $(CFLAGS) -c src/queue.c -o src/queue.o

src/core.o: src/core.c include/core.h include/queue.h include/pcb.h
	$(CC) $(CFLAGS) -c src/core.c -o src/core.o

src/resource.o: src/resource.c include/resource.h
	$(CC) $(CFLAGS) -c src/resource.c -o src/resource.o

clean:
	rm -f src/*.o $(EXEC)

run: all
	./$(EXEC)
