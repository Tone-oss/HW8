#include <iostream>
using namespace std;


class MatrixFunctions
{
private:


    
public:
    int** add(int**, int**, int rows, int cols);
    int** scale(int, int**, int rows, int cols);
    int** multi(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2);
    int** transpose(int**, int rows, int cols);
    


};
//helper functions
void destruct(int**, int);
void printMatrix(int** matrix ,int rows, int cols );




int main(){

    
    
        
    //If you wanna test different arrays, edit them here
    #define rowsA  2//num rows
    #define colsA  2//num cols


    int A[rowsA][colsA] = {{6, 4,},{8, 3}};//2 x 2 matrix

    int** matrixA = new int*[rowsA];

    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = new int [colsA];
        for (int j = 0; j < colsA; j++)
        {
            matrixA[i][j] = A[i][j];
        }
        
    }

        

    //Array declaration
    //If you wanna test different arrays, edit them here
    #define rowsB  2//num rows
    #define colsB  3//num cols

    int B[rowsB][colsB] = {{1, 2, 3}, {4, 5, 6}};//2 x 3 matrix


    int** matrixB = new int*[rowsB];
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = new int [colsB];
        for (int j = 0; j < colsB; j++)
        {
            matrixB[i][j] = B[i][j];
        }
        
    }

    //Array declaration
    //If you wanna test different arrays, edit them here
    #define rowsC  2 //num rows
    #define colsC  3 //num cols

    int C[rowsC][colsC] = {{2, 4, 6}, {1, 3, 5}};//2 x 3 matrix
    int** matrixC = new int*[rowsC];

    for (int i = 0; i < rowsC; i++)
    {
        matrixC[i] = new int [colsC];
        for (int j = 0; j < colsC; j++)
        {
            matrixC[i][j] = C[i][j];
        }
        
    }


    MatrixFunctions functions;

    int** scaleResult = functions.scale(3, matrixB, rowsB, colsB);
    int** transResult = functions.transpose(matrixC, rowsC, colsC);
    int** multResult = functions.multi(scaleResult, rowsB, colsB, transResult, colsC, rowsC);
    int** addResult = functions.add(matrixA, multResult, rowsA, colsA);//should be the final result

    //output result
    cout << "Final Result:\n";
    printMatrix(addResult, rowsA, colsA);
    


        destruct(matrixA, rowsA);
        destruct(matrixB, rowsB);
        destruct(matrixC, rowsC);
        destruct(scaleResult, rowsB);
        destruct(transResult, colsC);
        destruct(multResult, rowsB);
        destruct(addResult, rowsA);

        return 0;
}

void printMatrix(int** matrix ,int rows, int cols ){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

         cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }
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
            result[i][j] = matrix[i][j] * scalar; //multiply
        }
    }

    return result;
}

/*

*/
int** MatrixFunctions::multi(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2){
    //since an array with different dimensions can be made, A new array needs to be dynamically Allocated
     // Allocate memory for result matrix
     int** result = new int*[rows1];
     for (int i = 0; i < rows1; i++) {
         result[i] = new int[cols2];
         for (int j = 0; j < cols2; j++) {
             result[i][j] = 0; 
             // initialize each element to 0
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

    return result;
}

int** MatrixFunctions::transpose(int** matrix, int rows, int cols){
    // Allocate memory for the transposed matrix since it creates an array of different size
    int** result = new int*[cols];
    for (int i = 0; i < cols; i++) {
        result[i] = new int[rows];
    }

    // Swap the values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}


void destruct(int** matrix, int rows){
    for (int i = 0; i < rows; i++)
    {
        delete(matrix[i]);
    }
    delete(matrix);
    

}
