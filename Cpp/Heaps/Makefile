# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = main

all: heaps

heaps: main.o maxheap.o minheap.o
	$(CC) $(CFLAGS) -o heaps.out main.cpp maxheap.o minheap.o

maxheap.o:
	$(CC) $(CFLAGS) -c maxheap.cpp

minheap.o:
	$(CC) $(CFLAGS) -c minheap.cpp

clean:
	$(RM) heaps.out main.o maxheap.o minheap.o

test: all
	./heaps.out