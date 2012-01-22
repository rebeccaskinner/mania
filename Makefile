CC=gcc

CFLAGS= -std=gnu99 \
	-O0        \
	-g -ggdb   \
	-Wall      \
	-Werror    \
	-Wno-return-type \
	-Wno-unused-function

LFLAGS= -lSDL \
	-lSDL_image

SRC= $(shell echo *.c)
OBJ= $(SRC:.c=.o)

all: mania

%.o : %.c
	$(CC) $(CFLAGS) -c $(<)

mania: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o $(@)

clean:
	-rm -f *.o
	-rm -f core*
	-rm -f mania

.PHONY: all clean
