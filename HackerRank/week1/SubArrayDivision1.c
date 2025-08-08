#include <stdio.h>

int birthday(int totalElements, int* chocolateBar, int targetSum, int segmentLength) {
    int matchingSegments = 0;
    for (int startIndex = 0; startIndex <= totalElements - segmentLength; startIndex++) {
        int segmentSum = 0;
        for (int offset = 0; offset < segmentLength; offset++) {
            segmentSum += chocolateBar[startIndex + offset];
        }
        if (segmentSum == targetSum) {
            matchingSegments++;
        }
    }
    return matchingSegments;
}

int main() {
    int totalElements;
    scanf("%d", &totalElements);

    int chocolateBar[totalElements];
    for (int startIndex = 0; startIndex < totalElements; startIndex++) {
        scanf("%d", &chocolateBar[startIndex]);
    }

    int targetSum, segmentLength;
    scanf("%d %d", &targetSum, &segmentLength);

    int result = birthday(totalElements, chocolateBar, targetSum, segmentLength);
    printf("%d\n", result);

    return 0;
}
