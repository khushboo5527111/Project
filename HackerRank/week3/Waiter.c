#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the nth prime number
int get_prime(int n) {
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    return primes[n - 1];
}

// waiter function
int* waiter(int numbers_count, int* numbers, int q, int* result_count) {
    int* A = (int*)malloc(numbers_count * sizeof(int));
    int A_top = -1;

    // Initially, A is the input numbers in reverse order (stack)
    for (int i = numbers_count - 1; i >= 0; i--) {
        A[++A_top] = numbers[i];
    }
    
    int** B = (int**)malloc(q * sizeof(int*));
    int* B_tops = (int*)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
        B[i] = (int*)malloc(numbers_count * sizeof(int));
        B_tops[i] = -1;
    }
    
    int* result = (int*)malloc(numbers_count * sizeof(int));
    int result_idx = 0;

    int current_A_count = numbers_count;
    
    for (int i = 1; i <= q; i++) {
        int prime = get_prime(i);
        int* next_A = (int*)malloc(numbers_count * sizeof(int));
        int next_A_top = -1;
        
        // Pop from A
        for (int j = 0; j < current_A_count; j++) {
            int plate = A[A_top--];
            if (plate % prime == 0) {
                // Stack it in B_i
                B[i - 1][++B_tops[i-1]] = plate;
            } else {
                // Stack it in the next A
                next_A[++next_A_top] = plate;
            }
        }
        
        // Copy next_A to A for the next iteration
        free(A);
        A = next_A;
        A_top = next_A_top;
        current_A_count = next_A_top + 1;
    }
    
    // Concatenate B_i stacks to the result array
    for (int i = 0; i < q; i++) {
        for (int j = B_tops[i]; j >= 0; j--) {
            result[result_idx++] = B[i][j];
        }
    }
    
    // Concatenate the remaining A stack to the result array
    for (int i = A_top; i >= 0; i--) {
        result[result_idx++] = A[i];
    }

    // Clean up allocated memory
    free(A);
    for (int i = 0; i < q; i++) {
        free(B[i]);
    }
    free(B);
    free(B_tops);

    *result_count = result_idx;
    return result;
}

// Main function for testing
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    int* numbers = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    int result_count;
    int* result = waiter(n, numbers, q, &result_count);
    
    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }
    
    free(numbers);
    free(result);
    
    return 0;
}
