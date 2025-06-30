# Makefile para proyecto MCM con GTK+ 3

CC = gcc
CFLAGS = -Wall `pkg-config --cflags gtk+-3.0` -Iinclude
LDFLAGS = `pkg-config --libs gtk+-3.0`
SRC = src/main.c src/interfaz.c src/eventos.c src/logica.c src/fachada.c
OUT = app

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
