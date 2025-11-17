#include <iostream>
using namespace std;

// Function to convert 2D array to 1D using row-major mapping
void rowMajorMapping(int rows, int cols, int matrix[3][3], int oneD[]) {
    int index = 0;
    // Traverse row by row
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            oneD[index] = matrix[i][j];     // Store element in 1D array
            index++;                         // Move to next index
        }
    }
}
int main() {
 
    const int rows = 3;
    const int cols = 3;
    int matrix[rows][cols] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int oneD[9];

    rowMajorMapping(rows, cols, matrix, oneD);

    cout << "\n1D array in Row-Major Order: ";
    for (int i = 0; i < rows * cols; i++) {
        cout << oneD[i] << " ";
    }
    cout << endl;

    return 0;
}
