#include "MatrixFunctions.h"



using namespace std;




MatrixFunctions::MatrixFunctions(){
    
}


MatrixFunctions::~MatrixFunctions()
{
}

int** MatrixFunctions::add(int** matrix1, int** matrix2, int rows, int cols){

    int** result = new int*[rows];
    for (int i = 0; i < rows; i++) {
        result[i] = new int[cols];
    }

    // Add corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
    
    
    
}

int** MatrixFunctions::scale(int scalar, int** matrix, int rows, int cols){

    int** result = new int*[rows];
    for (int i = 0; i < rows; i++) {
        result[i] = new int[cols];
    }

    //Multiply corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] *= matrix[i][j];
        }
    }

    return result;
}

int** MatrixFunctions::multi(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2){
     // Allocate memory for result matrix
     int** result = new int*[rows1];
     for (int i = 0; i < rows1; i++) {
         result[i] = new int[cols2];
         for (int j = 0; j < cols2; j++) {
             result[i][j] = 0; // initialize each element to 0
         }
     }
 
     // Perform matrix multiplication
     for (int i = 0; i < rows1; i++) {
         for (int j = 0; j < cols2; j++) {
             for (int k = 0; k < cols1; k++) {
                 result[i][j] += matrix1[i][k] * matrix2[k][j];
             }
         }
     }
}

int** MatrixFunctions::transpose(int** matrix, int rows, int cols){
    // Allocate memory for the transposed matrix
    int** result = new int*[cols];
    for (int i = 0; i < cols; i++) {
        result[i] = new int[rows];
    }

    // Perform the transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
