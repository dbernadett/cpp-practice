CXX=g++
CXXGLFAGS=-Wall

BINARIES = helloworld

all: $(BINARIES)

helloworld: helloworld.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	/bin/rm -f $(BINARIES) *.o
