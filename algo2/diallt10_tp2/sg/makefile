CC = gcc
CFLAGS = -Wall -Wconversion -Werror -Wextra -Wpedantic -std=c11 -D _POSIX_C_SOURCE=200809L
LDFLAGS = -lX11
objects = sg_trial.o sg.o
executable = sg_trial

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

sg.o: sg.c sg.h
sg_trial.o: sg_trial.c sg.h
