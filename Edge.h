#pragma once

#include "Vertex.h"
#include <string>


class Edge
{
private:
	Vertex* From;
	Vertex* To;
	int Weight = 0;

public:
	Vertex* getFrom() const;
	void setFrom(Vertex* value);
	Vertex* getTo() const;
	void setTo(Vertex* value);
	int getWeight() const;
	void setWeight(int value);

	Edge(Vertex* from, Vertex* to, int weight = 1);

	std::wstring ToString();
};
