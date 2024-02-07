# Decorator Pattern Lab

## Objectives

1. Learn to apply a structural pattern to a specific design context.
2. Understand the details of the "Decorator" pattern in both its dynamic and static versions.

## Context and Problem Statement

In the context of the maze game design, Hunter, and monsters, it is required for this lab that under certain conditions (irrelevant for this lab), monsters and packs can acquire new powers such as:

1. INVISIBILITY: allowing them to be invisible to the Hunter.
2. REPLICABILITY: allowing them to replicate at will.
3. MEMORY: already incorporated in a previous lab, but now assuming not all monsters and packs have memory at the beginning and gain it at some point during the game.
   A monster or pack could have several of these powers, acquired one by one. These three are not the only powers; others could be added in the future. Additionally, they must be acquirable by all types of monsters (Wumpus, Cadejos, and future ones) and their corresponding packs.

## Solution Characteristics

Two solutions must be generated, one based on the static version of the Decorator and the other based on the dynamic version of the Decorator. In both cases:

1. The design must respect SOLID principles.
2. The design must be based on the correct application of the Decorator pattern.
3. The code should function correctly as a proof of concept, as shown in the examples. The controller must demonstrate that monsters and packs can be created, they can acquire one or more powers in any combination, and they respond to the activation/deactivation of powers once acquired.
4. Include the class model in PDF format.

Author:

- Fabián Orozco Chaves | <fabian7orozco@gmail.com>
