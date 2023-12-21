OBJECTS =
CXXFLAGS = -g -c -o
LDFLAGS =
CXX = g++

main: main.o $(OBJECTS)
	g++ -g -o main main.o $(OBJECTS)

main.o: main.cpp NearestNeighbor.hpp

clean:
	rm main main.o $(OBJECTS)