#include <stdio.h>
#include <string.h>

// Get digit sum from string
long long strSum(const char *s) {
    long long sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        sum += s[i] - '0';
    }
    return sum;
}

// Recursive super digit
long long superDigit(long long n) {
    if (n < 10) return n;
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return superDigit(sum);
}

int main() {
    char num[100005];
    int k;

    scanf("%s %d", num, &k);

    long long initSum = strSum(num) * k;

    printf("%lld\n", superDigit(initSum));
    return 0;
}
