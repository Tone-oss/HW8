Author: AnthonySesay
Assignment: C vs C++

This assignment requires me to create a set of matrix functions in C and C++. The arrays must
be able to handle "any matrix equation that involves (a) matrix addition, (b) scalar matrix multiplication, (c) matrix transposition, and (d) matrix multiplication". So I had to use dynamic memory allocation. In order for that to work and the arrays to handle matrices of any size, the matrix has to be a int**. That means that the passed in matrix cannot be statically defined, or it really wouldn't be able to handle any matrix equation. In both files, there is a main that shows how the functions are expected to be used.  

MatrixFunctions.c: The functions in C code. Uses globle variables as array sizes. Includes
an example in main that shows how each function is used to modify the final result

MatrixFunctions.cpp: The functions in C++ code. Uses classes to encapsulate the functions and then are called in an object. 
Includes an example in main that shows how each function is used to modify the final result

MatrixFunctions.h: Header file for MatrixFunctions.cpp.
