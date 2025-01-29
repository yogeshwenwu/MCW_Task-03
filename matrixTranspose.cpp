#include "matrixTranspose.h"

void MatrixTranspose(float matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            float temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
