#include <stdio.h>
#include <string.h>

void xorStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minLen = len1 < len2 ? len1 : len2;

    for (int idx = 0; idx < minLen; idx++) {
        if (str1[idx] == str2[idx])
            printf("0");
        else
            printf("1");
    }
    printf("\n");
}

int main() {
    char input1[1001], input2[1001];
    scanf("%s", input1);
    scanf("%s", input2);

    xorStrings(input1, input2);
    return 0;
}
