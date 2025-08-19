#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int ranked[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ranked[i]);
    }

    // Step 1: Remove duplicates and store unique scores
    int unique[n], u = 0;
    unique[u++] = ranked[0];
    for (int i = 1; i < n; i++) {
        if (ranked[i] != ranked[i - 1]) {
            unique[u++] = ranked[i];
        }
    }

    int m;
    scanf("%d", &m);

    int player[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }

    // Step 2: Compute ranks for each player score
    int pos = u - 1;  // start from the lowest leaderboard score
    for (int i = 0; i < m; i++) {
        while (pos >= 0 && player[i] >= unique[pos]) {
            pos--; // move up leaderboard
        }
        printf("%d\n", pos + 2); // rank = index+2 because pos is one step behind
    }

    return 0;
}
