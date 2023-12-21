#pragma once
#include <iostream>
#include <string>
#include <cmath>

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
	void print();
};