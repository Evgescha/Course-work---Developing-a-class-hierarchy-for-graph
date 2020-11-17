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
// класс графа
class Graph
{
public:
	// список вершин графа
	std::list<Vertex*> Vertexes = std::list<Vertex*>();
	// список ребер графа
	std::list<Edge*> Edges = std::list<Edge*>();

	// реализация гет/сеттеров
	int getVertexCount() const
	{
		return Vertexes.size();
	}
	int getEdgeCount() const
	{
		return Edges.size();
	}

	list<Vertex*> getVertexes() const
	{
		return Vertexes;
	}
	list<Edge*> getEdges() const
	{
		return Edges;
	}

	// метод добавления вершины
	void AddVertex(Vertex* vertex)
	{
		Vertexes.push_back(vertex);
	}
	// метод добавления ребра
	void AddEdge(Vertex* from, Vertex* to)
	{
		auto edge = new Edge(from, to);
		Edges.push_back(edge);
	}
	// метод получения матрицы смежности графа
	int**  GetMatrix()
	{		
		// инициализация массива
		int** matrix = new int* [100];
		for (int i = 0; i < 100; i++) {
			matrix[i] = new int[100];
			for (int j = 0; j < 100; j++){
				matrix[i][j] = 0;}
		}		
		// запись в массив матрицы смежности
		for (Edge* edge : Edges)
		{
			int row = edge->getFrom()->getNumber() - 1;
			int column = edge->getTo()->getNumber() - 1;
			matrix[row][column] = edge->getWeight();			
		}
		return matrix;
	}
	// метод определения списка вершин, в которые можно попасть из текущегей вершины
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
	// метод проверки, есть ли в текущем графе переданное ребро
	bool isEglesHas(Edge* _edge) {
		for (Edge* edge : Edges)
		{
			if (_edge->getFrom()->getNumber() == edge->getFrom()->getNumber() &&
				_edge->getTo()->getNumber() == edge->getTo()->getNumber())
				return true;
		}
		return false;
	}
	// метод проверки, есть ли в текущем графе переданная вершина
	bool isVertexesHas(Vertex* _vertex) {
		for (Vertex* vertex : Vertexes)
		{
			if (_vertex->getNumber()==vertex->getNumber())
				return true;
		}
		return false;
	}
	//метод пересечения графов
	static Graph* crossing(Graph* g1, Graph* g2) {
		Graph* graph = new Graph();
		//пробегаем первый граф по дорогам
		for (Edge* e1 : g1->getEdges())
		{
			//если такая дорога есть во втором графе
			if (g2->isEglesHas(e1)) {
				//если таких вершин еще нет, добавляем
				if (!graph->isVertexesHas(e1->getFrom()))
					graph->AddVertex(e1->getFrom());
				if (!graph->isVertexesHas(e1->getTo()))
					graph->AddVertex(e1->getTo());
				//добавляем в граф пересечения
				graph->AddEdge(e1->getFrom(), e1->getTo());
			}
		}
		return graph;
	}
	// метод объединения графов
	static Graph* alliance(Graph* g1, Graph* g2) {
		Graph* graph = new Graph();

		//пробегаем первый граф по вершинам
		for (Vertex* v1 : g1->getVertexes())
			graph->AddVertex(v1);

		//пробегаем второй граф по вершинам
		for (Vertex* v2 : g2->getVertexes())
			//если таких нет, не добавляем
			if(!graph->isVertexesHas(v2))
				graph->AddVertex(v2);
			

		//пробегаем первый граф по дорогам
		for (Edge* e1 : g1->getEdges())
			graph->AddEdge(e1->getFrom(),e1->getTo());

		//пробегаем второй граф по дорогам
		for (Edge* e2 : g2->getEdges())
			// если таких нет, то добавляем
			if(!graph->isEglesHas(e2))
			graph->AddEdge(e2->getFrom(), e2->getTo());

		return graph;
		
	}
	//вывод матрицы графа на экран
	static void GetMatrix(Graph* graph)
	{
		int** matrix = graph->GetMatrix();
		for (int i = 0; i < graph->getVertexCount(); i++)
		{
			std::wcout << i + 1;
			for (int j = 0; j < graph->getVertexCount(); j++)
			{
				std::wcout << L" | " << matrix[i][j] << L" | ";
			}
			std::wcout << std::endl;
		}

		std::wcout << L"____________________________________________________________" << std::endl;
		std::wcout << L" " << std::endl;
		for (int i = 0; i < graph->getVertexCount(); i++)
		{

			string temp = " | " + to_string(i + 1) + " | ";
			std::cout << temp;
		}
	}

	//вывод на экран вершин, в которые можно попасть из вершины заданного графа
	static void GetVertex(Graph* graph, Vertex* vertex)
	{
		std::wcout << vertex->getNumber() << L": ";
		for (Vertex* v : graph->GetVertexLists(vertex))
		{
			std::wcout << v->getNumber() << L", ";
		}
		std::wcout << std::endl;
	}
};