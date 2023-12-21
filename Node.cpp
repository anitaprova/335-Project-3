#include "Node.hpp"

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