OBJECTS = Vertex.o
CXXFLAGS = -g -c -o
LDFLAGS =
CXX = g++

main: main.o $(OBJECTS)
	g++ -g -o main main.o $(OBJECTS)

main.o: main.cpp NearestNeighbor.hpp

Vertex.o: Vertex.cpp Vertex.hpp

clean:
	rm main main.o $(OBJECTS)