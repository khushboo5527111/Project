#include <stdio.h>

void countBribes(int queue[], int size) {
    int totalBribes = 0;

    for (int i = 0; i < size; i++) {
        // Check if someone moved more than 2 positions ahead
        if (queue[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }

        // Only check from max(queue[i] - 2, 0) up to i-1
        int start = queue[i] - 2;
        if (start < 0) {
            start = 0;
        }

        for (int j = start; j < i; j++) {
            if (queue[j] > queue[i]) {
                totalBribes++;
            }
        }
    }

    printf("%d\n", totalBribes);
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        countBribes(arr, n);
    }

    return 0;
}
