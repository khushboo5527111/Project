#include <stdio.h>

int equalStacks(int height1[], int num1, int height2[], int num2, int height3[], int num3) {
    long long s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < num1; i++) s1 += height1[i];
    for (int i = 0; i < num2; i++) s2 += height2[i];
    for (int i = 0; i < num3; i++) s3 += height3[i];

    int i = 0, j = 0, k = 0;

    while (1) {
        if (i == num1 || j == num2 || k == num3)
            return 0;

        if (s1 == s2 && s2 == s3)
            return (int)s1;

        if (s1 >= s2 && s1 >= s3) {
            s1 -= height1[i++];
        } else if (s2 >= s1 && s2 >= s3) {
            s2 -= height2[j++];
        } else {
            s3 -= height3[k++];
        }
    }
}

int main() {
    int num1, num2, num3;

    printf("Enter the number of cylinders in stacks 1, 2, and 3: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int height1[num1], height2[num2], height3[num3];

    printf("Enter the heights of stack 1 (top to bottom): ");
    for (int i = 0; i < num1; i++) scanf("%d", &height1[i]);

    printf("Enter the heights of stack 2 (top to bottom): ");
    for (int i = 0; i < num2; i++) scanf("%d", &height2[i]);

    printf("Enter the heights of stack 3 (top to bottom): ");
    for (int i = 0; i < num3; i++) scanf("%d", &height3[i]);

    int result = equalStacks(height1, num1, height2, num2, height3, num3);

    printf("\nThe maximum possible equal height of the three stacks is: %d\n", result);

    return 0;
}
