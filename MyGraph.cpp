#include <iostream>
#include "string"
#include "Graph.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Старт программы!\n";

	Graph* graph1 = new Graph();
	Vertex* g1v1 = new Vertex(1);
	Vertex* g1v2 = new Vertex(2);
	Vertex* g1v3 = new Vertex(3);
	Vertex* g1v4 = new Vertex(4);
	Vertex* g1v5 = new Vertex(5);
	Vertex* g1v6 = new Vertex(6);
	Vertex* g1v7 = new Vertex(7);
	graph1->AddVertex(g1v1);
	graph1->AddVertex(g1v2);
	graph1->AddVertex(g1v3);
	graph1->AddVertex(g1v4);
	graph1->AddVertex(g1v5);
	graph1->AddVertex(g1v6);
	graph1->AddVertex(g1v7);
	graph1->AddEdge(g1v1, g1v2);
	graph1->AddEdge(g1v1, g1v3);
	graph1->AddEdge(g1v3, g1v4);
	graph1->AddEdge(g1v2, g1v5);
	graph1->AddEdge(g1v2, g1v6);
	graph1->AddEdge(g1v6, g1v5);
	graph1->AddEdge(g1v5, g1v6);

	//матрица смежности
	std::cout << "Матрица смежности первого графа!\n";
	graph1->GetMatrix(graph1);
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;


	Graph* graph2 = new Graph();
	Vertex* g2v1 = new Vertex(1);
	Vertex* g2v2 = new Vertex(2);
	Vertex* g2v3 = new Vertex(3);
	graph2->AddVertex(g2v1);
	graph2->AddVertex(g2v2);
	graph2->AddVertex(g2v3);
	graph2->AddEdge(g2v1, g2v2);
	graph2->AddEdge(g2v1, g2v3);
	graph2->AddEdge(g2v3, g2v2);

	//матрица смежности
	std::cout << "Матрица смежности второго графа!\n";
	Graph().GetMatrix(graph2);
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;


	//куда ведут дороги
	std::cout << "Вершины, в которые можно попасть из вершин первого графа!\n";
	Graph().GetVertex(graph1, g1v1);
	Graph().GetVertex(graph1, g1v2);
	Graph().GetVertex(graph1, g1v3);
	Graph().GetVertex(graph1, g1v4);
	Graph().GetVertex(graph1, g1v5);
	Graph().GetVertex(graph1, g1v6);
	Graph().GetVertex(graph1, g1v7);
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;

	Graph* alliance = Graph().alliance(graph1, graph2);
	std::cout << "Матрица смежности после объединения графов!\n";
	Graph().GetMatrix(alliance);
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;

	
	Graph* crossing = Graph().crossing(graph1, graph2);
	std::cout << "Матрица смежности после пересечения графов!\n";
	Graph().GetMatrix(crossing);

	std::wcout << std::endl;
	std::wcout << std::endl;
	std::wcout << std::endl;
	std::cout << "Конец программы!\n";
}

