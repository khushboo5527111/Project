#include <stdio.h>

int findWinner(int numTowers, int towerHeight) {
    if (towerHeight == 1 || numTowers % 2 == 0) {
        return 2; 
    } else {
        return 1; 
    }
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int i = 0; i < testCases; i++) {
        int towers, height;
        scanf("%d %d", &towers, &height);
        int winner = findWinner(towers, height);
        printf("%d\n", winner);
    }

    return 0;
}
