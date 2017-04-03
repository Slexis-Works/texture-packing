CC=g++
CFLAGS=-Wall -g -std=c++11
LDFLAGS=-g

all: testPPM PPMImage.o

%: %.o
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.cpp %.hpp
	$(CC) -o $@ $(CFLAGS) -c $<

testPPM: testPPM.o PPMImage.o
	$(CC) -o $@ $(LDFLAGS) $^

clean:
	rm *.o


