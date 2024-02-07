#include "Racional.h"
#include<iostream>
using namespace std;

string Racional::toString(){
   string result = to_string(numerador);
   
   if(denominador!=1){
      result = result + "/" + to_string(denominador);
   }
   return result;
}

Racional& Racional::_init(int numerador, int denominador){
   this->numerador = numerador;
   if(denominador){
      this->denominador = denominador;
   }
   else {
      this->denominador = 1;
      cerr << "Warning: Forzado denominadorominador 0 a 1"<< endl;
   }
   _simplificar();
   return *this;
}
      
Racional& Racional::_simplificar(){
   int x = _mcd(numerador,denominador);
   numerador/=x;
   denominador/=x;
   if(denominador<0){
      numerador*= -1.0;
      denominador*= -1.0;
   }
   return *this;
}

int Racional::_mcd(int x, int y){
    int resp;
    if(y==0){
       resp = x;
    }
    else {
       resp = _mcd( y , x%y);
    }
    return resp;
}

Racional::Racional(int numerador, int denominador){
   _init(numerador,denominador);
}

Racional::~Racional(){ }

Racional& Racional::operator+(Operando& otro) {
   Racional * racional = dynamic_cast<Racional*>(&otro);
   Racional * result = new Racional(this->numerador * racional->denominador + this->denominador * racional->numerador, this->denominador * racional->denominador);
   return *result;
}

Racional& Racional::operator-(Operando& otro){	
   Racional * racional = dynamic_cast<Racional*>(&otro);
   Racional * result = new Racional(numerador * racional->denominador - denominador * racional->numerador   , denominador * racional->denominador);
   return *result;
}

Racional& Racional::operator*(Operando& otro){
   Racional * racional = dynamic_cast<Racional*>(&otro);
   Racional * result = new Racional(numerador * racional->numerador ,  denominador * racional->denominador);
   return *result;
}
      
Racional& Racional::operator/(Operando& otro){
   Racional * racional = dynamic_cast<Racional*>(&otro);
   Racional * result = new Racional(this->numerador*racional->denominador, this->denominador*racional->numerador); 
   return *result;
}
