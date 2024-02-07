#include "Operando.h"
#include <map>
#include <stack>
#include <sstream>

// método plantilla
string Operando::evaluarPosfijo(string operation) {
  istringstream operacion(operation);
  cout << "Operacion: " << operacion.str() << "\n" << endl;
    // 2+2-1*2/4
  stack<Operando*> pila;
  string symbol = "";
  while(!operacion.eof()) {
    operacion >> symbol;
    if (isOperator(symbol)) {
      cout << "Calculando " << symbol << " ";

      Operando& op1 = *pila.top();
      pila.pop();
      Operando& op2 = *pila.top();
      pila.pop();

      Operando& result = operar(op2, op1, symbol[0]);
      pila.push(&result);
    } 
    else {
      pila.push(&variables.at(symbol));
    }
    printStack(pila);
  }
  
  string resultado = (pila.top())->toString();
  pila.pop();
  return resultado;
}

void Operando::setVar(string key, Operando& operando) {
  this->variables.insert(pair<string, Operando&>(key,operando));
}


Operando& Operando::getVar(string key) {
  return this->variables.at(key);
}

Operando& Operando::operar(Operando& operando1, Operando& operando2, char oper) {
  switch (oper) {
  case '-':
    return operando1 - operando2;
    break;
  case '*':
    return operando1 * operando2;
    break;
  case '/':
    return operando1 / operando2;
    break;
  default:
    return operando1 + operando2;
    break;
  }
}

bool Operando::isOperator(string symbol) {
  return (symbol == "+" || symbol == "-" || symbol == "/" || symbol == "*");
}

void Operando::printStack(stack<Operando*> pila) {
  cout << "Pila: ";
  // como es por copia, no le afecta el pop
  while( !pila.empty() )
  {
    Operando& operando = *pila.top();
    pila.pop();
    cout << operando.toString() << "  ";
  }
  cout << "\n"<< endl;
}