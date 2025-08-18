#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // sort the array
    qsort(a, n, sizeof(int), cmp);

    int minDiff = a[n - 1] - a[0];  // start with max difference

    // check every group of k numbers
    for (int i = 0; i <= n - k; i++) {
        int diff = a[i + k - 1] - a[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    printf("%d\n", minDiff);
    return 0;
}
