CC=g++
CFLAGS=-Wall -g -std=c++11
LDFLAGS=-g

all: texture-packing testPPM PPMImage.o Rectangle.o

%: %.o
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.cpp %.hpp
	$(CC) -o $@ $(CFLAGS) -c $<

testPPM: testPPM.o PPMImage.o Rectangle.o
	$(CC) -o $@ $(LDFLAGS) $^

texture-packing: texture-packing.o PPMImage.o
	$(CC) -o $@ $(LDFLAGS) $^

Rectangle.o: Rectangle.cpp Rectangle.hpp PPMImage.o
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm *.o


