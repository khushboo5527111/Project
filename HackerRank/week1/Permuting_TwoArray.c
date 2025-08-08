#include <stdio.h>
#include <stdlib.h>

int cmpAsc(const void* x, const void* y) {
    return (*(int*)x - *(int*)y);
}

int cmpDesc(const void* x, const void* y) {
    return (*(int*)y - *(int*)x);
}

const char* canPermuteArrays(int target, int length, int arr1[], int arr2[]) {
    qsort(arr1, length, sizeof(int), cmpAsc);
    qsort(arr2, length, sizeof(int), cmpDesc);

    for (int i = 0; i < length; i++) {
        if (arr1[i] + arr2[i] < target) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int size, targetSum;
        scanf("%d %d", &size, &targetSum);

        int firstArray[size];
        int secondArray[size];

        for (int i = 0; i < size; i++) {
            scanf("%d", &firstArray[i]);
        }
        for (int i = 0; i < size; i++) {
            scanf("%d", &secondArray[i]);
        }

        printf("%s\n", canPermuteArrays(targetSum, size, firstArray, secondArray));
    }

    return 0;
}
