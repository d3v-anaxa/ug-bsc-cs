#include <iostream>
class LowerTriangularMatrix {
private:
    int* matrix;
    int size;
    int dimension;
public:
    LowerTriangularMatrix(int n) {
        dimension = n;
        matrix = new int[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = 0;
        }
    }
    void setValue(int row, int col, int value) {
        if (row >= col && row >= 0 && row < dimension && col >= 0 && col < dimension) {
            int index = (row * (row + 1)) / 2 + col;
            matrix[index] = value;
        } else {
            std::cout << "Invalid position for setting value." << std::endl;
        }
    }
    int getValue(int row, int col) {
        if (row >= col && row >= 0 && row < dimension && col >= 0 && col < dimension) {
            int index = (row * (row + 1)) / 2 + col;
            return matrix[index];
        } else {
        }
    }
    void display() {
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                if (i >= j) {
                    int index = (i * (i + 1)) / 2 + j;
                    std::cout << matrix[index] << " ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
    ~LowerTriangularMatrix() {
        delete[] matrix;
    }
};
int main() {
    int size;
    std::cout << "Enter the size of the lower triangular matrix: ";
    std::cin >> size;
    LowerTriangularMatrix matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            int value;
            std::cout << "Enter value for element at position (" << i << ", " << j << "): ";
            std::cin >> value;
            matrix.setValue(i, j, value);
        }
    }
    std::cout << "Lower Triangular Matrix:" << std::endl;
    matrix.display();
    return 0;
}
