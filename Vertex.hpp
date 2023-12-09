#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Vertex
{
private:
	int id;
	double x, y;
	bool visited;

public:
	Vertex(int id, double x_coord, double y_coord);
	int getID();
	double getX();
	double getY();
	bool isVisited();

	int distance(const Vertex &other);
	void print();
};