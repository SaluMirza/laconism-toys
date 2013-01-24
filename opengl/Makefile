CC = gcc
CFLAGS = -O2
LINK_LIBS = -lGL -lGLU -lglut
OBJECT = big-dipper.o mandelbrot-set.o
TARGET = big-dipper mandelbrot-set

all: $(OBJECT)
	$(CC) -o big-dipper big-dipper.o $(LINK_LIBS)
	$(CC) -o mandelbrot-set mandelbrot-set.o $(LINK_LIBS)

big-dipper.o: big-dipper.c
	$(CC) $(CFLAGS) -c big-dipper.c

mandelbrot-set.o: mandelbrot-set.c
	$(CC) $(CFLAGS) -c mandelbrot-set.c

.PHONY: clean
clean:
	-rm $(TARGET) $(OBJECT)
