#include <stdio.h>

void countingSort(int inputArray[], int length, int frequency[]) {
    for (int index = 0; index < 100; index++) {
        frequency[index] = 0;
    }
    for (int idx = 0; idx < length; idx++) {
        frequency[inputArray[idx]]++;
    }
}

int main() {
    int size;
    scanf("%d", &size);
    
    int values[size];
    int frequency[100];

    for (int i = 0; i < size; i++) {
        scanf("%d", &values[i]);
    }

    countingSort(values, size, frequency);

    for (int i = 0; i < 100; i++) {
        printf("%d", frequency[i]);
        if (i != 99) printf(" ");
    }

    return 0;
}
