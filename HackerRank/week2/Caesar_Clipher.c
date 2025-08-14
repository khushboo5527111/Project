#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Function to encrypt a string using Caesar Cipher
void encryptCaesar(char *text, int shift) {
    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        char ch = text[i];

        if (islower(ch)) {
            text[i] = 'a' + (ch - 'a' + shift) % 26;
        } else if (isupper(ch)) {
            text[i] = 'A' + (ch - 'A' + shift) % 26;
        }
    }
}

int main() {
    int strLength, shiftAmount;
    scanf("%d", &strLength);

    char inputString[101];
    scanf("%s", inputString);

    scanf("%d", &shiftAmount);

    encryptCaesar(inputString, shiftAmount);

    printf("%s\n", inputString);

    return 0;
}
