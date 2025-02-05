CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src/main.c src/pcb.c src/queue.c src/scheduler.c src/pipeline.c src/cache.c
OBJ = $(SRC:.c=.o)
BIN = simulador

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) -lpthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

run: $(BIN)
	./$(BIN)
