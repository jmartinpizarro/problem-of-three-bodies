CC=gcc
CFLAGS=-g -Wall

all:
	$(CC) $(CFLAGS) main.cpp -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


