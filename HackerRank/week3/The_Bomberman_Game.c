#include <stdio.h>

// ---- Function Declarations ----
void plant_bombs(char board[][201], int rows, int cols);
void detonate(char current[][201], char next[][201], int rows, int cols);

int main() {
    int rows, cols, seconds;
    scanf("%d %d %d", &rows, &cols, &seconds);

    char initial[201][201];   // original state
    char stage1[201][201];    // state after first blast
    char stage2[201][201];    // state after second blast

    // Input initial grid
    for (int i = 0; i < rows; i++) {
        scanf("%s", initial[i]);
    }

    // Case 1: At time 1, just show the grid
    if (seconds == 1) {
        for (int i = 0; i < rows; i++) {
            printf("%s\n", initial[i]);
        }
    }
    // Case 2: At even times -> grid always full of bombs
    else if (seconds % 2 == 0) {
        plant_bombs(initial, rows, cols);
        for (int i = 0; i < rows; i++) {
            printf("%s\n", initial[i]);
        }
    }
    // Case 3: Odd times >= 3
    else {
        detonate(initial, stage1, rows, cols);

        if (seconds % 4 == 3) {
            for (int i = 0; i < rows; i++) {
                printf("%s\n", stage1[i]);
            }
        } else {
            detonate(stage1, stage2, rows, cols);
            for (int i = 0; i < rows; i++) {
                printf("%s\n", stage2[i]);
            }
        }
    }

    return 0;
}

// ---- Helper Functions ----

// Fill the board completely with bombs
void plant_bombs(char board[][201], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = 'O';
        }
        board[i][cols] = '\0'; // terminate row string
    }
}

// Perform explosion and update new grid
void detonate(char current[][201], char next[][201], int rows, int cols) {
    // Start with all bombs
    plant_bombs(next, rows, cols);

    // Clear exploded bombs and neighbors
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (current[i][j] == 'O') {
                next[i][j] = '.';
                if (i > 0)      next[i-1][j] = '.';
                if (i < rows-1) next[i+1][j] = '.';
                if (j > 0)      next[i][j-1] = '.';
                if (j < cols-1) next[i][j+1] = '.';
            }
        }
    }
}
