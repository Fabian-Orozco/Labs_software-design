#pragma once
#include <sstream>
#include <iostream>
using namespace std;

#include "Shape.h"

template < typename T >
class TransparentShape : public T
{
    // Impide que se use TransparentShape con un tipo T que NO herede de Shape!!!
    static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");
    
public:
    // el uso de ...Args permite que toda una lista de parámetros sea pasada a T mediante constructores "forward".
    template < typename ...Args >    
    TransparentShape(const uint8_t transparency, Args ...args) : transparency{ transparency }, T(std::forward<Args>(args)...){
    };
    
    ~TransparentShape(){
    }

    string toString() const override {
        ostringstream oss;
        oss << T::toString() << " has " << static_cast<float>(transparency) / 255.f*100.f << "% transparency";
        return oss.str();
    }
    
    uint8_t gTransparency() const {
        return transparency;
    }
    
private:
    uint8_t transparency;
};
