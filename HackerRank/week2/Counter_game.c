#include <stdio.h>

int isPow2(unsigned long long x) {
    return (x && !(x & (x - 1)));
}

unsigned long long prevPow2(unsigned long long x) {
    unsigned long long p = 1;
    while ((p << 1) < x) p <<= 1;
    return p;
}

const char* play(unsigned long long n) {
    int moves = 0;
    while (n > 1) {
        if (isPow2(n)) 
            n >>= 1;      // divide by 2
        else 
            n -= prevPow2(n);
        moves++;
    }
    return (moves % 2) ? "Louise" : "Richard";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        printf("%s\n", play(n));
    }
    return 0;
}
