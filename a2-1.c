#include <stdio.h>
#include <stdlib.h>  

void readMatrix(int row1, int col1, int row2, int col2, int **mat1, int **mat2, int **result) {

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            printf("Enter element mat1[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            printf("Enter element mat2[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }
}

void multiplyMatrices(int **mat1, int **mat2, int **result, int row1, int col1, int row2, int col2) {
     if (col1 != row2) {
        printf("Matrix multiplication is not possible. The number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        return;
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;  
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row1, col1, row2, col2, **mat1, **mat2, **result;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &row2, &col2);

    mat1 = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++) {
        mat1[i] = (int *)malloc(col1 * sizeof(int));
    }

    mat2 = (int **)malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++) {
        mat2[i] = (int *)malloc(col2 * sizeof(int));
    }

    result = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++) {
        result[i] = (int *)malloc(col2 * sizeof(int));
    }

    readMatrix(row1, col1, row2, col2, mat1, mat2, result);
    // printf("mat1[0][0]: %d and mat2[0][0]: %d", mat1[0][0], mat2[0][0]);

    multiplyMatrices(mat1, mat2, result, row1, col1, row2, col2);

    printf("\nResultant matrix after multiplication:\n");
    displayMatrix(result, row1, col2);

    for (int i = 0; i < row1; i++) {
        free(mat1[i]);
    }
    free(mat1);

    for (int i = 0; i < row2; i++) {
        free(mat2[i]);
    }
    free(mat2);

    for (int i = 0; i < row1; i++) {
        free(result[i]);
    }
    free(result);
}