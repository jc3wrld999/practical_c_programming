CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main
SRCS = main.c person.c

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
