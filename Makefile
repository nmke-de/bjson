
# Override these variables with environment variables by setting -e when using `make`.
LD = ld
LIBC = -lc
LDOPT = -static -s -z norelro -z noseparate-code

build: bjson

bjson: bjson.o
	$(LD) $(LDOPT) -o bjson bjson.o $(LIBC)

clean:
	rm -f *.o bjson

all: build clean

.PHONY: all build clean
