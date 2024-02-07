#pragma once
#include <string>
using namespace std;

class Shape
{
public:
	//Shape() {}; // Aunque no crea ningún objeto permitiría inicializar atributos
	virtual ~Shape() {}; // sólo es necesario para que funcione el enlace dinámico de los destructores de clases derivadas
	virtual string toString() const = 0;
};
// NOTA: el archivo Shape.cpp no hace falta porque NO hay ningún método que NO sea virtual puro.
// En caso de que una clase abstracta tenga algún método que no es virtual puro, se debe agregar el archivo cpp.
