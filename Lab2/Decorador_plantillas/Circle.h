#pragma once
#include <sstream>
#include <iostream>
using namespace std;

#include "Shape.h"

class Circle : public Shape
{
public:
    Circle();
    // explicit habilita al compilador para NO aceptar conversiones INDESEABLES a float de otros tipos
    explicit Circle(const float radius);

    ~Circle();

    // getters y setters
    float gRadius();
    void sRadius(float nr);

    void resize(float factor);
    virtual string toString() const override;
	
private:
    float radius;
};


Circle::Circle() : radius{ 10 }
{
}

Circle::Circle(float radius) : radius{ radius }
{
}

Circle::~Circle()
{
    cout << "destruye circulo de radio: " << radius << endl;
}

float Circle::gRadius()
{
    return radius;
}

void Circle::sRadius(float nr)
{
    radius = nr;
}

string Circle::toString() const
{
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
}

void Circle::resize(float factor)
{
    radius *= factor;
}