#include "Vertex.hpp"

Vertex::Vertex(int id, double x_coord, double y_coord)
{
	this->id = id;
	x = x_coord;
	y = y_coord;
	visited = false;
}

int Vertex::getID()
{
	return id;
}

double Vertex::getX()
{
	return x;
}

double Vertex::getY()
{
	return y;
}

bool Vertex::isVisited()
{
	return visited;
}

// Uses Euclidean distance and rounds to the nearest number
int Vertex::distance(const Vertex &other)
{
	return static_cast<int>(std::round(std::sqrt((std::pow(x - other.x, 2) + std::pow(y - other.y, 2)))));
}

void Vertex::print()
{
	std::cout << "Index: " << id << "  X-coord: " << x << "  Y-coord: " << y << std::endl;
}