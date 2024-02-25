#include <iostream>
class DiagonalMatrix {
private:
    int* diagonal;
    int size;
public:
    DiagonalMatrix(int n) {
        size = n;
        diagonal = new int[n];
        for (int i = 0; i < size; ++i) {
            diagonal[i] = 0;
        }
    }
    void setValue(int row, int col, int value) {
        if (row == col && row >= 0 && row < size) {
            diagonal[row] = value;
        } else {
            std::cout << "Invalid position for setting value." << std::endl;
        }
    }
    int getValue(int row, int col) {
        if (row == col && row >= 0 && row < size) {
            return diagonal[row];
        } else {
        }
    }
    void display() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == j) {
                    std::cout << diagonal[i] << " ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
    ~DiagonalMatrix() {
        delete[] diagonal;
    }
};
int main() {
    int size;
    std::cout << "Enter the size of the diagonal matrix: ";
    std::cin >> size;
    DiagonalMatrix matrix(size);
    for (int i = 0; i < size; ++i) {
        int value;
        std::cout << "Enter value for diagonal element at position (" << i << ", " << i << "): ";
        std::cin >> value;
        matrix.setValue(i, i, value);
    }
    std::cout << "Diagonal Matrix:" << std::endl;
    matrix.display();
    return 0;
}
