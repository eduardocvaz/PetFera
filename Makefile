#Makefile for "PetFera" C++ application

BIN=./bin
SRC = ./src
INC = ./include


PROG = $(BIN)/petfera
CC = g++
CPPFLAGS = -Wall -std=c++11 -I./include

OBJS = $(BIN)/profissional.o $(BIN)/tratador.o $(BIN)/veterinario.o $(BIN)/animal.o $(BIN)/anfibio.o $(BIN)/ave.o $(BIN)/mamifero.o $(BIN)/reptil.o $(BIN)/petfera.o $(BIN)/main.o $(BIN)/exotico.o $(BIN)/nativo.o $(BIN)/anfibioExotico.o $(BIN)/anfibioNativo.o  $(BIN)/aveExotico.o  $(BIN)/aveNativo.o  $(BIN)/mamiferoExotico.o $(BIN)/mamiferoNativo.o $(BIN)/reptilExotico.o $(BIN)/reptilNativo.o

all : createdir $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

createdir:
	[ -d bin ] || mkdir bin

$(BIN)/main.o : $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@
$(BIN)/petfera.o : $(SRC)/petfera.cpp $(INC)/petfera.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/petfera.cpp -o $@
$(BIN)/veterinario.o : $(SRC)/veterinario.cpp $(INC)/veterinario.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/veterinario.cpp -o $@
$(BIN)/tratador.o : $(SRC)/tratador.cpp $(INC)/tratador.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/tratador.cpp -o $@
$(BIN)/profissional.o : $(SRC)/profissional.cpp $(INC)/profissional.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/profissional.cpp -o $@
$(BIN)/reptil.o : $(SRC)/reptil.cpp $(INC)/reptil.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/reptil.cpp -o $@
$(BIN)/mamifero.o : $(SRC)/mamifero.cpp $(INC)/mamifero.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/mamifero.cpp -o $@
$(BIN)/ave.o : $(SRC)/ave.cpp $(INC)/ave.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/ave.cpp -o $@
$(BIN)/anfibio.o : $(SRC)/anfibio.cpp $(INC)/anfibio.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibio.cpp -o $@
$(BIN)/animal.o : $(SRC)/animal.cpp $(INC)/animal.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/animal.cpp -o $@
$(BIN)/exotico.o : $(SRC)/exotico.cpp $(INC)/exotico.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/exotico.cpp -o $@
$(BIN)/nativo.o : $(SRC)/nativo.cpp $(INC)/nativo.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/nativo.cpp -o $@
$(BIN)/anfibioExotico.o : $(SRC)/anfibioExotico.cpp $(INC)/anfibioExotico.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibioExotico.cpp -o $@
$(BIN)/anfibioNativo.o : $(SRC)/anfibioNativo.cpp $(INC)/anfibioNativo.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibioNativo.cpp -o $@
$(BIN)/aveExotico.o : $(SRC)/aveExotico.cpp $(INC)/aveExotico.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/aveExotico.cpp -o $@
$(BIN)/aveNativo.o : $(SRC)/aveNativo.cpp $(INC)/aveNativo.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/aveNativo.cpp -o $@
$(BIN)/mamiferoExotico.o : $(SRC)/mamiferoExotico.cpp $(INC)/mamiferoExotico.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/mamiferoExotico.cpp -o $@
$(BIN)/mamiferoNativo.o : $(SRC)/mamiferoNativo.cpp $(INC)/mamiferoNativo.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/mamiferoNativo.cpp -o $@
$(BIN)/reptilExotico.o : $(SRC)/reptilExotico.cpp $(INC)/reptilExotico.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/reptilExotico.cpp -o $@
$(BIN)/reptilNativo.o : $(SRC)/reptilNativo.cpp $(INC)/reptilNativo.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/reptilNativo.cpp -o $@
clean:
	rm -f core $(PROG) $(OBJS)
