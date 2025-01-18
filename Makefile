CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRCS = src/main.c src/pcb.c src/queue.c src/scheduler.c src/pipeline.c
OBJS = $(SRCS:.c=.o)
TARGET = simulador

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lpthread

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)
