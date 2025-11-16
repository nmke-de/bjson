
LDOPT ?= -static -s -z norelro -z noseparate-code

build: bjson

bjson: bjson.o
	$(CC) $(LDOPT) -o bjson bjson.o

clean:
	rm -f *.o bjson

all: build clean

.PHONY: all build clean
