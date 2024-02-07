#include <iostream>
using namespace std;

#include "Neuron.h"
#include "NeuronLayer.h"

int main() 
{
	Neuron n1, n2;
	NeuronLayer nl1(3), nl2(3);

	n1.connect_to(&n2);
	n1.connect_to(&nl1);
	nl2.connect_to(&n2);
	nl1.connect_to(&nl2);

	cout << "**** INICIO ****" << endl;
	cout << n1.toString() << endl;
	cout << n2.toString() << endl;
	cout << nl1.toString() << endl;
	cout << nl2.toString() << endl;
	cout << "**** FIN ****" << endl;
	cin.ignore();
}