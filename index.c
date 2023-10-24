#include <stdio.h>

#define ROWS 10
#define COLS 10

int main() {
    int matrix[ROWS][COLS];
    
    // Fill the matrix with 1s and 0s
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Generate a random number between 0 and 1
            matrix[i][j] = rand() % 2;
        }
    }
    

    // Print the matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}