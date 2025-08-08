#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int size, int grid[size][size]) {
    int leftDiagonalSum = 0, rightDiagonalSum = 0;

    for (int row = 0; row < size; row++) {
        leftDiagonalSum += grid[row][row];
        rightDiagonalSum += grid[row][size - 1 - row];
    }

    int difference = leftDiagonalSum - rightDiagonalSum;
    return difference < 0 ? -difference : difference;
}

int main() {
    int dimension;
    scanf("%d", &dimension);

    int grid[dimension][dimension]; 

    for (int r = 0; r < dimension; r++)
        for (int c = 0; c < dimension; c++)
            scanf("%d", &grid[r][c]);

    int result = diagonalDifference(dimension, grid);
    printf("%d\n", result);

    return 0;
}
