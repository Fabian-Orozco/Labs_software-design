#ifndef _RACIONAL
#define _RACIONAL

#include "Operando.h"
#include<iostream>
#include<string>
using namespace std;

class Racional : public Operando{
   private:
      int numerador;
      int denominador;

      Racional& _init(int,int); 
      int _mcd(int,int);
      Racional& _simplificar();

   public:
      Racional(int,int);
      ~Racional();
      string toString();

      Racional& operator+(Operando&);
      Racional& operator-(Operando&);
      Racional& operator*(Operando&);
      Racional& operator/(Operando&);

};

#endif
