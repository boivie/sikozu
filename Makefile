CC=g++
CFLAGS=-c -Wall -DUSE_LUA51_PATH
LDFLAGS=-levent -lprotobuf
SOURCES=src/main.cpp src/nodeid.cpp src/packetheader.cpp src/service.cpp src/coreservice.cpp src/server.cpp src/contact.cpp src/serviceregistry.cpp src/bucketstore.cpp src/request.cpp src/session.cpp src/core.pb.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sikozu

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f src/*.o $(EXECUTABLE) core

