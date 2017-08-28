SHELL = /bin/sh
CPP    = g++
FLAGS  = -std=c++11

TARGET  = libNumlab.1.dylib
SOURCES = $(shell echo src/*.cpp)
HEADERS = $(shell echo inc/*.h)
OBJECTS = $(SOURCES:.cpp=.o)
PROG = sysstatd

all: $(PROG)

$(PROG) : $(OBJECTS)
    $(CPP) -dynamiclib $(FLAGS) $(SOURCES) -current_version 1.0 -compatibility_version 1.0 -fvisibility=hidden -o $(TARGET)
