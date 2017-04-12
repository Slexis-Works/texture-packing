CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
LDFLAGS=-g

LIBS=PPMImage.o Rectangle.o Shelf.o Bin.o algoFFDH.o algoSFFDH.o
PROGS=testPPM texture-packing

all:  $(LIBS) $(PROGS)

%: %.o
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.cpp %.hpp
	$(CC) -o $@ $(CFLAGS) -c $<

testPPM: testPPM.o $(LIBS)
	$(CC) -o $@ $(LDFLAGS) $^

texture-packing: texture-packing.o $(LIBS)
	$(CC) -o $@ $(LDFLAGS) $^

Rectangle.o: Rectangle.cpp Rectangle.hpp PPMImage.o
	$(CC) -o $@ $(CFLAGS) -c $<

Shelf.o: Shelf.cpp Shelf.hpp PPMImage.o Rectangle.o
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm *.o


