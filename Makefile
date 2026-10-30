CC = gcc
CFLAGS = -Wall -Wpedantic -Wextra -g

TARGET = cnote
OBJS = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) *.o
