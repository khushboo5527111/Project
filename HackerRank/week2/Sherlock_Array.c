#include <stdio.h>

// Function to check if a balanced index exists
const char* balancedSums(int n, int arr[]) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];   // get total sum
    }

    long long left = 0;
    for (int i = 0; i < n; i++) {
        long long right = total - left - arr[i];  // remaining sum
        if (left == right) {
            return "YES";  // found balance
        }
        left += arr[i];  // move to next index
    }

    return "NO";  // no balance found
}

int main() {
    int t;
    scanf("%d", &t);   // number of test cases

    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];    // use simple fixed array (no malloc)

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("%s\n", balancedSums(n, arr));
    }

    return 0;
}
