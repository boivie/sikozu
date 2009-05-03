CC=g++
CFLAGS=-c -Wall -DUSE_LUA51_PATH
LDFLAGS=-levent -llua5.1
SOURCES=src/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sikozu

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f src/*.o $(EXECUTABLE) core

