#pragma once
#include <string>
using namespace std;

class Shape
{
public:
	//Shape() {}; // Aunque no crea ning�n objeto permitir�a inicializar atributos
	virtual ~Shape() {}; // s�lo es necesario para que funcione el enlace din�mico de los destructores de clases derivadas
	virtual string toString() const = 0;
};
// NOTA: el archivo Shape.cpp no hace falta porque NO hay ning�n m�todo que NO sea virtual puro.
// En caso de que una clase abstracta tenga alg�n m�todo que no es virtual puro, se debe agregar el archivo cpp.
