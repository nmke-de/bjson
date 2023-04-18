
# Override these variables with environment variables by setting -e when using `make`.
LD = ld
LIBC = -lc

build: bjson

bjson: bjson.o
	$(LD) -static -s -z norelro -z noseparate-code -o bjson bjson.o $(LIBC)

clean:
	rm -f $(cat .gitignore)

all: build clean

.PHONY: all build clean
