#define _CRT_SECURE_NO_WARNINGS
#include "Vertex.h"
// реализация гет/сеттеров и конструктора
int Vertex::getNumber() const
{
	return Number;
}

void Vertex::setNumber(int value)
{
	Number = value;
}

Vertex::Vertex(int number)
{
	setNumber(number);
}
