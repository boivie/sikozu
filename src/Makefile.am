# what flags you want to pass to the C compiler & linker
AM_CFLAGS = --pedantic -Wall -O2
AM_LDFLAGS =
INCLUDES = -I../external/threadpool-0_2_5-src/threadpool/

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS = sikozu
sikozu_SOURCES = \
baseservice.cpp  contact.cpp      main.cpp    packetheader.cpp      remoteservice.cpp  server.cpp           task.cpp \
bucketstore.cpp  coreservice.cpp  nodeid.cpp  rawpackethandler.cpp  request.cpp        serviceregistry.cpp  transaction.cpp \
core.pb.cc

