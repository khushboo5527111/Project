#include <stdio.h>
#include <limits.h>  

void miniMaxSum(int array_size, int* array_value) {
    long total = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < array_size; i++) {
        total += array_value[i];
        if (array_value[i] < min) min = array_value[i];
        if (array_value[i] > max) max = array_value[i];
    }

    long min_sum = total - max; 
    long max_sum = total - min; 

    printf("%ld %ld\n", min_sum, max_sum);
}

int main() {
    int array_value[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d", &array_value[i]);
    }

    miniMaxSum(5, array_value);

    return 0;
}
