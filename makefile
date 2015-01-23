CXX=g++
CXXGLFAGS=-Wall

BINARIES = detOfMat

all: $(BINARIES)

detOfMat: detOfMat.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	/bin/rm -f $(BINARIES) *.o
