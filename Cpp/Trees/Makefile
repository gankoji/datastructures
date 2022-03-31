# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = main

all: trees

trees: main.o bst_node.o avl_tree.o
	$(CC) $(CFLAGS) -o trees.out main.cpp bst_node.o avl_tree.o

bst_node.o:
	$(CC) $(CFLAGS) -c bst_node.cpp

avl_tree.o:
	$(CC) $(CFLAGS) -c avl_tree.cpp

clean:
	$(RM) trees.out main.o bst_node.o avl_tree.o

test: all
	./trees.out