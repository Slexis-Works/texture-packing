CC=g++
CFLAGS=-Wall -g -std=c++11
LDFLAGS=-g

all: PPMImage.o

%: %.o
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.cpp %.hpp
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm *.o


