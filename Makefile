
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Iinclude
SOURCES = $(wildcard src/*.c)
TARGET = desempenho_ordenacao

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
