#pragma once
#include <sstream>
#include <iostream>
using namespace std;

#include "Shape.h"

template < typename T >
class ColoredShape : public T
{
    // Impide que se use ColoredShape con un tipo T que NO herede de Shape!!!
    static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");
    
public:
    // el uso de ...Args permite que toda una lista de parámetros sea pasada a T mediante constructores "forward".
    template < typename ...Args >
    ColoredShape(const string& color, Args ...args) : T(std::forward<Args>(args)...), color{ color } {
    };
    
    ~ColoredShape(){
    };
        
    string toString() const override {
        ostringstream oss;
        oss << T::toString() << " has the color " << color;
        return oss.str();
    }
    
    string gColor() const {
        return color;
    }
    
private:
	string color;
};

