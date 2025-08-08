#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int leftToRightSum = 0;
    int rightToLeftSum = 0;
    
    for (int i = 0; i < arr_rows; i++) {
        leftToRightSum += arr[i][i];
    }
    
    for (int i = 0; i < arr_rows; i++) {
        rightToLeftSum += arr[i][arr_rows - 1 - i];
    }
    
    int difference = leftToRightSum - rightToLeftSum;
    return abs(difference);
}

int main() {
    int n;
    scanf("%d", &n);

    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int result = diagonalDifference(n, n, arr);
    printf("%d\n", result);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
