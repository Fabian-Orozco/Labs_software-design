#pragma once
#include <string>
using namespace std;

class Shape
{
public:
	// NO DEBEN declararse ni constructores ni destructores para una clase abstracta porque nunca se van a crear instancias!!
	//Shape();
	//~Shape();
	virtual string toString() const = 0;
};
// NOTA: el archivo Shape.cpp no hace falta porque NO hay ningún método que NO sea virtual puro.
// En caso de que una clase abstracta tenga algún método que no es virtual puro, se debe agregar el archivo cpp.
