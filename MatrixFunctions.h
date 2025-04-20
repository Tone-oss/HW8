class MatrixFunctions
{
private:


    
public:
    MatrixFunctions();
    ~MatrixFunctions();
    int** add(int**, int**, int rows, int cols);
    int** scale(int, int**, int rows, int cols);
    int** multi(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2);
    int** transpose(int**, int rows, int cols);
    


};