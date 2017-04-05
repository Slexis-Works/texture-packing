CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
LDFLAGS=-g

all: texture-packing testPPM PPMImage.o Rectangle.o Shelf.o

%: %.o
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.cpp %.hpp
	$(CC) -o $@ $(CFLAGS) -c $<

testPPM: testPPM.o PPMImage.o Rectangle.o Shelf.o
	$(CC) -o $@ $(LDFLAGS) $^

texture-packing: texture-packing.o PPMImage.o
	$(CC) -o $@ $(LDFLAGS) $^

Rectangle.o: Rectangle.cpp Rectangle.hpp PPMImage.o
	$(CC) -o $@ $(CFLAGS) -c $<

Shelf.o: Shelf.cpp Shelf.hpp PPMImage.o Rectangle.o
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm *.o


