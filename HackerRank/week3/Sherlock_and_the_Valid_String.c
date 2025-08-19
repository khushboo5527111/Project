#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

const char* isValid(const char* s) {
    int freq[MAX_CHAR] = {0};
    int len = strlen(s);

    // Step 1: Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find min and max frequencies
    int min = 1e9, max = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            if (freq[i] < min) min = freq[i];
            if (freq[i] > max) max = freq[i];
        }
    }

    // Step 3: Check valid cases
    int minCount = 0, maxCount = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] == min) minCount++;
        else if (freq[i] == max) maxCount++;
    }

    // Case 1: All same frequency
    if (min == max) return "YES";

    // Case 2: Remove one char with freq=1
    if (min == 1 && minCount == 1 && maxCount * max == (len - 1)) return "YES";

    // Case 3: One char with freq higher by 1
    if (max - min == 1 && maxCount == 1) return "YES";

    return "NO";
}

int main() {
    char s[100005];
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}
