CC=g++
CFLAGS=-I./raylib -L./raylib -lraylib -lm -ldl -pthread -lX11

main: main.cpp game.cc tools.cc
	$(CC) main.cpp game.cc tools.cc -o main $(CFLAGS)

