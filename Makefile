CC=g++
CFLAGS=-Wall -std=c++14
LDFLAGS=-lSDL2 -lSDL2_image
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
