sgdir = ../sg/
CC = gcc
CFLAGS = -std=c11 -Wall -Wconversion -Werror -Wextra -Wpedantic -D _POSIX_C_SOURCE=200809L -I $(sgdir)
LDFLAGS = -lX11 -lm
VPATH = $(sgdir)
objects = main.o $(sgdir)sg.o
executable = main

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

main.o: main.c sg.h
$(sgdir)sg.o: sg.c sg.h
