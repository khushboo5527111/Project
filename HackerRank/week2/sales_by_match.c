#include <stdio.h>

int countSockPairs(int total, int socks[]) {
    int totalPairs = 0;
    int frequency[101] = {0}; 

    for (int i = 0; i < total; i++) {
        frequency[socks[i]]++;
    }

    for (int color = 0; color < 101; color++) {
        totalPairs += frequency[color] / 2;
    }

    return totalPairs;
}

int main() {
    int numSocks;
    scanf("%d", &numSocks);

    int sockArray[numSocks];

    for (int i = 0; i < numSocks; i++) {
        scanf("%d", &sockArray[i]);
    }

    int result = countSockPairs(numSocks, sockArray);
    printf("%d\n", result);

    return 0;
}
