#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_COUNT 26

const char* checkPangram(const char* text) {
    int foundLetters[ALPHABET_COUNT] = {0};
    int uniqueCount = 0;

    for (int pos = 0; text[pos] != '\0'; pos++) {
        if (isalpha(text[pos])) {
            int letterIndex = tolower(text[pos]) - 'a';
            if (foundLetters[letterIndex] == 0) {
                foundLetters[letterIndex] = 1;
                uniqueCount++;
                if (uniqueCount == ALPHABET_COUNT) {
                    return "pangram";
                }
            }
        }
    }
    return "not pangram";
}

int main() {
    char sentence[1001];
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = 0;

    printf("%s\n", checkPangram(sentence));
    return 0;
}
