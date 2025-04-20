

#define m  2
#define n  3


int** add(int** matrix1, int** matrix2, int** result){

}
int** scale(int, int**, int** result);

int** multi(int** matrix1, int** matrix2, int** result);
int** transpose(int**, int** result);

int main(){

    int A[n][n];//n x n matrix
    int B[m][n];//n x m matrix
    int C[m][n];//n x m matrix
    int result[m][m];

   

    return 0;
}

int** multi(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2, int** result){
   
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    } 
    return result;

}

int** transpose(int** matrix, int rows, int cols, int** result){
    // Allocate memory for the transposed matrix
    
    // Perform the transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

int** scale(int scalar, int** matrix, int rows, int cols, int** result){


    //Multiply corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] *= matrix[i][j];
        }
    }

    return result;
}

int** add(int** matrix1, int** matrix2, int rows, int cols, int** result){

    // Add corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
    
    
    
}