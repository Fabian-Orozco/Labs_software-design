/* 
 * File:   main.cpp
 * Author: calderon
 *
 * Created on 1 de junio de 2012, 06:01 PM
 */

#include <cstdlib>
#include "EnchantedMazeFactory.h"
#include "BombedMazeFactory.h"
#include "MazeGame.h"

#include "ConstructorSerializadorAbstracto.h"
#include "ConstructorSerializadorConcretoJSON.h"
#include "ConstructorSerializadorConcretoXML.h"

#include "Maze.h"

#include <iostream>
using namespace std;

string director(ConstructorSerializadorAbstracto& constructorAbstracto, Maze* maze);
void elegirFabrica(EnchantedMazeFactory& enchantedFactory, BombedMazeFactory& BombedFactory, MazeGame& mazeGame);

void elegirFormato(ConstructorSerializadorJSON& json, ConstructorSerializadorXML& xml, MazeGame& mazeGame);

/*
 * 
 */
int main(int argc, char** argv) {
    EnchantedMazeFactory enchantedFactory;
    BombedMazeFactory BombedFactory;
    MazeGame mazeGame;

    ConstructorSerializadorJSON json;
    ConstructorSerializadorXML xml;
    elegirFabrica(enchantedFactory, BombedFactory, mazeGame);
    elegirFormato(json, xml, mazeGame);
    cout << "----------------------------------------------------------------------------" << endl;
    
    return 0;
}

string director(ConstructorSerializadorAbstracto& constructorAbstracto, Maze * maze) {
    vector<Room *> rooms =  maze->getAtributtes();
    constructorAbstracto.inicioObjeto("Maze");
    for (int i = 0; i < rooms.size(); ++i) {
        constructorAbstracto.serializarRoom(rooms[i]);
    }
    constructorAbstracto.finObjeto();
    return constructorAbstracto.obtSerializacion();
}

// escoge tipo de laberinto
void elegirFabrica(EnchantedMazeFactory& enchantedFactory, BombedMazeFactory& BombedFactory, MazeGame& mazeGame) {
    /* pedir al usuario el tipo de laberinto */

    int opcionDeUsuario = 0;
    cout << "\nSeleccione el tipo de laberinto\n1. Laberinto encantado\n2. Laberinto con bombas\n > ";
    cin >> opcionDeUsuario;
   
    while(true) {
        if (opcionDeUsuario >= 1 && opcionDeUsuario <= 2) {
            cout << "----------------------------------------------------------------------------" << endl;
            if (opcionDeUsuario == 1) { // si el usuario escoge laberinto encantado
                mazeGame.createMaze(&enchantedFactory);  // 7 rooms. Cada room con 2 puertas.
            }
            else { // si el usuario escoge laberinto con bombas
                mazeGame.createMaze(&BombedFactory);  // 7 rooms. Cada room con 2 puertas.
            }
            cout << mazeGame.toString() << endl;
            break;
        }
        else {
            cout << "Ingrese 1 o 2\n > ";
            cin >> opcionDeUsuario;
        }
    }
}

// escoge formato de guardado
void elegirFormato(ConstructorSerializadorJSON& json, ConstructorSerializadorXML& xml, MazeGame& mazeGame) {
    /* pedir al usuario el tipo de laberinto */
    int opcionDeUsuario = 0;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Juego de laberinto creado: 7 salas creadas con 2 puertas cada una.\nSeleccione el formato de guardado.\n1. JSON\n2. XML\n > ";
    cin >> opcionDeUsuario;
    while(true){
        if (opcionDeUsuario >= 1 && opcionDeUsuario <= 2) {
            cout << "----------------------------------------------------------------------------" << endl;
            if (opcionDeUsuario == 1) {  // selecciona json
                cout << director(json, mazeGame.getAtributtes()) << endl;
            }
            else {  // selecciona xml
                cout << director(xml, mazeGame.getAtributtes()) << endl;
            }
            break;
        }
        else {
            cout << "Ingrese 1 o 2\n > ";
            cin >> opcionDeUsuario;
        }
    }
}