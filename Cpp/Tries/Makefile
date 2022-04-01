# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = main

all: tries

tries: main.o tries.o
	$(CC) $(CFLAGS) -o tries.out main.cpp tries.o

tries.o:
	$(CC) $(CFLAGS) -c tries.cpp

clean:
	$(RM) tries.out main.o tries.o

test: clean all
	./tries.out