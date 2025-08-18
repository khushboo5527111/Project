#include <stdio.h>

int main() {
    int t; 
    scanf("%d", &t); // read and ignore test cases count

    int n;
    scanf("%d", &n); // number of elements

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // read array
    }

    // Step 1: Sort (bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Step 2: Middle index
    int mid = n / 2;

    // Step 3: Swap mid with last element
    int temp = arr[mid];
    arr[mid] = arr[n - 1];
    arr[n - 1] = temp;

    // Step 4: Reverse part after mid until n-2
    int st = mid + 1;
    int ed = n - 2;
    while (st <= ed) {
        temp = arr[st];
        arr[st] = arr[ed];
        arr[ed] = temp;
        st++;
        ed--;
    }

    // Step 5: Print result
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
