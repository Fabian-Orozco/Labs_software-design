# Builder Pattern Lab

## Objectives

Students will:

1. Learn to apply a creational pattern to a specific design context.
2. Understand the details of the "Builder" pattern.

## Context and Problem Statement

Building upon the maze game design and monsters, and based on the class model used as an example for the Abstract Factory pattern (Maze, Room, Door, Mapsite, Wall, etc.), this lab requires saving a maze (Maze) so that it can be shared among game enthusiasts. The task is to create a textual representation of a maze based, for example, on XML or JSON, which can then be copied and loaded into another enthusiast's gaming station, allowing the latter to play using it. Currently, these two formats (XML and JSON) are considered essential, but the possibility of adding other standard formats in the future without altering the code that generates the textual representation is desired.

## Solution Characteristics

A solution must be generated based on the Builder pattern so that:

1. The design must respect SOLID principles.
2. The design must be based on the correct application of the Builder pattern.
3. The code should function correctly as a proof of concept, as shown in the examples. The controller must demonstrate that: 1) it is possible to dynamically select which format to use to create the exportable textual representation, 2) it is possible to represent the different components of a maze (Maze, Room, Door, Mapsite, Wall, etc.) according to the selected format (XML or JSON), 3) it is possible to visualize the complete text representing a maze via console at the end, corresponding to the selected format, 4) it is possible to create a textual representation for a maze using each of these two formats, and 5) the minimum maze must include seven interconnected Rooms with at least two Rooms each, 6) the maze can be booby-trapped or enchanted.
4. Include the class model in PDF format.

---

## Compilar con

g++ main.cpp -o program

## Ejecutar con

./program

## Uso del programa

Al principio se pide digitar 1 o 2 para escoger el tipo de laberinto.

    1: Es laberinto encantado
    2: Es laberinto con bombas

Luego de mostrar la construcción del laberinto se pide digitar 1 o 2 para escoger en que formato se desea serializar el laberinto.

    1: Formato Json
    2: Formato XML

## Créditos

Fabián Orozco Chaves - B95690 <fabian7orozco@gmail.com>

Daniel Escobar Giraldo - C02748

Manuel Arroyo Portilla - A80675
