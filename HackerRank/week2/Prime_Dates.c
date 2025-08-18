#include <stdio.h>

int isLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    return (year % 4 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) return isLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int isLucky(int d, int m, int y) {
    long long num = d * 1000000LL + m * 10000LL + y;
    return (num % 4 == 0 || num % 7 == 0);
}

int countLuckyDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    int count = 0;

    while (1) {
        if (isLucky(d1, m1, y1)) count++;
        if (d1 == d2 && m1 == m2 && y1 == y2) break;

        d1++;
        if (d1 > daysInMonth(m1, y1)) {
            d1 = 1;
            m1++;
            if (m1 > 12) {
                m1 = 1;
                y1++;
            }
        }
    }
    return count;
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    scanf("%d-%d-%d %d-%d-%d", &d1, &m1, &y1, &d2, &m2, &y2);
    printf("%d\n", countLuckyDates(d1, m1, y1, d2, m2, y2));
    return 0;
}
