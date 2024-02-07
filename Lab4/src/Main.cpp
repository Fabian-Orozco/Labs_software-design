/* Prueba de concepto
Compilar con: g++ *.cpp -o program
Ejecutar con: ./program
Autores: Fabián Orozco Chaves - Daniel Escobar Giraldo - Manuel Arroyo.
 */
#include "Wumpus.h"
#include "Cadejo.h"
#include "MM.h"
#include "Cazador.h"

#include <iostream>
using namespace std;

// =============================================================================
// crea el monstruo tipo <T> y lo une al vector y a la manada pasados por parámetro.
template < typename T >
void crearMonstruos(vector <T *> & vtr, MM & manada, int & cantidad, int & ids);

// libera la memoria de un vector creado con objetos dinámicos
template < typename T >
void liberarMemoria(vector <T *> & vtr);

void run();

// =============================================================================

int main() {
  cout << "\n    | Start |" << endl;

  run();
  
  cout << "\n   | End |" << endl;
}

// =============================================================================
void run() {

  int ids = 0;

  // creación de manada y vector de wumpus
  int cantidadWumpus = 3;
  vector<Wumpus *> wumpus_vtr;
  MM manadaWumpus(++ids);
  ids = 2;  // el 2 es para manada de cadejos

  cout << "\nSe crean " << cantidadWumpus <<  " wumpus" << endl;
  crearMonstruos(wumpus_vtr, manadaWumpus, cantidadWumpus, ids);

  cout << "\nSe crea una manada de Wumpus " << endl;
  cout << manadaWumpus.toString() << endl;
  
  // -----------------------------------------------------------------
  cout << "\n===============================================" << endl;

  // creación de manada y vector de cadejos
  int cantidadCadejos = 3;
  vector<Cadejo *> cadejos_vtr;
  MM manadaCadejos(2);  // id puesto manualmente por estética.

  cout << "Se crean " << cantidadCadejos <<  " cadejos" << endl;
  crearMonstruos(cadejos_vtr, manadaCadejos, cantidadCadejos, ids);

  cout << "Se crea una manada de Cadejos " << endl;
  cout << manadaCadejos.toString() << endl;

  // -----------------------------------------------------------------
  cout << "\n===============================================" << endl;

  cout << "Envio de mensajes\n" << endl;
  int wumpusEjemplo = wumpus_vtr[0]->getCurrentID();

  cout << "Wumpus {" << wumpusEjemplo << "} intenta enviar un mensaje:" << endl;
  wumpus_vtr[0]->enviarMensaje("Encontre al cazador.");
  cout << "\nWumpus {" << wumpusEjemplo << "} se desagrega de su manada" << endl;
  wumpus_vtr[0]->unsetManada();
  cout << "\nWumpus {" << wumpusEjemplo << "} intenta enviar un mensaje a su manada:" << endl;
  wumpus_vtr[0]->enviarMensaje("Encontre al cazador.");
  
  cout << "\nNota: Un monstruo no puede enviar un mensaje fuera de la propia manada." << endl;

  // -----------------------------------------------------------------
  // liberación de memoria
  liberarMemoria(wumpus_vtr);
  liberarMemoria(cadejos_vtr);
}

// =============================================================================
template < typename T >
void crearMonstruos(vector <T *> & vtr, MM & manada, int & cantidad, int & ids) {
  for (int i = 0; i < cantidad; ++i) {
    T * wumpusActual = new T(++ids);
    wumpusActual->setManada(&manada);
    vtr.push_back(wumpusActual);
    cout << wumpusActual->toString() << endl;
  }
}

// =============================================================================
// libera la memoria de un vector creado con objetos dinámicos
template < typename T >
void liberarMemoria(vector <T *> & vtr) {
  for (int i = 0; i < vtr.size(); ++i) {
    delete vtr[i];
  }
}
