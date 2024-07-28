# This makefile for movie_tracker.exe

CC = clang++
CFLAGS = -g -Wall -std=c++17
LINKER = $(CC) $(CFLAGS) -o
OTHER_LINK_FLAGS =
TARGET = movie_tracker.exe
OBJS = main.o Movie.o Node.o LinkedList.o

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "-------------------------------------------"
	@echo "Linking and creating program executable."
	@echo "-------------------------------------------"
	$(LINKER) $(TARGET) $(OBJS) $(OTHER_LINK_FLAGS)

%.o: %.cpp
	@echo "--------------------------------------------------"
	@echo "Compiling the file: $< to make the object file: $@"
	@echo "--------------------------------------------------"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)

# Dependency chain
main.o			:	main.cpp
Movie.o			:	Movie.cpp
Node.o			:	Node.cpp
LinkedList.o	:	LinkedList.cpp
