# BitNine Fibonacci Calculator

This repository contains a C program that performs basic arithmetic operations and calculates the Fibonacci sequence. The program utilizes a custom data structure called Node to represent different types of operations and values.

## Prerequisites

Make sure you have the following installed on your system:

* C Compiler (e.g., GCC)

## How to Run
* Clone or download the repository to your local machine.

* Open a terminal or command prompt and navigate to the downloaded repository folder.

* Compile the C program using the C compiler:
  
```
gcc -o arithmetic_operations arithmetic_operations.c
```
* Run the compiled executable:
```
./arithmetic_operations

```
## Code Description
The C program contains the following components:

### Custom Data Structure
* Node: A struct that represents an operation or a value in the arithmetic expression. 
It has the following members:
  * type: An enumeration that indicates the type of the node (ADD, MUL, SUB, FIBO).
  * value: An integer that stores the result of the operation or the value.
  * operands: A union containing fields specific to each type of operation.

### Arithmetic Operations
The program defines three arithmetic functions and a Fibonacci function:

* addFunc: Function to perform addition.
* subFunc: Function to perform subtraction.
* mulFunc: Function to perform multiplication.
* fibonacci: Function to calculate the Fibonacci sequence.
  
### Function Pointer and Operation Mapper
OperationFunc: A function pointer type that takes two void* arguments and returns a Node*.
makeFunc: A function that returns the appropriate function pointer based on the provided operation code.

### Calculation and Printing

* calc: A function to extract the final result of the calculation from a Node.
* main: The main function that demonstrates how to use the custom data structure and arithmetic functions. It performs addition, multiplication, and subtraction on two pairs of integers and calculates the Fibonacci sequence based on the results.

#### Example Output
The program will print the results of each arithmetic operation and the Fibonacci sequence:
The results for this program should look like this:
```
add : 16
mul : 20
sub : 4
fibo : 3
```
#### Notes
* The MAX_SIZE constant defines the maximum size for memoization in the Fibonacci function. This is to enforce the dynamic approach to implementing the fibonnaci sequence.
* The program uses dynamic memory allocation (malloc) for each Node, so make sure to free the allocated memory after use.
