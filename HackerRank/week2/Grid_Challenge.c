#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        char grid[n][n+1];  // +1 for null terminator

        // Input grid
        for(int i = 0; i < n; i++) {
            scanf("%s", grid[i]);

            // Sort the row using bubble sort (no extra function)
            for(int pass = 0; pass < n-1; pass++) {
                for(int j = 0; j < n - pass - 1; j++) {
                    if(grid[i][j] > grid[i][j+1]) {
                        char temp = grid[i][j];
                        grid[i][j] = grid[i][j+1];
                        grid[i][j+1] = temp;
                    }
                }
            }
        }

        // Check columns
        int valid = 1; // assume YES
        for(int col = 0; col < n; col++) {
            for(int row = 0; row < n - 1; row++) {
                if(grid[row][col] > grid[row+1][col]) {
                    valid = 0; // NO
                    break;
                }
            }
            if(!valid) break;
        }

        if(valid)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
