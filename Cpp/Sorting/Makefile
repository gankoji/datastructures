# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = main

all: sorting

sorting: main.o quicksort.o mergesort.o heapsort.o
	$(CC) $(CFLAGS) -o sorting.out main.cpp quicksort.o mergesort.o heapsort.o

quicksort.o:
	$(CC) $(CFLAGS) -c quicksort.cpp

mergesort.o:
	$(CC) $(CFLAGS) -c mergesort.cpp

heapsort.o:
	$(CC) $(CFLAGS) -c heapsort.cpp

clean:
	$(RM) sorting.out main.o quicksort.o mergesort.o heapsort.o

test: all
	./sorting.out