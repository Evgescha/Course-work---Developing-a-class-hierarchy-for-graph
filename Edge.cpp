#define _CRT_SECURE_NO_WARNINGS
#include "Edge.h"
#include "Vertex.h"

// реализация гет/сеттеров и конструктора
	Vertex *Edge::getFrom() const
	{
		return From;
	}

	void Edge::setFrom(Vertex *value)
	{
		From = value;
	}

	Vertex *Edge::getTo() const
	{
		return To;
	}

	void Edge::setTo(Vertex *value)
	{
		To = value;
	}

	int Edge::getWeight() const
	{
		return Weight;
	}

	void Edge::setWeight(int value)
	{
		Weight = value;
	}

	Edge::Edge(Vertex *from, Vertex *to, int weight)
	{
		setFrom(from);
		setTo(to);
		setWeight(weight);
	}


