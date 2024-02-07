#pragma once
#include <sstream>
#include <iostream>
using namespace std;

#include "Shape.h"

class ColoredShape : public Shape
{
public:
	ColoredShape(Shape& shape, const string& color);
	~ColoredShape();

	virtual string toString() const override;

private:
	Shape& shape;
	string color;
};


ColoredShape::ColoredShape(Shape& shape, const string& color) : shape{ shape }, color{ color }
{

}

ColoredShape::~ColoredShape()
{
	cout << "destruye ColoredShape de color " << color << endl;
	(&shape)->~Shape();
}

string ColoredShape::toString() const
{
	ostringstream oss;
	oss << shape.toString() << " has the color " << color;
	return oss.str();
}
