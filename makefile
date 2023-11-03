CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o  $(OBJ)/Graph.o  $(OBJ)/Sort.o 
HDRS = $(INC)/Graph.hpp $(INC)/Sort.hpp $(INC)/GreedyAlgorithm.hpp
CFLAGS = -Wall -std=c++11 -c -g -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
		./$(EXE) 
		


$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Graph.o: $(HDRS) $(SRC)/Graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Graph.o $(SRC)/Graph.cpp  

$(OBJ)/Sort.o: $(HDRS) $(SRC)/Sort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Sort.o $(SRC)/Sort.cpp


clean:
	rm -f $(EXE) $(OBJS) gmon.out