#include <iostream>
using namespace std;

#include "Shape.h"
#include "Circle.h"
#include "ColoredShape.h"
#include "TransparentShape.h"

int main() {
    Circle c1{ 5 };
    ColoredShape< Circle > c1coloreado{ "green",c1 };
    cout << c1coloreado.toString() << endl;
    ColoredShape< Circle > circleBlue{"blue", 10};
    cout << circleBlue.toString() << endl;
    cout << circleBlue.gColor() << endl;
    // se logra porque ColoredShape hereda públicamente de T!! Y no requiere que el decorador incluya el método del decorado:
    cout << circleBlue.gRadius() << endl;
    
    // a continuación se logran tres niveles de composición!!!
    TransparentShape< ColoredShape< Circle > > circleTransparentBlue{ 85, "black", 20 };
    cout << circleTransparentBlue.toString() << endl;
    cout << unsigned(circleTransparentBlue.gTransparency()) << endl; // se necesita unsigned para que uint8_t se visualice adecuadamente
    cout << circleTransparentBlue.gTransparency() << endl;
    cout << circleTransparentBlue.gColor() << endl;
    cout << circleTransparentBlue.gRadius() << endl;

    ColoredShape< TransparentShape < Circle >> transparentRedCircle{ "red", 75, 30 };
    cout << transparentRedCircle.toString() << endl;

    Circle c(45);
    ColoredShape< Circle > circuloAzul{ "azul",c };

	cin.ignore();
}