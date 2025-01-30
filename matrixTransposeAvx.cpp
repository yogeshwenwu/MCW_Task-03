#include "matrixtransposeAvx.h"
#include <immintrin.h>

void MtAvx256(double matrix[5][5]) {
    // Load the matrix into registers
    __m256d row0 = _mm256_loadu_pd(&matrix[0][0]);
    __m256d row1 = _mm256_loadu_pd(&matrix[1][0]);
    __m256d row2 = _mm256_loadu_pd(&matrix[2][0]);
    __m256d row3 = _mm256_loadu_pd(&matrix[3][0]);

    // Unpack the matrix
    __m256d t0 = _mm256_unpacklo_pd(row0, row1);
    __m256d t1 = _mm256_unpackhi_pd(row0, row1);
    __m256d t2 = _mm256_unpacklo_pd(row2, row3);
    __m256d t3 = _mm256_unpackhi_pd(row2, row3);

    // Transpose the matrix
    __m256d temp0 = _mm256_permute2f128_pd(t0, t2, 0x20);
    __m256d temp1 = _mm256_permute2f128_pd(t1, t3, 0x20);
    __m256d temp2 = _mm256_permute2f128_pd(t0, t2, 0x31);
    __m256d temp3 = _mm256_permute2f128_pd(t1, t3, 0x31);

    // Store the transposed matrix
    _mm256_storeu_pd(&matrix[0][0], temp0);
    _mm256_storeu_pd(&matrix[1][0], temp1);
    _mm256_storeu_pd(&matrix[2][0], temp2);
    _mm256_storeu_pd(&matrix[3][0], temp3);

    // Handle the remaining elements
    for (int i = 0; i < 4; i++) {
        float temp = matrix[i][4];
        matrix[i][4] = matrix[4][i];
        matrix[4][i] = temp;
    }
}
