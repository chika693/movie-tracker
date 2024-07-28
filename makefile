# This makefile for movie_tracker.exe

CPPC=clang++
CFLAGS=-g -Wall -std=c++17
LINKER=$(CPPC) $(CFLAGS) -o
OTHER_FLAGS=
SRC=src
OBJ=obj
BINDIR=bin
SRCS=$(wildcard $(SRC)/*.cpp) 
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
BIN = $(BINDIR)/movie_tracker.exe

all: $(BIN)

$(BIN): $(OBJS)
	$(LINKER) $@ $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CPPC) $(CFLAGS) -c $< -o $@

clean:
	rm -r $(BINDIR)/* $(OBJ)/*
