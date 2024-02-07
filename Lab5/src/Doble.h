#ifndef DOBLE_H
#define DOBLE_H

#include <string>
#include "Operando.h"
using namespace std;

class Doble : public Operando{
	private:
		double valor;

	public:
		Doble();
		Doble(double d);
		~Doble();
		string toString();
		Doble& operator+(Operando &);
		Doble& operator-(Operando &);
		Doble& operator*(Operando &);
		Doble& operator/(Operando &);
};

#endif