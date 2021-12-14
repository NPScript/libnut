CC=gcc
SRC=$(wildcard *.c)
OBJ=${SRC:.c=.o}
LDFLAGS=

all: test

options:
	@echo "CC      = ${CC}"
	@echo "SRC     = ${SRC}"
	@echo "OBJ     = ${OBJ}"
	@echo "LDFLAGS = ${LDFLAGS}"

.c.o:
	${CC} -c $<

test: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm ${OBJ} test

