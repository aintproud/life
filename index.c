#include <stdio.h>
#include <unistd.h>

#define ROWS 5
#define COLS 5
int new_matrix[ROWS][COLS] = {0};

void isLife(int x, int y, int matrix[ROWS][COLS]) {
    int neighbors_count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) continue;
            int new_x = i<0? ROWS - 1 : i;
            int new_y = j<0? COLS - 1 : j;
            // printf("%d, %d\n", new_x, new_y);
            if (matrix[new_x][new_y] == 1) {
                neighbors_count++;
            }
        }
    }
    if(matrix[x][y] == 0 && neighbors_count == 3) {
        new_matrix[x][y] = 1;
    } else if(matrix[x][y] == 1 && (neighbors_count <= 2 || neighbors_count > 3)) {
        new_matrix[x][y] = 0;
    }
}

int main() {
    int matrix[ROWS][COLS];
    int generation = 0;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    while (1) {
                printf("Generation: %d\n\n", generation);
        for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            isLife(i, j, matrix);
        }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", new_matrix[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                matrix[i][j] = new_matrix[i][j];
            }
        }
        generation++;
        printf("\n\n");
        sleep(5);
    }

    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         isLife(i, j, matrix);
    //     }
    //     printf("\n");
    // }
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // // Print the matrix
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         printf("%d ", new_matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    
    return 0;
}