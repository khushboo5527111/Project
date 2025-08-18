#include <stdio.h>
#include <stdlib.h>

// Dynamic array structure
typedef struct {
    int *arr;
    int size;
    int capacity;
} DynamicArray;

// Initialize a dynamic array
void init(DynamicArray *a) {
    a->size = 0;
    a->capacity = 2;
    a->arr = (int*)malloc(a->capacity * sizeof(int));
}

// Add element at the end
void push(DynamicArray *a, int val) {
    if (a->size == a->capacity) {
        a->capacity *= 2;
        a->arr = (int*)realloc(a->arr, a->capacity * sizeof(int));
    }
    a->arr[a->size++] = val;
}

// Free memory of array
void cleanup(DynamicArray *a) {
    free(a->arr);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Array of sequences
    DynamicArray seq[n];
    for (int i = 0; i < n; i++) {
        init(&seq[i]);
    }

    int lastAnswer = 0;

    while (q--) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            push(&seq[idx], y);
        } 
        else if (type == 2) {
            int pos = y % seq[idx].size;
            lastAnswer = seq[idx].arr[pos];
            printf("%d\n", lastAnswer);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        cleanup(&seq[i]);
    }

    return 0;
}
