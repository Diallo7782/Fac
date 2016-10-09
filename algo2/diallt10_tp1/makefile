CC = gcc
CFLAGS = -std=c11 -Wall -Wconversion -Werror -Wextra -Wpedantic
LDFLAGS =
objects = main.o natural_opr.o
executable = main

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

main.o: main.c natural_opr.h natural.h
natural_opr.o: natural_opr.c natural_opr.h natural.h
