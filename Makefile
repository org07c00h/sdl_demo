CC=g++
CFLAGS=-Wall -std=c++14 -lSDL2
LDFLAGS=-lSDL2
SOURCES=$(wildcard src/*.cpp)

OBJECTS=$(addprefix obj/,$(notdir $(SOURCES:.cpp=.o)))
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
clean:
	rm -rf obj/*
