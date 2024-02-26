def matrix_sum(matrix1, matrix2):
    """
    Calculate the sum of two matrices.

    Args:
    matrix1 (list of lists): The first matrix.
    matrix2 (list of lists): The second matrix.

    Returns:
    list of lists: The sum of the two matrices if they are compatible, None otherwise.
    """
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        print("Matrices are not compatible for addition.")
        return None
    
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    
    return result

def matrix_product(matrix1, matrix2):
    """
    Calculate the product of two matrices.

    Args:
    matrix1 (list of lists): The first matrix.
    matrix2 (list of lists): The second matrix.

    Returns:
    list of lists: The product of the two matrices if they are compatible, None otherwise.
    """
    if len(matrix1[0]) != len(matrix2):
        print("Matrices are not compatible for multiplication.")
        return None
    
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            total = 0
            for k in range(len(matrix2)):
                total += matrix1[i][k] * matrix2[k][j]
            row.append(total)
        result.append(row)
    
    return result

# Example matrices
matrix1 = [[1, 2, 3],
           [4, 5, 6]]

matrix2 = [[7, 8],
           [9, 10],
           [11, 12]]

# Calculate and display sum
print("Sum of matrices:")
sum_matrix = matrix_sum(matrix1, matrix2)
if sum_matrix:
    for row in sum_matrix:
        print(row)

# Calculate and display product
print("\nProduct of matrices:")
product_matrix = matrix_product(matrix1, matrix2)
if product_matrix:
    for row in product_matrix:
        print(row)

