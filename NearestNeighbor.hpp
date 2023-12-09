#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cctype>
#include <regex>
#include <list>

void nearestNeighbor(std::string filename)
{
	std::ifstream file(filename);
	int numCities = 0;
	std::regex dimension("^DIMENSION: \\d+");
	std::regex coordinates("^\\d+ \\d+\\.\\d+ \\d+\\.\\d+");
	std::smatch match;

	std::string line;
	std::list<Vertex> unvisitedVertex;
	while (std::getline(file, line))
	{
		if (std::regex_match(line, dimension))
		{
			std::regex num("\\d+");
			std::regex_search(line, match, num);
			numCities = std::stoi(match[0]);
		}
		else if (std::regex_match(line, coordinates))
		{
			std::regex index("\\d+");
			std::regex_search(line, match, index);
			int i = std::stoi(match[0]);

			std::regex coords("(\\d+) (\\d+.\\d+) (\\d+.\\d+)");
			std::regex_search(line, match, coords);

			double x = std::stod(match[2]);
			double y = std::stod(match[3]);

			Vertex v(i, x, y);
			unvisitedVertex.push_back(v);
		}
	}

	auto start_time = std::chrono::high_resolution_clock::now();
	std::list<Vertex> tour;
	int distance = 0;

	// start with the first vertex on the tour
	auto currentCity = unvisitedVertex.begin();
	tour.push_back(*currentCity);
	//unvisitedVertex.erase(currentCity);
	std::cout << "SIZE: " << numCities << "\n"; 
	

	// while (!unvisitedVertex.empty())
	// {
	// 	auto nearestCity = unvisitedVertex.begin();
	// 	int minDistance = std::numeric_limits<int>::max();

	// 	// gets the nearest city by comparing it to every vertex
	// 	for (auto it = unvisitedVertex.begin(); it != unvisitedVertex.end(); ++it)
	// 	{
	// 		int currDistance = currentCity->distance(*it);
	// 		if (currDistance < minDistance)
	// 		{
	// 			minDistance = currDistance;
	// 			nearestCity = it;
	// 		}
	// 	}

	// 	std::cout << minDistance << "\n";
	// 	// adds to tour and removes from unvisited list
	// 	distance += minDistance;
	// 	tour.push_back(*nearestCity);
	// 	currentCity = unvisitedVertex.erase(nearestCity);
	// 	break;
	// }

	// // Return to the starting city
	// distance += tour.back().distance(tour.front());

	// Print the tour
	// std::cout << "Nearest Neighbor Tour: ";
	// for (auto &city : tour)
	// {
	// 	std::cout << city.getID() << " ";
	// }
	// std::cout << std::endl;

	// auto end_time = std::chrono::high_resolution_clock::now();
	// int time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
	// std::cout << "Total Distance: " << distance << "\nTime: " << time << std::endl;
}
