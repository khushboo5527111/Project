#include <stdio.h>

int getSingleValue(int totalCount, int *arr) {
    int tempValue = 0;
    int index = 0;
    while (index < totalCount) {
        tempValue = tempValue ^ arr[index]; 
        index++;
    }
    return tempValue;
}

int main() {
    int size;
    scanf("%d", &size);

    int elements[size];
    for (int k = 0; k < size; ++k) {
        scanf("%d", &elements[k]);
    }

    int answer = getSingleValue(size, elements);
    printf("%d\n", answer);

    return 0;
}
