#include <stdio.h>

int maxSubarraySum(int Arr[], int size) {
    int currentSum = Arr[0];
    int bestSum = Arr[0];

    for (int i = 1; i < size; i++) {
        if (Arr[i] > currentSum + Arr[i]) {
            currentSum = Arr[i];
        } else {
            currentSum = currentSum + Arr[i];
        }

        if (currentSum > bestSum) {
            bestSum = currentSum;
        }
    }
    return bestSum;
}

int maxSubsequenceSum(int Arr[], int size) {
    int maxVal = Arr[0];
    int sum = 0;
    int foundPositive = 0;

    for (int i = 0; i < size; i++) {
        if (Arr[i] > 0) {
            sum += Arr[i];
            foundPositive = 1;
        }
        if (Arr[i] > maxVal) {
            maxVal = Arr[i];
        }
    }

    if (foundPositive)
        return sum;
    else
        return maxVal;
}

int main() {
    int test_case;
    printf("Enter number of test cases: ");
    scanf("%d", &test_case);

    for (int t = 1; t <= test_case; t++) {
        int size;
        printf("\nTest Case %d\n", t);
        printf("Enter size of array: ");
        scanf("%d", &size);

        int Arr[size];
        printf("Enter %d integers (positive/negative):\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &Arr[i]);
        }

        int subarray = maxSubarraySum(Arr, size);
        int subsequence = maxSubsequenceSum(Arr, size);

        printf("\nResults for Test Case %d:\n", t);
        printf("Maximum Subarray Sum    = %d\n", subarray);
        printf("Maximum Subsequence Sum = %d\n", subsequence);
    }

    return 0;
}
