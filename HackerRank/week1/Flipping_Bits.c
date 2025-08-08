#include <stdio.h>

unsigned long flipBits(unsigned long num1) {
    unsigned long mask = 0xFFFFFFFF; 
    return num1 ^ mask;               
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int idx = 0; idx < testCases; idx++) {
        unsigned long value;
        scanf("%lu", &value);  // Read input as unsigned long

        unsigned long flipped = flipBits(value);
        printf("%lu\n", flipped);
    }

    return 0;
}
