#include <stdio.h>
#include <string.h>

char* convertTo24HourFormat(const char* s) {
    static char result[9]; 
    int hour;
    char ampm[3];

    hour = (s[0] - '0') * 10 + (s[1] - '0');
    ampm[0] = s[8];
    ampm[1] = s[9];
    ampm[2] = '\0';

    if (strcmp(ampm, "AM") == 0) {
        if (hour == 12) hour = 0;
    } else {
        if (hour != 12) hour += 12;
    }

    snprintf(result, sizeof(result), "%02d:%c%c:%c%c", 
             hour, s[3], s[4], s[6], s[7]);

    return result;
}

int main() {
    char s[11];  
    scanf("%s", s);

    printf("%s\n", convertTo24HourFormat(s));
    return 0;
}
