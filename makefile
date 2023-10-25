CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Stack.o $(OBJ)/BooleanEvaluation.o $(OBJ)/BinaryTree.o
HDRS = $(INC)/BooleanEvaluation.hpp $(INC)/Stack.hpp $(INC)/BinaryTree.hpp
CFLAGS = -Wall -std=c++11 -c -g -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp  

$(OBJ)/BooleanEvaluation.o: $(HDRS) $(SRC)/BooleanEvaluation.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BooleanEvaluation.o $(SRC)/BooleanEvaluation.cpp	 

$(OBJ)/BinaryTree.o: $(HDRS) $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BinaryTree.o $(SRC)/BinaryTree.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out