#include "matrixTranspose.h"

void MatrixTranspose(double matrix[5][5]) {
    // Transpose the matrix
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
