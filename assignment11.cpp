#include<iostream>
using namespace std;
class Matrix {
private:
    int rows;
    int columns;
    int *data;
public:
    Matrix(int r, int c) : rows(r), columns(c) {
        data = new int[rows * columns];
    }
    ~Matrix() {
        delete[] data;
    }
    void setValue(int row, int col, int value) {
        data[row * columns + col] = value;
    }
    int getValue(int row, int col) const {
        return data[row * columns + col];
    }
    int getRows() const {
        return rows;
    }
    int getColumns() const {
        return columns;
    }
};
Matrix matrixAddition(const Matrix& A, const Matrix& B) {
    Matrix result(A.getRows(), A.getColumns());
    for (int i = 0; i < A.getRows(); ++i) {
        for (int j = 0; j < A.getColumns(); ++j) {
            result.setValue(i, j, A.getValue(i, j) + B.getValue(i, j));
        }
    }
    return result;
}
int main() {
    int rows1, columns1, rows2, columns2;
    cout << "Enter the number of rows and columns for matrix 1: ";
    cin >> rows1 >> columns1;
    Matrix OBJ1(rows1, columns1);
    cout << "Enter the values for matrix 1:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns1; ++j) {
            int value;
            cout << "Enter value for row " << i + 1 << " and column " << j + 1 << ": ";
            cin >> value;
            OBJ1.setValue(i, j, value);
        }
    }
    cout << "Enter the number of rows and columns for matrix 2: ";
    cin >> rows2 >> columns2;
    Matrix OBJ2(rows2, columns2);
    cout << "Enter the values for matrix 2:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < columns2; ++j) {
            int value;
            cout << "Enter value for row " << i + 1 << " and column " << j + 1 << ": ";
            cin >> value;
            OBJ2.setValue(i, j, value);
        }
    }
    Matrix OBJ3 = matrixAddition(OBJ1, OBJ2);
    cout << "Resultant Matrix 3 after addition:" << endl;
    for (int i = 0; i < OBJ3.getRows(); ++i) {
        for (int j = 0; j < OBJ3.getColumns(); ++j) {
            cout << OBJ3.getValue(i, j) << " ";
       }
        cout << endl;
    }
    return 0;
}


