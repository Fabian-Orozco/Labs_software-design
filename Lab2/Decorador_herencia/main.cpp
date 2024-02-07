#include <iostream>
using namespace std;

#include "Shape.h"
#include "Circle.h"
#include "ColoredShape.h"
#include "TransparentShape.h"

int main() {
	Circle circle{ 0.5f }; // se crea un cículo
	cout << circle.toString() << endl;

	ColoredShape redCircle{ circle, "red" }; // se decora con color
	cout << redCircle.toString() << endl;
	cout << circle.gRadius() << endl;
	
	TransparentShape demiCircle{ circle, 85 }; // se decora con transparencia
	cout << demiCircle.toString() << endl;

	ColoredShape greenRedCircle{ redCircle, "green" };
	cout << greenRedCircle.toString() << endl;
	
	TransparentShape demiRedCircle{ redCircle,85 };
	cout << demiRedCircle.toString() << endl;

	Shape& s = *(new ColoredShape{ *(new Circle{0.3f}), "black" });
	Shape& s2 = *(new TransparentShape{ *(new ColoredShape{ *(new Circle{0.3f}), "black" }), 2 });
	Shape& s3 = *(new ColoredShape{ *(new TransparentShape{*(new Circle{25.5f}),70}),"green" });
	cout << s.toString() << endl;
	
	// se pueden componer figuras coloreadas con figuras transparentes en una sola creación:
	TransparentShape circuloDecorado {
		*(new ColoredShape { *(new Circle{23}), "green"}), 64
	};

	cout << circuloDecorado.toString() << endl;
	cout << s.toString() << endl;
	cout << s2.toString() << endl;
	
	cin.ignore();
}