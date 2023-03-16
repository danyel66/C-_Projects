//
// Onyeka Daniel Nduka.
//
#include <iostream>
#include <fstream>
using namespace std;

void printMatrix(double** matrix, int row, int col);

double** addMatrix(double** mat1, double** mat2, int row, int col);

int main(int argc, char* argv []){
    cout << "Welcome to Matrix Addition." << endl;
    string fileName1;
    string fileName2;

    if (argc > 1)
        fileName1 = argv[1];
    if (argc > 2)
        fileName2 = argv[2];

    if (fileName1.empty()){
        cout << "Please enter the first file name: ";
        getline(cin, fileName1);
        cout << "Please enter the second file name: ";
        getline(cin, fileName2);
    } else if (fileName2.empty()){
        cout << "Please enter another big integer: ";
        getline(cin, fileName2);
    }

    ifstream fin;
    fin.open(fileName1);
    if (!fin) {
        cout << "ERROR opening file " << fileName1 << "!!!" << endl;
        exit(EXIT_FAILURE);
    }
    int mat1row;
    int mat1col;
    int mat2row;
    int mat2col;

    fin >> mat1row >> mat1col;

    double** matrix1 = new double*[mat1row];
    for (int i = 0; i < mat1row; i++) {
        matrix1[i] = new double[mat1col];
    }

    for (int i = 0; i < mat1row; i++) {
        for (int j = 0; j < mat1col; j++) {
            fin >> matrix1[i][j];
        }
    }
    fin.close();

    // The second matrix
    fin.open(fileName2);
    if (!fin) {
        cout << "ERROR opening file " << fileName1 << "!!!" << endl;
        exit(EXIT_FAILURE);
    }

    fin >> mat2row >> mat2col;

    double** matrix2 = new double*[mat2row];
    for (int i = 0; i < mat2row; i++) {
        matrix2[i] = new double[mat2col];
    }

    for (int i = 0; i < mat2row; i++) {
        for (int j = 0; j < mat2col; j++) {
            fin >> matrix2[i][j];
        }
    }
    fin.close();

    cout << "The first Matrix: " << endl;
    printMatrix(matrix1, mat1row, mat1col);
    cout << "\nThe second Matrix: " << endl;
    printMatrix(matrix2, mat2row, mat2col);

    if ((mat1row != mat2row) || (mat1col != mat2col)) {
        cout << "The dimensions are not equal. Cannot perform addition operation!" << endl;
        return 1;
    }

    double** result = addMatrix(matrix1, matrix2, mat1row, mat1col);
    cout << "\nThe sum is: \n";
    printMatrix(result, mat1row, mat1col);

    // deallocate memory
    for (int i = 0; i < mat1row; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] result[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
}

double** addMatrix(double** mat1, double** mat2, int row, int col) {
    double** result = new double*[row];
    for (int i = 0; i < row; i++) {
        result[i] = new double[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return result;
}

void printMatrix(double** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "\t" << matrix[i][j];
        }
        cout << endl;
    }
}
