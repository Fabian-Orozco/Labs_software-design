# Template Method Pattern Lab

## Objectives

Students will:

1. Learn to apply a behavioral pattern to a specific design context.
2. Understand the details of the "Template Method" pattern.

## Problem Statement

Design a small library with classes representing "operands" in general, on which the four basic operations can be applied: +, -, \*, and /. Add the evaluation of postfix expressions for at least three types of operands:

1. Double numbers: use an Adapter or "Wrapper" of the primitive type "double".
2. Fractions: 1/2, 3/5, etc., create the Racional or Fraction class.
3. Sets: extend [set] from the STL by overloading operators. In this case, the addition operator will represent the union of sets, the multiplication operator the intersection, the subtraction operator the difference, and the division operator the symmetric difference.
   NOTE: for all types of operands, the evaluation of postfix expressions should return a value of the same type as the operands, which can be visualized by console using "toString()", as a character string.

## Solution Characteristics

1. It must use the Template Method pattern so that the code for evaluating postfix expressions is polymorphic code that allows dynamic binding and can work with any other type of operand added in the future.
2. Clearly, a class is needed for each type of operand.
3. It should be based on the algorithm for evaluating postfix expressions at: [Wikipedia Stack (computer science)](<https://en.wikipedia.org/wiki/Stack_(abstract_data_type)>).
4. Simplify the analysis of the postfix string as much as possible, assuming it is well constructed. It is suggested that the postfix evaluator code be based on expressions based solely on variables, so that a different analysis is not needed for each type of operand.
5. The controller or main() function must demonstrate that: 1) operands of the three types can be created, 2) postfix expressions can be correctly processed for each type of operand, 3) at least one of the postfix expressions for each type of operand includes all four operators. For the particular case of sets, the main function will demonstrate its use by specializing [set] with the type "int".
6. The Template Method cannot be a method that receives a type parameter, nor a function with a type parameter, nor belong to a templated class that receives a type parameter.

## Compilar con

`g++ *.cpp -o program`

## Ejecutar con

`./program`

## Créditos

Fabián Orozco Chaves - B95690 | <fabian7orozco@gmail.com>
Daniel Escobar Giraldo - C02748  
Manuel Arroyo Portilla - A80675
