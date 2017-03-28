CC = gcc
CFLAGS = -I .
DEBUG = -g
LDFLAGS = -lPoKeys -L./src -lusb-1.0 -L/usr/lib/ -lconfig -lzlog -lpthread
SOURCES = ./src/main.c ./src/config.c ./src/devices.c
OBJECTS = $(SOURCES:.c=.o)

pokey: $(OBJECTS)
	$(CC) $(OBJECTS) -o src/pokey $(CFLAGS) $(LDFLAGS) $(DEBUG) -g -std=gnu99 -Wall -m64

clean:
	rm -f src/*.o src/*.a src/pokey

all: clean pokey

install: clean all
	mkdir -p logs
	touch logs/log