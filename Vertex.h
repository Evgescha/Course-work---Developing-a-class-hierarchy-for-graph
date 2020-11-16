#pragma once

#include <string>
#include <iostream>
class Vertex
{
private:
	int Number = 0;
public:
	int getNumber() const;
	void setNumber(int value);
	Vertex(int number);
	
};
