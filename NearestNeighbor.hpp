#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>
#include <cmath>
#include <iomanip>

class Node
{
private:
	int id;
	double x, y;
	bool visited;

public:
	Node(int id, double x_coord, double y_coord);
	int getID();
	double getX();
	double getY();
	bool isVisited();

	int distance(const Node &other);
};

/**
 * Constructor for Node class
 * @param id: ID of Node
 * @param x: x coordinate of Node
 * @param y: y coordinate of Node
 */
Node::Node(int id, double x_coord, double y_coord)
{
	this->id = id;
	x = x_coord;
	y = y_coord;
	visited = false;
}

/**
 * returns the ID of the node
 * @return: ID
 */
int Node::getID()
{
	return id;
}

/**
 * returns the x-coordinate of the node
 * @return: x-coordinate
 */
double Node::getX()
{
	return x;
}

/**
 * returns the y-coordinate of the node
 * @return: y-coordinate
 */
double Node::getY()
{
	return y;
}

/**
 * returns whether or not the node has been visited
 * which will be useful later for the algorithm
 * @return: whether the node has been visited
 */
bool Node::isVisited()
{
	return visited;
}

/**
 * Uses Euclidean distance and rounds the distance to the nearest number
 * @return: the distance of one node to another
 */
int Node::distance(const Node &other)
{
	return static_cast<int>(std::round(std::sqrt((std::pow(x - other.x, 2) + std::pow(y - other.y, 2)))));
}

/**
 * first extracts all the information from the file
 * next finds the nearest neighbor for the current node until all nodes have been visited 
 * @param filename: the file name containing the information on the nodes and their coordinates
 */
void nearestNeighbor(std::string filename)
{
	std::ifstream file(filename);

	std::string line;
	std::list<Node> unvisitedNode;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		int index;
		double x, y;

		if (iss >> index >> x >> y)
		{
			Node v(index, x, y);
			unvisitedNode.push_back(v);
		}
	}

	auto start_time = std::chrono::high_resolution_clock::now();

	std::list<Node> tour;
	int totalDistance = 0;

	// start with the first Node on the tour
	auto currentCity = unvisitedNode.begin();
	tour.push_back(*currentCity);
	unvisitedNode.erase(currentCity);

	while (!unvisitedNode.empty())
	{
		int minDistance = std::numeric_limits<int>::max();
		auto nearestCity = unvisitedNode.begin();

		for (auto it = unvisitedNode.begin(); it != unvisitedNode.end(); ++it)
		{
			int distance = currentCity->distance(*it);
			if (distance < minDistance)
			{
				minDistance = distance;
				nearestCity = it;
			}
		}

		totalDistance += minDistance;
		currentCity = nearestCity;
		tour.push_back(*nearestCity);
		unvisitedNode.erase(nearestCity);
	}

	// Return to the starting city to complete the tour	
	totalDistance += currentCity->distance(tour.front());

	auto end_time = std::chrono::high_resolution_clock::now();

	// Print the tour
	for (auto &city : tour)
	{
		std::cout << city.getID() << " ";
	}
	std::cout << tour.front().getID() << std::endl; //to account for the fact that we are returning to the starting city

	int time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
	std::cout << "Total Distance: " << totalDistance << "\nTime: " << time << std::endl;
}
