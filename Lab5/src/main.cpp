#include "Racional.h"
#include "Doble.h"
#include "Conjunto.h"
#include <set>
#include <sstream>

#include<iostream>
using namespace std;

void probarOperando(Operando& x, Operando& y) {
   cout << "---------------------------------------" << endl;
   cout << "Prueba de operando:\n" << endl;
   cout << "x: " << x.toString() << " | y: " << y.toString() << endl;
   cout << "Operando sobre (x) y (y)" << endl;
   Operando& suma = x + y;
   Operando& resta = x - y;
   Operando& multiplicacion = x * y;
   Operando& division = x / y;
   cout << "Suma: " << suma.toString() << "\nResta: " << resta.toString()  << "\nMultiplicacion: " << multiplicacion.toString()  << "\nDivision: " << division.toString()  << endl;
   cout << "---------------------------------------" << endl;
}

void run() {
   // probamos Racionales
   Racional r1(5,3);
   Racional r2(6,12);
   probarOperando(r1, r2);

   // Probamos Dobles
   Doble d1(2.5);
   Doble d2(40.3);
   probarOperando(d1, d2);

   // probamos conjuntos
   Conjunto set1{ set<int> { 1, 2 } };
   Conjunto set2{ set<int> { 3, 4, 1 } };
   probarOperando(set1, set2);

   // Probamos evaluar posfijo
   Doble d3(3);
   Doble d4(4);
   Doble d5(5);

   Racional r3(3,5);
   Racional r4(4,6);
   Racional r5(5,7);

   Conjunto set3{ set<int> { 5, 6, 7 } };
   Conjunto set4{ set<int> { 2, 4 } };
   Conjunto set5{ set<int> { 7, 5 } };

   cout << "\nEvaluando posFijo" << endl;
   Doble general;
   // llena el mapa
   general.setVar("d1",d1);
   general.setVar("d2",d2);
   general.setVar("d3",d3);
   general.setVar("d4",d4);
   general.setVar("d5",d5);
   general.setVar("r1",r1);
   general.setVar("r2",r2);
   general.setVar("r3",r3);
   general.setVar("r4",r4);
   general.setVar("r5",r5);
   general.setVar("set1",set1);
   general.setVar("set2",set2);
   general.setVar("set3",set3);
   general.setVar("set4",set4);
   general.setVar("set5",set5);

   string resultado = general.evaluarPosfijo("d1 d2 * d3 / d4 + d5 -");
   cout << "Resultado final: " << resultado << endl;
   cout << "\n---------------------------------------\n" << endl;

   resultado = general.evaluarPosfijo("r1 r2 * r3 / r4 + r5 -");
   cout << "Resultado final: " << resultado << endl;
   cout << "\n---------------------------------------\n" << endl;
   
   resultado = general.evaluarPosfijo("set1 set2 * set3 / set4 + set5 -");
   cout << "Resultado final: " << resultado << endl;
   
}

int main(){
   cout << "\n    | Start |" << endl;

   run();

   cout << "\n   | End |" << endl;

   return 0;
}
