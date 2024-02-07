#pragma once
#include <vector>
#include <sstream>
using namespace std;

#include "Neurons.h"

class Neuron : public Neurons
{
public:
	Neuron();
	~Neuron();

	unsigned int gId();
	void out_push_back(Neuron& other);
	void in_push_back(Neuron& other);
	Neuron* begin() override;
	Neuron* end() override;
	Neuron* next() override;
	void connect_to(Neurons* other) override;
	string toString() override;

private:
	static unsigned int idg;

	unsigned int id;
	Neuron* cursor;
	vector<Neuron> in, out;
};

// Definición de variables static:
unsigned int Neuron::idg = 0;

// Definición de métodos:
Neuron::Neuron()
{
	this->id = Neuron::idg++;
	cursor = this;
}


Neuron::~Neuron()
{
}

unsigned int Neuron::gId()
{
	return id;
}

void Neuron::out_push_back(Neuron& other)
{
	out.push_back(other);
}

void Neuron::in_push_back(Neuron& other)
{
	in.push_back(other);
}

Neuron* Neuron::begin()
{
	cursor = this;
	return cursor;
}

Neuron* Neuron::end()
{
	return 0;
}

Neuron* Neuron::next()
{
	cursor = 0;
	return cursor;
}

void Neuron::connect_to(Neurons* other)
{
	Neuron* from = this->begin();
	while (from != 0) {
		Neuron* to = other->begin();
		while (to != 0) {
			from->out_push_back(*to);
			to->in_push_back(*from);
			to = other->next();
		}
		from = this->next();
	}
}

string Neuron::toString()
{
	ostringstream salida;
	salida << "Neurona id: " << id << endl;
	salida << "ids entrantes: " << endl;
	for (auto n : in)
		salida << n.gId() << ",";
	salida << endl;
	salida << "ids salientes: " << endl;
	for (auto n : out)
		salida << n.gId() << ",";
	salida << endl; salida << endl;
	return salida.str();
}