#pragma once
#include "stdafx.h"
#include "iostream"

using namespace std;

enum xCoordinate {a,b,c,d,e,f,g,h};
static const char xCoord[] = {'a','b','c','d','e','f','g','h'};

struct Position
{
private:
	xCoordinate x;
	unsigned y;

public:
	Position()
	{
		this->x = a;  
		this->y = 0;
	};

	Position(xCoordinate _x, unsigned _y)
	{
		this->setX(_x);
		this->setY(_y);
	}

	Position(Position const& other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	void setX(xCoordinate _x)
	{
		x = _x;
	}

	void setY(unsigned _y)
	{
		y = _y;
	}

	xCoordinate getX() const
	{
		return x;
	}

	int getY() const
	{
		return y;
	}

	void printPosition()
	{
		cout << getX() << getY() << endl;
	}  

	friend ostream& operator<<(ostream& os, Position const& p)
	{
		os << xCoord[p.getX()];
		os << p.getY();
		return os;
	}

	bool operator==(Position const& p)
	{
		if (this->getX() == p.getX() && this->getY() == p.getY())
		{
			return true;
		}

		return false;
	}

	friend istream& operator>>(istream& is, Position &p)
	{
		//we need more checks here
		char letter;
		is >> letter >> p.y;
		p.x = static_cast<xCoordinate>(letter-'a');
		return is;
	}
};