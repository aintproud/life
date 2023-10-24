#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 15
#define COLS 15
int new_matrix[ROWS][COLS] = {0};

void isLife(int x, int y, int matrix[ROWS][COLS]) {
    int neighbors_count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) continue;
            int new_x = i<0? ROWS - 1 : i;
            int new_y = j<0? COLS - 1 : j;
            new_x = new_x >= ROWS? 0 : new_x;
            new_y = new_y >= COLS? 0 : new_y;
            if (matrix[new_x][new_y] == 1) {
                neighbors_count++;
            }
        }
    }
    if((neighbors_count == 3 || neighbors_count == 2) && matrix[x][y] == 1) {
        new_matrix[x][y] = 1;
    } 
    else if(neighbors_count == 3 && matrix[x][y] == 0) {
        new_matrix[x][y] = 1;
    }
    else if(matrix[x][y] == 1 && (neighbors_count < 2 || neighbors_count > 3)) {
        new_matrix[x][y] = 0;
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int generation = 0;

    while (1) {
        printf("Generation: %d\n\n", generation);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                isLife(i, j, matrix);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (matrix[i][j] == 1) {
                    printf("\033[0;33m");
                    printf("%d ", matrix[i][j]);
                    printf("\033[0m");    
                }
                else {
                    printf("\033[0;32m");
                    printf("%d ", matrix[i][j]);
                    printf("\033[0m");  
                }
            }
            printf("\n");
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                matrix[i][j] = new_matrix[i][j];
            }
        }
        generation++;
        usleep(100000);
        system("clear");
    }
    return 0;
}