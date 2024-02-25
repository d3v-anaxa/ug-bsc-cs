#include <iostream>
#include <vector>
struct Triplet {
    int row;
    int col;
    int value;
    Triplet(int r, int c, int v) : row(r), col(c), value(v) {}
};
class SparseMatrix {
private:
    int rows;
    int cols;
    std::vector<Triplet> triplets;
public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}
    void addElement(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            triplets.push_back(Triplet(row, col, value));
        } else {
            std::cerr << "Error: Index out of bounds." << std::endl;
        }
    }
    std::vector<std::vector<int>> toNonZeroForm() {
        std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));
        for (const auto& triplet : triplets) {
            result[triplet.row][triplet.col] = triplet.value;
        }
        return result;
    }
    void fromNonZeroForm(const std::vector<std::vector<int>>& matrix) {
        triplets.clear();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] != 0) {
                    triplets.push_back(Triplet(i, j, matrix[i][j]));
                }
            }
        }
    }
    void display() {
        std::cout << "Sparse Matrix:" << std::endl;
        for (const auto& triplet : triplets) {
            std::cout << "(" << triplet.row << ", " << triplet.col << "): " << triplet.value << std::endl;
        }
    }
};
int main() {
    int rows, cols;
    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> rows >> cols;
    SparseMatrix sparseMatrix(rows, cols);
    std::cout << "Enter the elements of the matrix row-wise:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            std::cin >> value;
            if (value != 0) {
                sparseMatrix.addElement(i, j, value);
            }
        }
    }
    std::vector<std::vector<int>> nonZeroForm = sparseMatrix.toNonZeroForm();
    std::cout << "Matrix in non-zero form:" << std::endl;
    for (const auto& row : nonZeroForm) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    SparseMatrix sparseMatrixFromNonZeroForm(rows, cols);
    sparseMatrixFromNonZeroForm.fromNonZeroForm(nonZeroForm);
    sparseMatrixFromNonZeroForm.display();
    return 0;
}
