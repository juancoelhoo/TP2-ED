CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o  $(OBJ)/Graph.o  $(OBJ)/Sort.o 
HDRS = $(INC)/Graph.hpp $(INC)/Sort.hpp 
CFLAGS = -Wall -std=c++11 -c -g -I$(INC)


EXE = $(BIN)/tp2.out

run:$(EXE)
		./$(EXE) 

all:$(EXE)


$(BIN)/tp2.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp2.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Graph.o: $(HDRS) $(SRC)/Graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Graph.o $(SRC)/Graph.cpp  

$(OBJ)/Sort.o: $(HDRS) $(SRC)/Sort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Sort.o $(SRC)/Sort.cpp


clean:
	rm -f $(EXE) $(OBJS) gmon.out