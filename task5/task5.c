#include <stdio.h>
#include <stdlib.h>

// Takes input for matrix A and vector x from the user
void input_matrix_vector(int rows, int cols, float **A, float *x) {
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    printf("Enter the elements of vector x:\n");
    for (int i = 0; i < cols; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }
}

int main() {
    int rows, cols;

    // Prompt the user to enter the number of rows and columns
    printf("Enter the number of rows in matrix A: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in matrix A (size of vector x): ");
    scanf("%d", &cols);

    // Dynamically allocate memory for matrix A and vector x
    float **A = (float **)malloc(rows * sizeof(float *));
    if (A == NULL) {
        printf("Error! Memory not allocated.");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        A[i] = (float *)malloc(cols * sizeof(float));
        if (A[i] == NULL) {
            printf("Error! Memory not allocated.");
            return 1;
        }
    }
    float *x = (float *)malloc(cols * sizeof(float));
    float *output = (float *)malloc(rows * sizeof(float));

    // Check if memory allocation was successful
    if (x == NULL || output == NULL) {
        printf("Error! Memory not allocated.");
        return 1;
    }

    // Take input for matrix A and vector x
    input_matrix_vector(rows, cols, A, x);

    // Compute matrix-vector multiplication
    for (int i = 0; i < rows; i++) {
        output[i] = 0;
        for (int j = 0; j < cols; j++) {
            output[i] += A[i][j] * x[j];
        }
    }

    // Display the resulting vector (y = A * x)
    printf("Resulting matrix (y = A * x):\n");
    for (int i = 0; i < rows; i++) {
        printf("output[%d] = %.2f\n", i, output[i]);
    }

    // Deallocate the memory
    for (int i = 0; i < rows; i++) {
        free(A[i]);
    }
    free(A);
    free(x);
    free(output);

    return 0;
}
