#include <iostream>
class SymmetricMatrix {
private:
    int* matrix;
    int size;
    int dimension;
public:
    SymmetricMatrix(int n) {
        dimension = n;
        matrix = new int[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = 0;
        }
    }
    void setValue(int row, int col, int value) {
        if (row >= 0 && row < dimension && col >= 0 && col < dimension) {
            if (row <= col) {
                int index = row * dimension - (row - 1) * row / 2 + col - row;
                matrix[index] = value;
            } else {
                int temp = row;
                row = col;
                col = temp;
                int index = col * dimension - (col - 1) * col / 2 + row - col;
                matrix[index] = value;
            }
        } else {
            std::cout << "Invalid position for setting value." << std::endl;
        }
    }
    int getValue(int row, int col) {
        if (row >= 0 && row < dimension && col >= 0 && col < dimension) {
            if (row <= col) {
                int index = row * dimension - (row - 1) * row / 2 + col - row;
                return matrix[index];
            } else {
                int temp = row;
                row = col;
                col = temp;
                int index = col * dimension - (col - 1) * col / 2 + row - col;
                return matrix[index];
            }
        } else {
        }
    }
    void display() {
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                if (i <= j) {
                    int index = i * dimension - (i - 1) * i / 2 + j - i;
                    std::cout << matrix[index] << " ";
                } else {
                    int index = j * dimension - (j - 1) * j / 2 + i - j;
                    std::cout << matrix[index] << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    ~SymmetricMatrix() {
        delete[] matrix;
    }
};
int main() {
    int size;
    std::cout << "Enter the size of the symmetric matrix: ";
    std::cin >> size;
    SymmetricMatrix matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            int value;
            std::cout << "Enter value for element at position (" << i << ", " << j << "): ";
            std::cin >> value;
            matrix.setValue(i, j, value);
        }
    }
    std::cout << "Symmetric Matrix:" << std::endl;
    matrix.display();
    return 0;
}
