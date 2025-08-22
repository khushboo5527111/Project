#include <stdio.h>
#include <stdlib.h>

void countingSort(int Arr[], int len, int freq[]) {
    for (int n = 0; n < 100; n++) {
        freq[n] = 0;
    }
    for (int n = 0; n < len; n++) {
        freq[Arr[n]]++;
    }
}

int main() {
    int size;
    printf("Enter  Size of elements:\n");
    scanf("%d", &size);

    int *vals = (int *)malloc(size * sizeof(int));
    if(vals == NULL){
     printf("Memory allocation failed!\n");
         return 1;
    }
         
    int freq[100];

    printf("Enter %d integers (each between 0 and 99):\n",size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &vals[i]);
    }

    countingSort(vals, size, freq);

    printf("\nFrequency of numbers (0-99):\n");
    for (int i = 0; i < 100; i++) {
        printf("%2d -> %d\n",i,freq[i]);
    }

    free(vals);
    return 0;
}
