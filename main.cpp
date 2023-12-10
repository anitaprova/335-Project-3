#include <iostream>
#include <string>
#include "Vertex.hpp"
#include "NearestNeighbor.hpp"
#include "GreedyTSP.hpp"

int main()
{
	// Nearest Neighbor
	nearestNeighbor("input_files/dj38.tsp");
	nearestNeighbor("input_files/wi29.tsp");

	return 0;
}