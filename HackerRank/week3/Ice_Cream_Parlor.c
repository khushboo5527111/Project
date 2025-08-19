int* icecreamParlor(int m, int arr_count, int* arr, int* result_count) {
    // We always return 2 indices
    *result_count = 2;
    int* result = malloc(2 * sizeof(int));

    // Brute force search (O(n^2)), fine for small constraints
    for (int i = 0; i < arr_count; i++) {
        for (int j = i + 1; j < arr_count; j++) {
            if (arr[i] + arr[j] == m) {
                result[0] = i + 1;  // +1 for 1-based indexing
                result[1] = j + 1;
                return result;
            }
        }
    }
    return result; // Should never reach here (always one solution guaranteed)
}
