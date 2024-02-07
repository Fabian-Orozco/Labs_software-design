#pragma once
#include <string>
using namespace std;

class Neuron;

class Neurons
{
public:
	Neurons();
	~Neurons();

	virtual Neuron* begin() = 0;
	virtual Neuron* end() = 0;
	virtual Neuron* next() = 0;
	virtual void connect_to(Neurons* other) = 0;
	virtual string toString() = 0;
};

Neurons::Neurons()
{
}

Neurons::~Neurons()
{
}
