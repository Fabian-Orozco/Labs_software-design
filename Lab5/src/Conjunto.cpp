#include "Conjunto.h"
#include <vector>

Conjunto::Conjunto() { }

Conjunto::Conjunto(set<int> d) : valor(d) { }

Conjunto::~Conjunto() { }

string Conjunto::toString() {
  string temp = "[";
  set<int>::iterator it = valor.begin();
  if(it != valor.end()){
	temp += to_string(*it++);
	for ( ; it!=valor.end(); ++it){
		temp += ", " + to_string(*it);
	}
  }
  temp += "]";
  return temp;
}

Conjunto& Conjunto::operator+(Operando& otro ) {
  Conjunto * resultado = new Conjunto();

  Conjunto * conjunto = dynamic_cast<Conjunto*>(&otro);
  vector<int> v2 ( conjunto->valor.size() + this->valor.size() );
  std::vector<int>::iterator it = set_union(this->valor.begin(), this->valor.end(), conjunto->valor.begin(), conjunto->valor.end(), v2.begin());
  v2.resize(it-v2.begin());
  std::copy(v2.begin(), v2.end(), std::inserter(resultado->valor,resultado->valor.end()));
  return *resultado;
}

Conjunto& Conjunto::operator-(Operando& otro ) {
  Conjunto * resultado = new Conjunto();

  Conjunto * conjunto = dynamic_cast<Conjunto*>(&otro);
  vector<int> v2 ( conjunto->valor.size() + this->valor.size() );
  std::vector<int>::iterator it = set_difference(this->valor.begin(), this->valor.end(), conjunto->valor.begin(), conjunto->valor.end(), v2.begin());
  v2.resize(it-v2.begin());
  std::copy(v2.begin(), v2.end(), std::inserter(resultado->valor,resultado->valor.end()));
  return *resultado;
}

Conjunto& Conjunto::operator*(Operando& otro) {
  Conjunto * resultado = new Conjunto();

  Conjunto * conjunto = dynamic_cast<Conjunto*>(&otro);
  vector<int> v2 ( conjunto->valor.size() + this->valor.size() );
  std::vector<int>::iterator it = set_intersection(this->valor.begin(), this->valor.end(), conjunto->valor.begin(), conjunto->valor.end(), v2.begin());
  v2.resize(it-v2.begin());
  std::copy(v2.begin(), v2.end(), std::inserter(resultado->valor,resultado->valor.end()));
  return *resultado;
}

Conjunto& Conjunto::operator/(Operando& otro) {
  Conjunto * resultado = new Conjunto();

  Conjunto * conjunto = dynamic_cast<Conjunto*>(&otro);
  vector<int> v2 ( conjunto->valor.size() + this->valor.size() );
  std::vector<int>::iterator it = set_symmetric_difference(this->valor.begin(), this->valor.end(), conjunto->valor.begin(), conjunto->valor.end(), v2.begin());
  v2.resize(it-v2.begin());
  std::copy(v2.begin(), v2.end(), std::inserter(resultado->valor,resultado->valor.end()));
  return *resultado;
}

