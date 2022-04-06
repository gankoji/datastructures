# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = main

all: graphs

graphs: main.o graph.o
	$(CC) $(CFLAGS) -o graphs.out main.cpp graph.o

graph.o:
	$(CC) $(CFLAGS) -c graph.cpp

clean:
	$(RM) graphs.out main.o graph.o

test: clean all
	./graphs.out