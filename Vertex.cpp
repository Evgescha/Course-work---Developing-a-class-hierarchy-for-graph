#define _CRT_SECURE_NO_WARNINGS
#include "Vertex.h"
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
