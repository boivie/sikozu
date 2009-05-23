CC=g++
CFLAGS=-c -Wall -I./src -I./examples
LDFLAGS=-levent -lprotobuf -lboost_thread-mt
SOURCES=src/main.cpp src/nodeid.cpp src/packetheader.cpp src/baseservice.cpp src/coreservice.cpp src/server.cpp src/contact.cpp src/serviceregistry.cpp src/bucketstore.cpp src/request.cpp src/session.cpp src/core.pb.cc src/workerthread.cpp src/basethread.cpp examples/simpledb.cpp examples/simpledb.pb.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sikozu

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f src/*.o $(EXECUTABLE) core

