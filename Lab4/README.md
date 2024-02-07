# Mediator Pattern Lab

## Objectives

1. Learn to apply a behavioral pattern to a specific design context.
2. Understand the details of the "Mediator" pattern.

## Context and Problem Statement

Building upon the maze game design, monsters, and packs, and based on the solution provided in the first lab (with any recommended improvements), this lab requires implementing a new basic capability for monsters organized in packs: message passing. The idea is that a monster can send messages to other monsters in the pack about game states such as: where it thinks the Hunter is, if it has detected monsters or packs of other classes, if it has found traps placed by the Hunter in a cave, which cave connects to which (maze structure), etc. The detail of the messages doesn't matter; what matters is the functionality. A monster cannot send messages to members of other packs, only its own. A completely solitary monster cannot send messages at all. Remember that the formation of packs is entirely dynamic, cannot be predetermined at compile time, and a monster is always free to disaggregate or aggregate at any time.

## Solution Characteristics

A solution must be generated based on the Mediator pattern so that:

1. The design must respect SOLID principles.
2. The design must be based on the correct application of the Mediator pattern.
3. The code should function correctly as a proof of concept, as shown in the examples. The controller must demonstrate that: 1) a monster in a pack can send messages to the others ONLY from its own pack, 2) ALL other monsters in a pack effectively receive the message sent previously by another, 3) a completely solitary monster cannot send messages to any other. The detail of the different types of messages doesn't matter; only the ability to send messages matters, so sending/receiving strings will suffice.
4. Include the class model in PDF format.

---

## Compilar con

`g++ *.cpp -o program`

## Ejecutar con

`./program`

## Créditos

Fabián Orozco Chaves - B95690 | <fabian7orozco@gmail.com>
Daniel Escobar Giraldo - C02748  
Manuel Arroyo Portilla - A80675
