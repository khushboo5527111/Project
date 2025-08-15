#include <stdio.h>

// Function to calculate the number of x values satisfying n + x = n ^ x
long countValidX(long num) {
    if (num == 0) return 1;

    int zeroCount = 0;
    long copy = num;

    while (copy > 0) {
        if ((copy & 1) == 0) {
            zeroCount++;
        }
        copy >>= 1; // Move to next bit
    }

    return 1L << zeroCount;
}

int main() {
    long n;
    scanf("%ld", &n);

    printf("%ld\n", countValidX(n));
    return 0;
}
