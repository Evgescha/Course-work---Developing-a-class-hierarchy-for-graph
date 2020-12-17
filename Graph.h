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
#include <fstream>

using namespace std;
// ����� �����
class Graph
{
public:
	// ������ ������ �����
	std::vector<Vertex*> Vertexes = std::vector<Vertex*>();
	// ������ ����� �����
	std::vector<Edge*> Edges = std::vector<Edge*>();

	// ���������� ���/��������
	int getVertexCount() const
	{
		return Vertexes.size();
	}
	int getEdgeCount() const
	{
		return Edges.size();
	}

	vector<Vertex*> getVertexes() const
	{
		return Vertexes;
	}
	vector<Edge*> getEdges() const
	{
		return Edges;
	}

	// ����� ���������� �������
	void AddVertex(Vertex* vertex)
	{
		if (vertex == NULL)return;
		Vertexes.push_back(vertex);
	}
	// ����� ���������� �����
	void AddEdge(Vertex* from, Vertex* to)
	{
		if (from == NULL || to == NULL)return;
		auto edge = new Edge(from, to);
		Edges.push_back(edge);
	}
	// ����� ��������� ������� ��������� �����
	int**  GetMatrix()
	{		
		// ������������� �������
		int** matrix = new int* [100];
		for (int i = 0; i < 100; i++) {
			matrix[i] = new int[100];
			for (int j = 0; j < 100; j++){
				matrix[i][j] = 0;}
		}		
		// ������ � ������ ������� ���������
		for (Edge* edge : Edges)
		{
			int row = edge->getFrom()->getNumber();
			int column = edge->getTo()->getNumber();
			matrix[row][column] = edge->getWeight();			
		}
		return matrix;
	}
	// ����� ����������� ������ ������, � ������� ����� ������� �� ��������� �������
	std::list<Vertex*> GetVertexLists(Vertex* vertex)
	{
		std::list<Vertex*> result = std::list<Vertex*>();
		if (vertex == NULL)return result;

		for (Edge* edge : Edges)
		{
			if (edge->getFrom() == vertex)
			{
				result.push_back(edge->getTo());
			}
		}

		return result;
	}
	// ����� ��������, ���� �� � ������� ����� ���������� �����
	bool isEglesHas(Edge* _edge) {
		if (_edge == NULL)return false;
		for (Edge* edge : Edges)
		{
			if (_edge->getFrom()->getNumber() == edge->getFrom()->getNumber() &&
				_edge->getTo()->getNumber() == edge->getTo()->getNumber())
				return true;
		}
		return false;
	}
	// ����� ��������, ���� �� � ������� ����� ���������� �������
	bool isVertexesHas(Vertex* _vertex) {
		if (_vertex == NULL)return false;
		for (Vertex* vertex : Vertexes)
		{
			if (_vertex->getNumber()==vertex->getNumber())
				return true;
		}
		return false;
	}
	//����� ����������� ������
	static Graph* crossing(Graph* g1, Graph* g2) {
		Graph* graph = new Graph();
		if (g1 == NULL || g2==NULL)return graph;
		//��������� ������ ���� �� �������
		for (Edge* e1 : g1->getEdges())
		{
			//���� ����� ������ ���� �� ������ �����
			if (g2->isEglesHas(e1)) {
				//���� ����� ������ ��� ���, ���������
				if (!graph->isVertexesHas(e1->getFrom()))
					graph->AddVertex(e1->getFrom());
				if (!graph->isVertexesHas(e1->getTo()))
					graph->AddVertex(e1->getTo());
				//��������� � ���� �����������
				graph->AddEdge(e1->getFrom(), e1->getTo());
			}
		}
		return graph;
	}
	// ����� ����������� ������
	static Graph* alliance(Graph* g1, Graph* g2) {
		Graph* graph = new Graph();
		if (g1 == NULL || g2 == NULL)return graph;
		//��������� ������ ���� �� ��������
		for (Vertex* v1 : g1->getVertexes())
			graph->AddVertex(v1);

		//��������� ������ ���� �� ��������
		for (Vertex* v2 : g2->getVertexes())
			//���� ����� ���, �� ���������
			if(!graph->isVertexesHas(v2))
				graph->AddVertex(v2);
			

		//��������� ������ ���� �� �������
		for (Edge* e1 : g1->getEdges())
			graph->AddEdge(e1->getFrom(),e1->getTo());

		//��������� ������ ���� �� �������
		for (Edge* e2 : g2->getEdges())
			// ���� ����� ���, �� ���������
			if(!graph->isEglesHas(e2))
			graph->AddEdge(e2->getFrom(), e2->getTo());

		return graph;
		
	}
	//����� ������� ����� �� �����
	static void GetMatrix(Graph* graph)
	{
		if (graph == NULL )return ;
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

	//����� �� ����� ������, � ������� ����� ������� �� ������� ��������� �����
	static void GetVertex(Graph* graph, Vertex* vertex)
	{
		if (graph == NULL || vertex == NULL)return ;
		std::wcout << vertex->getNumber() << L": ";
		for (Vertex* v : graph->GetVertexLists(vertex))
		{
			std::wcout << v->getNumber() << L", ";
		}
		std::wcout << std::endl;
	}

	void SaveToFile(string filename) {
		ofstream fout(filename); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ cppstudio.txt
		int** matrix = GetMatrix();
		for (int i = 0; i < getVertexCount(); i++)
		{
			for (int j = 0; j < getVertexCount(); j++)
			{
				fout << matrix[i][j];
				if (j + 1 < getVertexCount())fout << " ";
			}
			if (i + 1 < getVertexCount())fout << std::endl;
		}
		fout.close(); // ��������� ����
	}

	//����� ������ �� �����
	Graph* readFromFile(string filename) {
		Graph* graph1 = new Graph();
		char buff[50];
		ifstream file(filename); // ���� �� �������� ������  
		file.getline(buff, 50);


		//��������� ������ ������
		vector<string> listValues = split(buff, " ");
		//������� �� ��� ������ ���������� ������
		for (int i = 0; i < listValues.size(); i++)
			graph1->AddVertex(new Vertex(i));

		//����� �������� ������ ������ � ������� �����
		int row = 0;
		do {
			for (int i = 0; i < listValues.size(); i++)
			{
				if (std::stoi(listValues[i]) != 0)
					graph1->AddEdge(graph1->getVertexes()[row], graph1->getVertexes()[i]);
			}
			file.getline(buff, 50);
			listValues = split(buff, " ");
			row++;
		} while (listValues.size() > 1);


		file.close(); // ����������� ��������� ���� ��� �� �� ��������� ���

		return graph1;
	}

	// ����� ���������� ������ �� �����������
	vector<string> split(char* phrase, string delimiter) {
		vector<string> list;
		string s = string(phrase);
		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != string::npos) {
			token = s.substr(0, pos);
			list.push_back(token);
			s.erase(0, pos + delimiter.length());
		}
		list.push_back(s);
		return list;
	}
};