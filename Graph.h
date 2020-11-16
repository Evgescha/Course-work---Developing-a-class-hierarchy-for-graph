#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Vertex.h"
#include <vector>
#include <list>
#include <algorithm>
#include "Edge.h"
#include <list>
#include <iostream>
#include "string"
using namespace std;

class Graph
{
public:
	std::list<Vertex*> Vertexes = std::list<Vertex*>();
	std::list<Edge*> Edges = std::list<Edge*>();


	int getVertexCount() const
	{
		return Vertexes.size();
	}
	int getEdgeCount() const
	{
		return Edges.size();
	}
	void AddVertex(Vertex* vertex)
	{
		Vertexes.push_back(vertex);
	}
	void AddEdge(Vertex* from, Vertex* to)
	{
		auto edge = new Edge(from, to);
		Edges.push_back(edge);
	}
	int**  GetMatrix()
	{		
		
		int** matrix = new int* [100];
		for (int i = 0; i < 100; i++) {
			matrix[i] = new int[100];
			for (int j = 0; j < 100; j++){
				matrix[i][j] = 0;}
		}
		

		for (Edge* edge : Edges)
		{
			int row = edge->getFrom()->getNumber() - 1;
			int column = edge->getTo()->getNumber() - 1;

			matrix[row][column] = edge->getWeight();
			
		}

		return matrix;
	}

	std::list<Vertex*> GetVertexLists(Vertex* vertex)
	{
		std::list<Vertex*> result = std::list<Vertex*>();

		for (Edge* edge : Edges)
		{
			if (edge->getFrom() == vertex)
			{
				result.push_back(edge->getTo());
			}
		}

		return result;
	}

	bool isEglesHas(Edge* _edge) {
		for (Edge* edge : Edges)
		{
			if (_edge->getFrom() == edge->getFrom() &&
				_edge->getTo() == edge->getTo())
				return true;
		}
		return false;
	}
	bool isVertexesHas(Vertex* _vertex) {
		for (Vertex* vertex : Vertexes)
		{
			if (_vertex->getNumber()==vertex->getNumber())
				return true;
		}
		return false;
	}
};