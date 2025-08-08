#include <stdio.h>

void plusMinus(int array_size, int *array_value) {
 
    double positive_value = 0.0;
    double negative_value = 0.0;
    double zero_value = 0.0;

    for (int i = 0; i < array_size; i++) {
        if (array_value[i] > 0) {
            positive_value++;
        } else if (array_value[i] < 0) {
            negative_value++;
        } else {
            zero_value++;
        }
    }

    printf("%.6f\n", positive_value / array_size);
    printf("%.6f\n", negative_value / array_size);
    printf("%.6f\n", zero_value / array_size);
}

int main() {
    int n;
    scanf("%d", &n); 

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    plusMinus(n, array);

    return 0;
}
