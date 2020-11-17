#pragma once

#include <string>
#include <iostream>
// класс вершин графа
class Vertex
{
private:
	// ключевое поле для определения
	int Number = 0;
public:
	// методы доступа к ключу
	int getNumber() const;
	void setNumber(int value);
	// конструктор
	Vertex(int number);
	
};
