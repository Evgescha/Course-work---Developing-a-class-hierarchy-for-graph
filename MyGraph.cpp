// MyGraph.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "string"
#include "Graph.h"





void GetVertex(Graph* graph, Vertex* vertex)
{
	std::wcout << vertex->getNumber() << L": ";
	for (Vertex* v : graph->GetVertexLists(vertex))
	{
		std::wcout << v->getNumber() << L", ";
	}
	std::wcout << std::endl;
}

void GetMatrix(Graph* graph)
{
	int** matrix = graph->GetMatrix();
	for (int i = 0; i < graph->getVertexCount(); i++)
	{
		std::wcout << i+1 ;
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




int main()
{
	std::cout << "Hello World!\n";

	Graph* graph = new Graph();

	Vertex* v1 = new Vertex(1);
	Vertex* v2 = new Vertex(2);
	Vertex* v3 = new Vertex(3);
	Vertex* v4 = new Vertex(4);
	Vertex* v5 = new Vertex(5);
	Vertex* v6 = new Vertex(6);
	Vertex* v7 = new Vertex(7);

	graph->AddVertex(v1);
	graph->AddVertex(v2);
	graph->AddVertex(v3);
	graph->AddVertex(v4);
	graph->AddVertex(v5);
	graph->AddVertex(v6);
	graph->AddVertex(v7);

	graph->AddEdge(v1, v2);
	graph->AddEdge(v1, v3);
	graph->AddEdge(v3, v4);
	graph->AddEdge(v2, v5);
	graph->AddEdge(v2, v6);
	graph->AddEdge(v6, v5);
	graph->AddEdge(v5, v6);

	GetMatrix(graph);

	std::wcout << std::endl;
	std::wcout << std::endl;
	/*
	GetVertex(graph, v1);
	GetVertex(graph, v2);
	GetVertex(graph, v3);
	GetVertex(graph, v4);
	GetVertex(graph, v5);
	GetVertex(graph, v6);
	GetVertex(graph, v7);

	std::wcout << std::endl;
	std::wcout << std::endl;
	*/
}

