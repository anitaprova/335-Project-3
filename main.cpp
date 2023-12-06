#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "NearestNeighbor.hpp"
#include "GreedyTSP.hpp"

int main()
{
	// Nearest Neighbor
	auto start_time = std::chrono::high_resolution_clock::now();


	auto end_time = std::chrono::high_resolution_clock::now();
	int duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
	std::cout << "Duration: " << duration << " milliseconds" << std::endl;
	// Greedy TSP

	return 0;
}