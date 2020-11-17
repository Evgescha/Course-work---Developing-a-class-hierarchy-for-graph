#pragma once

#include "Vertex.h"
#include <string>

// класс ребра
class Edge
{
private:
	// вершина из которой направлено ребро
	Vertex* From;
	// вершина в которую направлено ребро
	Vertex* To;
	// вес ребра
	int Weight = 0;

public:
	// методы доступа к вершинам ребра и весу
	Vertex* getFrom() const;
	void setFrom(Vertex* value);
	Vertex* getTo() const;
	void setTo(Vertex* value);
	int getWeight() const;
	void setWeight(int value);
	// конструктор, по умолчанию вес 1
	Edge(Vertex* from, Vertex* to, int weight = 1);
	// перевод в строку
	std::wstring ToString();
};
