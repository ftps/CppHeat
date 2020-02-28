TARGET = exe
LIBS = -lm -lutil
CC = g++
CFLAGS = -Wall -pedantic -o3 -std=c++14 -fconcepts

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard main.cpp))
OBJECT_TEST = $(patsubst %.cpp, %.o, $(wildcard mainForPlots.cpp))
HEADERS = $(wildcard *.hpp)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@
	-rm -f *.o

test: $(OBJECT_TEST)
	$(CC) $(OBJECT_TEST) -Wall $(LIBS) -o $@
	-rm -f *.o
clean:
	-rm -f $(TARGET)
	-rm -f *.o
