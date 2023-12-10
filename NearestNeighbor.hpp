#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cctype>
#include <regex>
#include <list>
#include <iomanip>

void nearestNeighbor(std::string filename)
{
	std::ifstream file(filename);

	std::string line;
	std::list<Vertex> unvisitedVertex;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		int index;
		double x, y;

		if (iss >> index >> x >> y)
		{
			Vertex v(index, x, y);
			unvisitedVertex.push_back(v);
		}
	}

	auto start_time = std::chrono::high_resolution_clock::now();

	std::list<Vertex> tour;
	int totalDistance = 0;

	// start with the first vertex on the tour
	auto currentCity = unvisitedVertex.begin();
	tour.push_back(*currentCity);
	unvisitedVertex.erase(currentCity);
	// for (auto x : unvisitedVertex)
	// {
	// 	x.print();
	// }
	// std::cout << std::endl;

	while (!unvisitedVertex.empty())
	{
		int minDistance = std::numeric_limits<int>::max();
		auto nearestCity = unvisitedVertex.begin();
		//(*nearestCity).print();

		for (auto it = unvisitedVertex.begin(); it != unvisitedVertex.end(); ++it)
		{
			int distance = currentCity->distance(*it);
			// std::cout << "DISTANCE: " << distance << "\n";
			if (distance < minDistance)
			{
				minDistance = distance;
				nearestCity = it;
			}
		}

		totalDistance += minDistance;
		currentCity = nearestCity;
		tour.push_back(*nearestCity);
		unvisitedVertex.erase(nearestCity);
	}

	// Return to the starting city to complete the tour
	// std::cout << currentCity->distance(tour.front()) << "\n";
	// currentCity->print();
	// tour.front().print();
	totalDistance += currentCity->distance(tour.front());

	// Print the tour
	std::cout << "Nearest Neighbor Tour: ";
	for (auto &city : tour)
	{
		std::cout << city.getID() << " ";
	}
	std::cout << tour.front().getID();
	std::cout << std::endl;

	auto end_time = std::chrono::high_resolution_clock::now();
	int time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
	std::cout << "Total Distance: " << totalDistance << "\nTime: " << time << std::endl;
}
