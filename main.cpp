#include <iostream>
#include <chrono>
#include "matrixTranspose.h"
#include "matrixTransposeAvx.h"
using namespace std;

int main() {
    // Initialization
    double matrix[5][5] = {
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {6.0, 7.0, 8.0, 9.0, 10.0},
        {11.0, 12.0, 13.0, 14.0, 15.0},
        {16.0, 17.0, 18.0, 19.0, 20.0},
        {21.0, 22.0, 23.0, 24.0, 25.0}
    };

    // Scalar transpose the matrix
    auto start_scalar = chrono::high_resolution_clock::now();
    MatrixTranspose(matrix);
    auto end_scalar = chrono::high_resolution_clock::now();
    auto scalar_duration = chrono::duration_cast<chrono::nanoseconds>(end_scalar - start_scalar).count();
    

    // Display the transposed matrix
    cout << "Transposed Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Vector transpose the matrix
    auto start_vector = chrono::high_resolution_clock::now();
    MtAvx256(matrix);
    auto end_vector = chrono::high_resolution_clock::now();
    auto vector_duration = chrono::duration_cast<chrono::nanoseconds>(end_vector - start_vector).count();
    

    // Display the transposed matrix
    cout << "Transposed Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix transposition took: " << scalar_duration << " nanoseconds" << endl;
    cout << "Vector Matrix transposition took: " << vector_duration << " nanoseconds" << endl;

    return 0;
}
