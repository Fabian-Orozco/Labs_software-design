#pragma once
#include <vector>
using namespace std;

#include "Neuron.h"
#include "Neurons.h"

class NeuronLayer : public Neurons
{
public:
	// Construye una NeuronLayer con "count" neuronas.
	NeuronLayer(int count);
	~NeuronLayer();

	unsigned int gId();
	Neuron* begin() override;
	Neuron* end() override;
	Neuron* next() override;
	void connect_to(Neurons* other) override;
	string toString() override;

private:
	static unsigned int idg;

	int id;
	vector< Neuron > neuronas;
	int pos;
	Neuron* cursor;
};

// Definición de variables static:
unsigned int NeuronLayer::idg = 0;

NeuronLayer::NeuronLayer(int count)
{
	this->id = NeuronLayer::idg++;
	while (count-- > 0)
		neuronas.emplace_back(Neuron{});
	pos = 0;
	cursor = &neuronas[pos];
}

NeuronLayer::~NeuronLayer()
{
}

unsigned int NeuronLayer::gId()
{
	return id;
}


Neuron* NeuronLayer::begin()
{
	pos = 0;
	cursor = &neuronas[pos];
	return cursor;
}

Neuron* NeuronLayer::end()
{
	return 0;
}

Neuron* NeuronLayer::next()
{
	if (pos < neuronas.size() - 1) {
		pos++;
		cursor = &neuronas[pos];
	}
	else cursor = 0;
	return cursor;
}

void NeuronLayer::connect_to(Neurons* other)
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

string NeuronLayer::toString()
{
	ostringstream salida;
	salida << "Capa neuronal id: " << id << endl;
	for (auto n : neuronas)
		salida << n.toString();
	return salida.str();
}