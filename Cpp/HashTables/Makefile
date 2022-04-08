# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = main

all: hashtables

hashtables: main.o hashtable.o
	$(CC) $(CFLAGS) -o hashtables.out main.cpp hashtable.o

hashtable.o:
	$(CC) $(CFLAGS) -c hashtable.cpp

clean:
	$(RM) hashtables.out main.o hashtable.o

test: clean all
	./hashtables.out