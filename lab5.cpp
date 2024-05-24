#include <iostream>

using namespace std;

class SquareMatrix {
private:
    int size;
    int** matrix;

public:
    // Default constructor
    SquareMatrix() : size(0), matrix(nullptr) {}

    // Parameterized constructor with size of the square matrix
    SquareMatrix(int n) : size(n) {
        // Allocate memory for each row
        matrix = new int* [size];
        for (int i = 0; i < size; ++i) {
            // Allocate memory for each column
            matrix[i] = new int[size];
            // Initialize elements of the matrix
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = 0; // You can initialize as needed
            }
        }
    }

    // Destructor to release memory
    ~SquareMatrix() {
        // Free memory for each row
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        // Free memory for the array of rows
        delete[] matrix;
    }

    // Overloading the indexing operator []
    int* operator[](int index) {
        return matrix[index];
    }

    // Overloading the function call operator ()
    int& operator()(int row, int col) {
        return matrix[row][col];
    }

    friend istream& operator>>(istream& in, SquareMatrix& mat);
    friend ostream& operator<<(ostream& out, const SquareMatrix& mat);
};

// Overloading the input operator >>
istream& operator>>(istream& in, SquareMatrix& mat) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            in >> mat.matrix[i][j];
        }
    }
    return in;
}

// Overloading the output operator <<
ostream& operator<<(ostream& out, const SquareMatrix& mat) {
    out << "Matrix:" << endl;
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            out << mat.matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

int main() {
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    SquareMatrix mat(size);

    cin >> mat;

    cout << mat;

    // Example usage of the [] operator
    cout << "Element at position (0, 0): " << mat[0][0] << endl;

    // Example usage of the () operator
    mat(0, 0) = 100;
    cout << "Updated element at position (0, 0): " << mat(0, 0) << endl;

    return 0;
}
