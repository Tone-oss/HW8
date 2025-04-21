#include <stdio.h>
#include <stdlib.h>




//matrix functions
int** add(int* matrix1[], int* matrix2[], int rows, int cols);
int** scale(int, int**,  int rows, int cols);
int** multi(int* matrix1[], int rows1, int cols1, int* matrix2[], int rows2, int cols2);
int** transpose(int* matrix[], int rows, int cols);

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void destruct(int** matrix, int rows){
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    

}



//example usage here
int main(){

    //Array declaration
    //If you wanna test different arrays, edit them here
    #define rowsA  2//num rows
    #define colsA  2//num cols


    int A[rowsA][colsA] = {{6, 4,},{8, 3}};//2 x 2 matrix


    int** matrixA = (int**)malloc(rowsA * sizeof(int*)); // Allocate rows
    for (int i = 0; i < rowsA; i++) {
        matrixA[i] = (int*)malloc(colsA * sizeof(int)); // Allocate columns for each row
        for (int j = 0; j < colsA; j++) {
            matrixA[i][j] = A[i][j]; // Copy values from static array to dynamic matrix
        }
    }
     
        

    //Array declaration
    //If you wanna test different arrays, edit them here
    #define rowsB  2//num rows
    #define colsB  3//num cols

    int B[rowsB][colsB] = {{1, 2, 3}, {4, 5, 6}};//2 x 3 matrix

    
    int** matrixB = (int**)malloc(rowsB * sizeof(int*));
    for (int i = 0; i < rowsB; i++) {
        matrixB[i] = (int*)malloc(colsB * sizeof(int)); // Allocate columns for each row
        for (int j = 0; j < colsB; j++) {
            matrixB[i][j] = B[i][j]; // Copy values from static array to dynamic matrix
        }
    }

    //Array declaration
    //If you wanna test different arrays, edit them here
    #define rowsC  2 //num rows
    #define colsC  3 //num cols

    int C[rowsC][colsC] = {{2, 4, 6}, {1, 3, 5}};//2 x 3 matrix

    int** matrixC = (int**)malloc(rowsC * sizeof(int*));
    for (int i = 0; i < rowsC; i++) {
        matrixC[i] = (int*)malloc(colsC * sizeof(int)); // Allocate columns for each row
        for (int j = 0; j < colsC; j++) {
            matrixC[i][j] = C[i][j]; // Copy values from static array to dynamic matrix
        }
    }

    
    
    

    int** scaleResult = scale(3, matrixB, rowsB, colsB);
    int** transResult = transpose(matrixC, rowsC, colsC);
    int** multResult = multi(scaleResult, rowsB, colsB, transResult, colsC, rowsC);
    int** addResult = add(matrixA, multResult, rowsA, colsA);//should be the final result

    printf("B after Scalar of 3: \n");
    printMatrix(scaleResult, rowsB, colsB);
    printf("\nC transposed: \n");
    printMatrix(transResult, colsC, rowsC);
    printf("\nB and C multiplied: \n");
    printMatrix(multResult, rowsB, rowsC);
    printf("\nA plus B and C multiplied: \n");
    printMatrix(addResult, rowsA, colsA);
    
    //dynamic arrays need to be free'd
    destruct(scaleResult, rowsB);
    destruct(transResult, colsC);
    destruct(multResult, rowsB);
    destruct(addResult, rowsA);
    destruct(matrixA, rowsA);
    destruct(matrixB, rowsB);
    destruct(matrixC, rowsC);

    
    return 0;
}

int** multi(int* matrix1[], int rows1, int cols1, int* matrix2[], int rows2, int cols2){
   
    
    // Allocate memory for the result matrix
    int** result = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int*)malloc(cols2 * sizeof(int));
        
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    } 
    return result;

}

int** transpose(int* matrix[], int rows, int cols){
    // Allocate memory for the transposed matrix
    int** result = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }
    // Perform the transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

int** scale(int factor, int* matrix[], int rows, int cols){


    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
    }

    //Multiply corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * factor;
        }
    }

    return result;
}

int** add(int* matrix1[], int* matrix2[], int rows, int cols){

    int** result = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }

    // Add corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
    
    
    
}
