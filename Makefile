CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
LDFLAGS=-g

LIBS=PPMImage.o Rectangle.o Shelf.o Bin.o algoFF.o algoFFDH.o
PROGS=testPPM texture-packing

all:  $(LIBS) $(PROGS)

%: %.o
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.cpp %.hpp
	$(CC) -o $@ $(CFLAGS) -c $<

testPPM: testPPM.o $(LIBS)
	$(CC) -o $@ $(LDFLAGS) $^

testPPM.o: testPPM.cpp testPPM.hpp $(LIBS)
	$(CC) -o $@ $(CFLAGS) -c $<

texture-packing: texture-packing.o $(LIBS)
	$(CC) -o $@ $(LDFLAGS) $^

texture-packing.o: texture-packing.cpp texture-packing.hpp $(LIBS)
	$(CC) -o $@ $(CFLAGS) -c $<

Rectangle.o: Rectangle.cpp Rectangle.hpp PPMImage.o
	$(CC) -o $@ $(CFLAGS) -c $<

Shelf.o: Shelf.cpp Shelf.hpp PPMImage.o Rectangle.o
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -f $(LIBS) $(PROGS)


