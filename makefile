# This makefile for movie_tracker.exe

CPPC = clang++
CFLAGS = -g -Wall -std=c++17
LINKER = $(CPPC) $(CFLAGS) -o
OTHER_LINK_FLAGS =
BIN= bin/movie_tracker.exe
OBJS = obj/main.o obj/Movie.o obj/Node.o obj/LinkedList.o

all: $(BIN)

$(BIN): $(OBJS)
	$(LINKER) $(BIN) $(OBJS) $(OTHER_LINK_FLAGS)

obj/%.o: src/%.cpp
	$(CPPC) $(CFLAGS) -c $< -o $@

clean:
	rm -r bin/* obj/*

